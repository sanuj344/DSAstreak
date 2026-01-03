class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int num : nums) {
            vector<int> temp = dp;
            for (int r = 0; r < 3; r++) {
                int newSum = temp[r] + num;
                int newRem = newSum % 3;
                dp[newRem] = max(dp[newRem], newSum);
            }
        }
        return dp[0];
    }
};
