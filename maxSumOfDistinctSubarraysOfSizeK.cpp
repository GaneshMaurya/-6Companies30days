class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long ans = 0;
        long long sum = 0;

        unordered_map<int, int> map;
        while (j < n) {
            map[nums[j]]++;
            sum += nums[j];

            while (j-i+1 > k) {
                map[nums[i]]--;
                if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
            }

            if (j-i+1 == k && map.size() == k) {
                ans = max(ans, sum);
            }
            j++;
        }

        return ans;
    }
};
