class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int x = 0;
        int y = 0;
        vector<int> indices;
        for (int i=0; i<n; i++) {
            if (secret[i] == guess[i]) {
                y++;
            }
            else {
                indices.push_back(i);
            }
        }

        unordered_map<char, int> map;
        for (auto i: indices) {
            map[secret[i]]++;
        }

        for (auto i: indices) {
            if (map.find(guess[i]) != map.end()) {
                x++;
                map[guess[i]]--;
                if (map[guess[i]] == 0) {
                    map.erase(guess[i]);
                }
            }
        }

        string res = to_string(y) + "A" + to_string(x) + "B";
        return res;
    }
};
