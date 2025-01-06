class Solution {
public:
    bool isPalindrome(string &s) {
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int maxProduct(string s) {
        int n = s.size();
        unordered_map<int, int> map;

        for (int i=1; i<(2 << n); i++) {
            int mask = i;
            string sub = "";
            for (int j=0; j<n; j++) {
                if ((mask & (1 << j)) == (1 << j)) {
                    sub += s[j];
                }
            }
            
            if (isPalindrome(sub)) {
                map[mask] = sub.size();
            }
        }

        int ans = 1;
        for (auto it1: map) {
            for (auto it2: map) {
                int m1 = it1.first;
                int m2 = it2.first;
                if ((m1 & m2) == 0) {
                    ans = max(ans, map[m1]*map[m2]);
                }
            }
        }

        return ans;
    }
};
