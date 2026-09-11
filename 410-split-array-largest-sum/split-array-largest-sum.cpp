class Solution {
private:
    int num_of_subArray(vector<int>& nums, int limit_num)
    {
        int cnt_of_subArray = 1;
        int sum_elem = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(sum_elem + nums[i] <= limit_num)
            {
                sum_elem += nums[i];
            }
            else
            {
                cnt_of_subArray++;
                sum_elem = nums[i];
            }
        }
        return cnt_of_subArray;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        // if(k == 1) return accumulate(nums.begin(), nums.end(), 0);
        while(low  <= high)
        {
            int mid = low + (high - low) / 2;
            int cnt_subArray = num_of_subArray(nums, mid);
            if(cnt_subArray > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};