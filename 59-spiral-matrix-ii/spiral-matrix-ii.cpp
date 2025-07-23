class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int k=1;
        vector<vector <int>> res(n,vector<int>(n));
        int top=0, bottom=n-1, left=0, right=n-1;
        while(top<=bottom && left<=right){
            for(int i=left; i<=right;i++){
                res[top][i]=k++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res[i][right]=k++;
            }
            right--;
            if(top<=bottom){
                for(int i=right; i>=left;i--){
                res[bottom][i]=k++;
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom; i>=top;i--){
                res[i][left]=k++;
            }
            left++;
            }
        }
        return res;
    }
};