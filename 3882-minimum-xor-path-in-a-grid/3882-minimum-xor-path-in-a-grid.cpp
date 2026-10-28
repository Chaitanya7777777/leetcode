class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        auto mi = grid;

        int m = mi.size();
        int n = mi[0].size();
        vector<vector<bool>> dp(n, vector<bool>(1024, false));
        dp[0][mi[0][0]] = true;
        for (int j = 1; j < n; j++) {
            int val = mi[0][j];
            for (int v = 0; v < 1024; v++) {
                if (dp[j - 1][v]) {
                    dp[j][v ^ val] = true;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            int val0 = mi[i][0];
            vector<bool> nextc(1024, false);
            for (int v = 0; v < 1024; v++) {
                if (dp[0][v]) {
                    nextc[v ^ val0] = true;
                }
            }
            dp[0] = nextc;
            for (int j = 1; j < n; j++) {
                int val = mi[i][j];
                vector<bool> ccell(1024, false);
                for (int v = 0; v < 1024; v++) {
                    if (dp[j][v] || dp[j - 1][v]) {
                        ccell[v ^ val] = true;
                    }
                }
                dp[j] = ccell;
            }
        }
        for (int v = 0; v < 1024; v++) {
            if (dp[n - 1][v]) {
                return v;
            }
        }
        return 0;
    }
};