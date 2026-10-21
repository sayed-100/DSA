class Solution {
private:
    void help(int i, int k, int sumTillNow, int n, vector<int> &ds, vector<vector<int>> &ans)
    {
        //base
        if(k == 0)
        {
            if(sumTillNow == n)
            {
                ans.push_back(ds);
                // return;
            }
            return; 
        }
        if(i == 10 || sumTillNow > n) return;
        ds.push_back(i);
        help(i+1, k - 1, sumTillNow + i, n, ds, ans);
        //undo 
        ds.pop_back();
        help(i+1, k, sumTillNow, n, ds, ans);


    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> ans;
      vector<int> ds;
      help(1, k, 0, n, ds, ans); 
      return ans; 
    }
};