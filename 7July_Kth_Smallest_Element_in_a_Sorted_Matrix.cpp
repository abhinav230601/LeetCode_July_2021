class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> res(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[i*n + j] = matrix[i][j];
            }
        }
        sort(res.begin(), res.end());
        return res[k-1];
        
    }
};
