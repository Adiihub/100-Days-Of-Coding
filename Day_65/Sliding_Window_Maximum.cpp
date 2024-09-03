#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        vector<int> ans;
        deque<int> q;  // deque indices store krega

        while (j < n) {
            // jo vi element nums[j] se chota hoga use pop krenge
            while (!q.empty() && nums[q.back()] < nums[j]) {
                q.pop_back();
            }

            // current element's index ko deque me push krenge
            q.push_back(j);

            if (j - i + 1 == k) {
                
                ans.push_back(nums[q.front()]);

                // Remove the element which is out of this window
                if (q.front() == i) {
                    q.pop_front();
                }

                i++;
            }
            j++;
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6};
    int k = 3;
    vector<int> ans = s.maxSlidingWindow(nums, k);
    for(auto it: ans) cout<<it<<" ";
    

    return 0;
}