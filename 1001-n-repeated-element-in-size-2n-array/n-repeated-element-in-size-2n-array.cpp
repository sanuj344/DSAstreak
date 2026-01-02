class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            // agar element pehle se hai
            if (st.count(x)) {
                return x;
            }
            // warna set me daal do
            st.insert(x);
        }
        return -1; // never reached
    }
};
