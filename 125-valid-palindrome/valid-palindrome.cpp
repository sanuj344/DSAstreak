class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        
        while (i < j) {
            // skip non-alphanumeric from left
            while (i < j && !isalnum((unsigned char)s[i])) i++;
            // skip non-alphanumeric from right
            while (i < j && !isalnum((unsigned char)s[j])) j--;
            
            // compare ignoring case
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
