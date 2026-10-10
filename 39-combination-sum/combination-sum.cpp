class Solution {
private:
    void findCombination(int index, int target,vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        //Base Case
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        if(index == arr.size())
        {
            return;
        }
        //pick
        if(arr[index] <= target)
        {
            ds.push_back(arr[index]);
            findCombination(index, target - arr[index], arr, ans, ds);
            //undo
            ds.pop_back();
        }
        //not pick
        findCombination(index + 1, target, arr, ans, ds);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target, candidates, ans, ds);
        return ans;
    }
};