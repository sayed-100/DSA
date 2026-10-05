class Solution {
private:
    long long pow(long long a, long long b)
    {
        const long long MOD = 1e9 + 7; // 1,000,000,007
        long long ans = 1;
        while(b != 0)
        {
            if(b % 2 == 1)
            {
                ans = (ans * a) % MOD;
                b = b - 1;
            }
            else
            {
                a = (a * a) % MOD;
                b = b / 2;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {

        const long long MOD = 1e9 + 7; // 1,000,000,007
        long long num_of_evenIndices = (n + 1) /2;
        long long num_of_oddIndices = (n / 2);
        return (pow(5, num_of_evenIndices) * pow(4, num_of_oddIndices)) % MOD;
        
    }
};