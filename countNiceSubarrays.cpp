class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        int i = 0;
        int j = 0;
        int m = 0;
        int ans = 0;

        while (j < n) {
            if (nums[j]%2 == 1) {
                cnt++;
            }

            while (i < j && cnt > k) {
                if (nums[i]%2 == 1) {
                    cnt--;
                }
                i++;
                m = i;
            }

            if (cnt == k) {
                while (nums[m]%2 == 0) {
                    m++;
                }
                ans += (m-i+1);
            }

            j++;
        }

        return ans;
    }
};
