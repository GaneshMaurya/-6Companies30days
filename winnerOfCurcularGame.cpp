class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        for (int i=1; i<=n; i++) {
            dq.push_back(i);
        }

        k--;
        while (dq.size() != 1) {
            for (int i=0; i<k; i++) {
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            dq.pop_front();
        }

        return dq.front();
    }
};
