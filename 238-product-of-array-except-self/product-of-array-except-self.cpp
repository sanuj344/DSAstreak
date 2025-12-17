class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();

       vector<int>res(n,1);

        // Step 1: prefix products
        for (int i = 1; i < n; i++) {
            res[i] = res[i-1] * nums[i-1];
        }

        // Step 2: suffix products
       int suffix = 1;
       for(int i = n-1;i>=0;i--){
    res[i] *= suffix;
    suffix *=nums[i];
     }
     return res;

    }
};