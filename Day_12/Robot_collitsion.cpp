#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>

class Solution {
public:
    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
        int n = positions.size();
        std::vector<std::tuple<int, int, char, int>> robots;
        
        // Combine positions, healths, and directions into one vector of tuples along with original indices for sorting
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        // Sort robots by positions
        std::sort(robots.begin(), robots.end());
        
        std::stack<std::tuple<int, int, char, int>> stk;  // Stack to hold robots moving to the right
        
        for (const auto& robot : robots) {
            int position = std::get<0>(robot);
            int health = std::get<1>(robot);
            char direction = std::get<2>(robot);
            int index = std::get<3>(robot);
            
            if (direction == 'R') {
                // Push the robot moving to the right onto the stack
                stk.push(robot);
            } else {
                // Handle collision with robots moving to the right
                while (!stk.empty() && std::get<2>(stk.top()) == 'R') {
                    auto [r_pos, r_health, r_dir, r_index] = stk.top();
                    
                    if (r_health < health) {
                        // Right robot is destroyed
                        stk.pop();
                        --health;
                    } else if (r_health > health) {
                        // Left robot is destroyed
                        --std::get<1>(stk.top());
                        health = 0;
                        break;
                    } else {
                        // Both robots are destroyed
                        stk.pop();
                        health = 0;
                        break;
                    }
                }
                
                if (health > 0) {
                    stk.push({position, health, direction, index});
                }
            }
        }
        
        // Collect surviving robots in their original order
        std::vector<int> result(n, -1);
        while (!stk.empty()) {
            auto [pos, health, dir, index] = stk.top();
            stk.pop();
            result[index] = health;
        }
        
        // Filter out non-survivors
        std::vector<int> survivors;
        for (int health : result) {
            if (health != -1) {
                survivors.push_back(health);
            }
        }
        
        return survivors;
    }
};
