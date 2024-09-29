
class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;  // Stores keys with the same count
        Node(int c) : count(c) {}
    };
    
    list<Node> nodes; 
    unordered_map<string, int> key_count_map; current count
    unordered_map<int, list<Node>::iterator> count_node_map;  
public:
    AllOne() {}
    
    void inc(string key) {
        int count = key_count_map[key]++;
        
        // If this is the first time the key is added (count == 0)
        if (count == 0) {
            // Create or find the node for count = 1
            if (nodes.empty() || nodes.front().count != 1) {
                nodes.push_front(Node(1));
                count_node_map[1] = nodes.begin();
            }
            count_node_map[1]->keys.insert(key);
            return;
        }

        // Find the current node for the current count
        auto cur_node = count_node_map[count];
        
        // Create a new node for count + 1 if necessary
        if (next(cur_node) == nodes.end() || next(cur_node)->count != count + 1) {
            auto new_node = nodes.insert(next(cur_node), Node(count + 1));
            count_node_map[count + 1] = new_node;
        }
        
        // Move the key to the new node
        next(cur_node)->keys.insert(key);
        cur_node->keys.erase(key);
        
        // If the current node becomes empty, remove it
        if (cur_node->keys.empty()) {
            count_node_map.erase(count);
            nodes.erase(cur_node);
        }
    }
    
    // Decrement the count of the key
    void dec(string key) {
        int count = key_count_map[key]--;
        auto cur_node = count_node_map[count];
        
        if (count == 1) {
            key_count_map.erase(key);  // Remove the key if the count reaches 0
        } else {
            // Create a new node for count - 1 if necessary
            if (cur_node == nodes.begin() || prev(cur_node)->count != count - 1) {
                auto new_node = nodes.insert(cur_node, Node(count - 1));
                count_node_map[count - 1] = new_node;
            }
            prev(cur_node)->keys.insert(key);
        }
        
        // Remove the key from the current node
        cur_node->keys.erase(key);
        if (cur_node->keys.empty()) {
            count_node_map.erase(count);
            nodes.erase(cur_node);
        }
    }
    
    // Get the key with the maximum count
    string getMaxKey() {
        if (nodes.empty()) return "";
        return *(nodes.back().keys.begin());  // Max count is at the end of the list
    }
    
    // Get the key with the minimum count
    string getMinKey() {
        if (nodes.empty()) return "";
        return *(nodes.front().keys.begin());  // Min count is at the front of the list
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
