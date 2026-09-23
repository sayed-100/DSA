class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int rowIndex = 0;

        for (int i = 0; i < mat.size(); i++) {
            int ones = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                ones += mat[i][j];
            }

            if (ones > maxOnes) {
                maxOnes = ones;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};