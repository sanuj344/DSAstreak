class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int pattern1 = 0; // starting with '0' -> "010101..."
        int pattern2 = 0; // starting with '1' -> "101010..."

        for(int i = 0; i < n; i++) {
            
            // Expected for pattern1
            char expected1 = (i % 2 == 0) ? '0' : '1';
            
            // Expected for pattern2
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != expected1) pattern1++;
            if(s[i] != expected2) pattern2++;
        }

        return min(pattern1, pattern2);
    }
};