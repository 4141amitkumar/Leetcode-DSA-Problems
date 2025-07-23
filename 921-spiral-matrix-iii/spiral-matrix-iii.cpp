class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int total=rows*cols;
        int k=0;
        int x = 1;

        while (k<total) {
            for (int i=0; i<x; i++) {
                if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                    res.push_back({rStart, cStart});
                    k++;
                }
                cStart++;
            }
            for (int i=0; i<x;i++) {
                if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                    res.push_back({rStart, cStart});
                    k++;
                }
                rStart++;
            }
            x++; 
            for (int i=0; i<x; i++) {
                if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                    res.push_back({rStart, cStart});
                    k++;
                }
                cStart--;
            }
            for (int i=0; i<x; i++) {
                if (rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) {
                    res.push_back({rStart, cStart});
                    k++;
                }
                rStart--;
            }
            x++;
        }
        return res;
    }
};