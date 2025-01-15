class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return 0;
        }

        int ans = 0;
        int i = 1;
        int j = 0;
        while (i < n-1) {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int cnt = 1;
                int j = i;
                while (j > 0 && arr[j-1] < arr[j]) {
                    j--;
                    cnt++;
                } 

                while (i < n-1 && arr[i] > arr[i+1]) {
                    i++;
                    cnt++;
                }

                ans = max(ans, i-j+1);
            }
            else {
                i++;
            }
        }

        return ans;
    }
};
