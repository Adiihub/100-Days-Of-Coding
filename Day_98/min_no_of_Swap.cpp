class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '['){
                st.push(it);
            }
            else if(!st.empty()){
                st.pop(); //balancing closing bracket with open bracket
            }
        }

        return (st.size()+1)/2;
        
    }
};