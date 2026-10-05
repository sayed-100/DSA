class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << n); i++) // i << n same as 2^n
        {
            vector<int> numsSub;
            for(int j = 0; j < n; j++)
            {
                if((i & (1 << j)) != 0)
                {
                    numsSub.push_back(nums[j]);
                }
            }
            ans.push_back(numsSub);
        }
        return ans;
    }
};