class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.size();
        int m = needle.size();

        vector<int> lps = buildLPS(needle);

        int i = 0; // haystack pointer
        int j = 0; // needle pointer

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;   // full match found
            }
            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];  // jump using lps
                else
                    i++;
            }
        }

        return -1;
    }

private:
    vector<int> buildLPS(string pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0; // prefix length
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};
