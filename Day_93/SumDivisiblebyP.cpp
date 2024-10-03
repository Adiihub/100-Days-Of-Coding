#include <unordered_map>
#include <vector>
#include <numeric> // For accumulate

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        // Calculate total sum of the array
        long long totalSum = std::accumulate(nums.begin(), nums.end(), 0LL);
        int targetMod = totalSum % p;
        
        // If the total sum is already divisible by p, no subarray needs to be removed
        if (targetMod == 0) return 0;

        // Use a hash map to store prefix sum modulo values and their indices
        std::unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1;  
        int n = nums.size();
        long long prefixSum = 0;
        int minLength = n;

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            
            int neededMod = (prefixSum - targetMod + p) % p;

            if (prefixModMap.find(neededMod) != prefixModMap.end()) {
                minLength = std::min(minLength, i - prefixModMap[neededMod]);
            }

            prefixModMap[prefixSum] = i;
        }

        return minLength == n ? -1 : minLength;
    }
};
