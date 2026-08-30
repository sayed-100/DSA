class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        //First occurence;
        int first = -1;
        while ( low <= high )
        {
            int mid = low  + ( ( high - low ) / 2 );
            if( nums[mid] >= target )
            {
                if( nums[mid] == target)
                {
                    first = mid;
                }

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
       //(last occurence) Upper Bound for finding num just greater then target
        low = 0,
        high = nums.size() - 1;
        int last = -1;
        while ( low <= high )
        {
            int mid = low  + ( ( high - low ) / 2 );
            if( nums[mid] <= target )
            {
                if( nums[mid] == target)
                {
                    last = mid;
                }
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return {first,last};
    }
};