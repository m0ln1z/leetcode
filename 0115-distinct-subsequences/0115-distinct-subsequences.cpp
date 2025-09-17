class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    __int128 tmp = (__int128)dp[j] + dp[j - 1];
                    dp[j] = (long long)tmp;
                }
            }
        }
        return (int)dp[n];
    }
};
