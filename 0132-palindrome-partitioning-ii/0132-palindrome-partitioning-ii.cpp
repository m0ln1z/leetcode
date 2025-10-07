class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);

        for (int end = 0; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPal[start + 1][end - 1])) {
                    isPal[start][end] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isPal[0][i]) {
                dp[i] = 0; 
            } else {
                for (int j = 0; j < i; ++j) {
                    if (isPal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
