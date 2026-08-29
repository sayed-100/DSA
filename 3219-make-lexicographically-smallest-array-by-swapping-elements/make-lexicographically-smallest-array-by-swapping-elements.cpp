class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
            v[i] = {nums[i], i};

        sort(v.begin(), v.end());

        for (int l = 0; l < n;) {
            int r = l;

            while (r + 1 < n && v[r + 1].first - v[r].first <= limit) {
                r++;
            }

            vector<int> idx;
            idx.reserve(r - l + 1);

            for (int i = l; i <= r; i++)
                idx.push_back(v[i].second);

            sort(idx.begin(), idx.end());

            for (int i = l; i <= r; i++)
                nums[idx[i - l]] = v[i].first;

            l = r + 1;
        }

        return nums;
    }

};