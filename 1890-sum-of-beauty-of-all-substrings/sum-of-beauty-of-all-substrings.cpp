class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0; // Stores total beauty of all substrings

        // Choose starting point of substring
        for (int i = 0; i < n; i++) {
            // Frequency of 26 lowercase letters
            vector<int> freq(26, 0);

            // Choose ending point of substring
            for (int j = i; j < n; j++) {
                // Increase frequency of current character
                freq[s[j] - 'a']++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                // Find minimum and maximum frequency
                // among characters present in substring
                for (auto it : freq) {
                    // Ignore characters whose frequency is 0
                    if (it > 0) {
                        mini = min(mini, it);
                        maxi = max(maxi, it);
                    }
                }

                // Beauty = maximum frequency - minimum frequency
                int bty = maxi - mini;

                // Add beauty of current substring to total sum
                sum += bty;
            }
        }

        return sum;
    }
};