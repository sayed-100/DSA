class Solution {
public:
    int findMin(vector<int>& nums) {
        int low  = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            // 1. If strictly sorted, the first element is the minimum of this range
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }
            int mid  = low + ( high - low ) / 2;
           
            //duplicate present in array at low, mid and high then shrink
            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }
            // 3. Two-way duplicates at left boundary: safely skip one element
            if (nums[low] == nums[mid]) {
                ans = min(ans, nums[low]);
                low++;
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