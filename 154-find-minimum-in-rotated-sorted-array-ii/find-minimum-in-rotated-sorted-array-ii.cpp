class Solution {
public:
    int findMin(vector<int>& nums) {
        int low  = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid  = low + ( high - low ) / 2;
           
            //duplicate present in array at low, mid and high then shrink
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }
            //left sorted
            if(nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // right sorted
            else
            {
                ans = min( ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};