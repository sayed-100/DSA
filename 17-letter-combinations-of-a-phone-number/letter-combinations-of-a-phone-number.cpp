class Solution {
private:
    void solve(int idx, string &digits, string &ds, 
    unordered_map <char, string> &mp, vector<string> &ans )
    {
        if(idx >= digits.length())
        {
            ans.push_back(ds);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i = 0; i < str.length(); i++)
        {
            //do something
            ds.push_back(str[i]);
            //explore
            solve(idx + 1, digits, ds, mp, ans);
            // undo
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        string ds = "";
        solve(0, digits, ds, mp, ans);
        return ans;
    }
};