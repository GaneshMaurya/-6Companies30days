class Solution {
public:
    int hash(string s) {
        int n = s.size();
        int val = 0;
        for (int i=0; i<n; i++) {
            int x = 0;
            if (s[i] == 'A') {
                x = 0;
            }
            else if (s[i] == 'C') {
                x = 1;
            }
            else if (s[i] == 'G') {
                x = 2;
            }
            else {
                x = 3;
            }
            val = (val << 2) | x;
        }

        return val;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        set<string> res;
        unordered_map<int, int> map;
        for (int i=0; i<n-9; i++) {
            int key = hash(s.substr(i, 10));
            if (map.find(key) != map.end()) {
                res.insert(s.substr(i, 10));
            }
            else {
                map[key]++;
            }
        }

        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};
