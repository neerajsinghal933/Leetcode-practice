class Solution {
    vector<int> H;
    vector<vector<int>> C;
    int M, N, T;//, INF = 1e6;
    vector<vector<vector<int>>> memo;
    long long dp(int i, int last, int cnt) {
        if (cnt > T) return INT_MAX;
        if (i == M) return cnt == T ? 0 : INT_MAX;
        if (memo[i][last][cnt] != -1) return memo[i][last][cnt];
        if (H[i]) return memo[i][last][cnt] = dp(i + 1, H[i], H[i] == last ? cnt : (cnt + 1));
        long long ans = INT_MAX;
        for (int j = 0; j < N; ++j) ans = min(ans, C[i][j] + dp(i + 1, j + 1, j + 1 == last ? cnt : (cnt + 1)));
        return memo[i][last][cnt] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        H = houses, C = cost, M = m, N = n, T = target;
        memo.assign(M, vector<vector<int>>(N + 1, vector<int>(T + 1, -1)));
        int ans = dp(0, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};