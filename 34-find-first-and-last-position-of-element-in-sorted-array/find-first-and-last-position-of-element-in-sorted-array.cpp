class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         // First occurrence
        int first = lower_bound(nums.begin(), nums.end(), target)
                    - nums.begin();

        // Target doesn't exist
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        // Last occurrence
        int last = upper_bound(nums.begin(), nums.end(), target)
                   - nums.begin() - 1;

        return {first, last};
    }
};