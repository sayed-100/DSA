class Solution {
private:
    bool isPalindromeSolve(const string& s, int i, int j)
    {
        if(i >= j)
            return true;

        if(s[i] == s[j])
            return isPalindromeSolve(s, i + 1, j - 1);

        return false;
    }

public:
    string longestPalindrome(string s)
    {
        int maxLen = 0;
        int startPoint = 0;
        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int lengthOfString = j - i + 1;

                if(isPalindromeSolve(s, i, j))
                {
                    if(lengthOfString > maxLen)
                    {
                        maxLen = lengthOfString;
                        startPoint = i;
                    }
                }
            }
        }

        return s.substr(startPoint, maxLen);
    }
};