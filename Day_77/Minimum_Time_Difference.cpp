class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> minutes(n);
        for(int i=0; i<n; i++){
            string time = timePoints[i];

            string hourSubstr = time.substr(0,2); //hr
            string minSubstr = time.substr(3); //min

            int hourInt = stoi(hourSubstr);
            int minInt = stoi(minSubstr);

            minutes[i] = hourInt*60 + minInt;
        }
        sort(minutes.begin(),minutes.end());
        int res = INT_MAX;
        for(int i=1; i<n; i++){
            res = min(res, minutes[i] - minutes[i-1]);
        }
        return min(res, (24*60 - minutes[n-1]) + minutes[0]);
    }
};