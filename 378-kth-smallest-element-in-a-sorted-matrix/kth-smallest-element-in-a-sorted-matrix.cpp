class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //Method 1
        int n = matrix.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
    // But traversing on whole matrix, means t.c. is something something n^2.  O(n^2logk);
};