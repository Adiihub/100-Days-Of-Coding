#include<bits/stdc++.h>
using namespace std;
#include<stack>

class Solution {
public:
    vector<int> NGR(vector<int>&temperatures,int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(n-1);
    ans[n-1] = -1;
    for(int i=n-2;i>=0;i--){
    while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
        s.pop();
    }
    ans[i] = s.empty()?-1:s.top();
    s.push(i);
    }
    return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>index = NGR(temperatures,n);
        vector<int>result(n);
        for(int i=0;i<n;i++){
          if(index[i]==-1){
            result[i]=0;
          }else{
            result[i]=index[i]-i;
          }
      }
      return result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>temperatures(n);
    for(int i=0;i<n;i++){
        cin>>temperatures[i];
        }
        Solution s;
        vector<int>result = s.dailyTemperatures(temperatures);
        
        return 0;
}