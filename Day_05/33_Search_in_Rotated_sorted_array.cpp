class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0 , hi=nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target)
                return mid;

            else if(nums[lo] <= nums[mid]){ //left half sorted
                if(target >= nums[lo] && target <= nums[mid]){
                    //remove the right half
                    hi = mid -1;
                }
                else
                    lo = mid + 1; 
            }

            else{ // right half sorted
                if(target >= nums[mid] && target <= nums[hi]){
                    //remove the left half
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }  
        }
        return -1;
    }
};