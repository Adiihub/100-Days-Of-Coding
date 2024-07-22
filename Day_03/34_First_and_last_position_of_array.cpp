class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);

        int n = nums.size();
        if(n==0) 
        return ans;

        // checking for first position
       
        int fi=0, last = n-1;
        while(fi<=last){
            int mid = fi + (last - fi) / 2;  // Avoid overflow
            if(nums[mid]==target){
                if(mid == 0 || nums[mid-1] != target){
                    ans[0] = mid;
                    break;
                }
                else{
                    last = mid-1;
                }
            }
            else if(nums[mid]<target){
                fi = mid +1;
            }
            else{
                last = mid -1;
            }
        }

        // checking for last position
       
        fi=0, last = n-1;
        while(fi<=last){
            int mid = fi + (last - fi) / 2;  // Avoid overflow
            if(nums[mid]==target){
                if(mid == n-1 || nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                }
                else{
                    fi = mid+1;   
                }
            }
            else if(nums[mid]<target){
                fi = mid +1;
            }
            else{
                last = mid -1;
            }
        }
        return ans;
    }
};