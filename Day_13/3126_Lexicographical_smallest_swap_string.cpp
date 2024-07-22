#include<iostream>
using namespace std;


class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i = 0; i < n - 1; i++) {
            if((s[i] %2 == s[i+1]%2) && s[i]>s[i+1]){
                swap(s[i], s[i+1]);
                break;
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    string s = "45320";
    cout<<s.getSmallestString(s);


    return 0;
}