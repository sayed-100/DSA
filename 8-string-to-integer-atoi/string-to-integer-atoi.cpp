class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long ans = 0;
        int i = 0;
        // Whitespace
        while(i < s.length() && s[i] == ' ')
        {
            i++;
        }
        // signedness
        if(i < s.length() && (s[i] == '+' || s[i] == '-') )
        {   if ( s[i] == '-' )
            {
                sign = -1;
            }
            i++;
        }
        while( i < s.length() && ( s[i] >= '0' && s[i] <= '9') )
        {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if(ans * sign > INT_MAX )
            return INT_MAX;
            else if(ans * sign < INT_MIN)
            return INT_MIN;
            i++;
        }
        return ans * sign;

    }
};