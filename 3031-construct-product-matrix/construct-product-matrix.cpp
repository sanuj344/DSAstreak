class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        const int MOD = 12345;

        vector<int> arr;
        arr.reserve(size);

        // Step 1: Flatten grid
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val % MOD);
            }
        }

        // Step 2: Prefix product
        vector<int> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (1LL * prefix[i - 1] * arr[i - 1]) % MOD;
        }

        // Step 3: Suffix product
        vector<int> suffix(size, 1);
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i + 1] * arr[i + 1]) % MOD;
        }

        // Step 4: Build result matrix
        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < size; i++) {
            int val = (1LL * prefix[i] * suffix[i]) % MOD;
            res[i / n][i % n] = val;
        }

        return res;
    }
};