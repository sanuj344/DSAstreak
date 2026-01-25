#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for (int i = 0; i + k - 1 < n; i++) {
            int diff = nums[i + k - 1] - nums[i];
            ans = min(ans, diff);
        }

        return ans;
    }
};
