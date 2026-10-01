class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long ans = 0;
        int i = 0;

        // 1. Skip whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // 2. Handle sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // 3. Convert digits
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // 4. Check overflow BEFORE multiplication
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 &&
                 digit > (sign == 1 ? 7 : 8))) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        // 5. Apply sign
        return ans * sign;
    }
};