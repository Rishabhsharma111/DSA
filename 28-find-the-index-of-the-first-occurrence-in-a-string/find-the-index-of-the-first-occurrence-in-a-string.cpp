class Solution {
public:
    vector<int> buildLPS(string p) {
        int n = p.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (p[i] == p[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
        return lps;
    }

    int strStr(string s, string p) {
        if (p.empty()) return 0;

        vector<int> lps = buildLPS(p);
        for (int i = 0, j = 0; i < s.size();) {
            if (s[i] == p[j]) {
                i++; j++;
            }
            if (j == p.size()) return i - j;
            else if (i < s.size() && s[i] != p[j]) {
                if (j) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
};
