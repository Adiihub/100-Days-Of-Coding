class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0;
        stack<int> st;
        for(auto it: s){
            if(it== '('){
                st.push(it);
            }
            else if(!st.empty() && it == ')'){
                size+=2;
                st.pop();
            }
        }
        return s.size()-size;
    }
};