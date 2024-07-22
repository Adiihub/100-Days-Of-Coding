class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int a ,p=0;
        vector<int> arr;
        for(int i=0;i<n;i++){
            a = matrix[i][0];
            for(int j=0;j<m;j++){
                if(a>matrix[i][j]){
                a=matrix[i][j];
                p=j;
                }
            }
            bool islucky = true;
            for(int k=0;k<n;k++){
                if(a<matrix[k][p]){
                islucky = false;
                break;
                }
            }
            if(islucky){
            arr.push_back(a);
            }
        }
        return arr;
    }
};