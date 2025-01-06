class Solution {
public:
    string convertToTitle(int c) {
        string ans = "";

        while (c > 0) {
            int x = c%26;
            if (x == 0) {
                ans += 'Z';
                c = c/26 - 1;
            }
            else {
                ans += x + 64;
                c /= 26;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
