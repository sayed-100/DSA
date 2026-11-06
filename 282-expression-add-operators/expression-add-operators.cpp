class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        string path ="";
        helper(num, target, 0, path, 0, 0);
        return ans;
    }
    void helper(string s, int target, int i, string path, long eval, long prev)
    {
        if(i == s.size())
        {
            if(eval == target)
            {
                ans.push_back(path);
            }
            return;
        }
        for(int j = i; j < s.size(); j++)
        {
            //handel '0' 
            if(j > i && s[i] == '0') return;
            string currStr = s.substr(i, j-i+1);
            long number = stol(currStr);
            if(i == 0)
            {
                helper(s, target, j + 1, path + currStr, number, number);
            }
            else
            {
                helper(s, target, j + 1, path + "+" + currStr, eval+number, number);
                helper(s, target, j + 1, path + "-" + currStr, eval-number, -number);
                helper(s, target, j + 1, path + "*" + currStr, eval-prev + prev*number, prev*number);
            }
        }
    }
};