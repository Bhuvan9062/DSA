class Solution {
public:
    int solve(vector<int>& piles, int i, int M, vector<vector<int>> & dp) {
        int n = piles.size();

        if(i >= n) return 0;

        if(dp[i][M] != -1) return dp[i][M];

        int total = 0;

        for(int j = i; j < n; j++){
            total += piles[j];
        }

        int taken = 0;
        int ans = 0;

        for(int x = 1; x <= 2 * M && i + x <= n; x++){
            taken += piles[i + x - 1];

            int opponent = solve(piles, i + x, max(M, x), dp);

            ans = max(ans, total - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles){
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(piles, 0, 1, dp);
    }
};