class Solution {
public:
    bool isValid(string s) {
        int top = 0;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                s[top++] = c;
            }
            else {
                if (top == 0)
                    return false;

                char open = s[top - 1];

                if ((c == ')' && open != '(') ||
                    (c == '}' && open != '{') ||
                    (c == ']' && open != '[')) {
                    return false;
                }

                top--;
            }
        }

        return top == 0;
    }
};