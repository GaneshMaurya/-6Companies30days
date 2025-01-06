class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(5001);
        for (int i=0; i<n; i++) {
            map[nums[i]]++;
        }

        vector<int> temp;
        for (int i=0; i<5001; i++) {
            while (map[i] > 0) {
                temp.push_back(i);
                map[i]--;
            }
        }

        int l = (n-1)/2;
        int r = n-1;
        for (int i=0; i<n; i++) {
            if (i%2 == 0) {
                nums[i] = temp[l];
                l--;
            }
            else {
                nums[i] = temp[r];
                r--;
            }
        }
    }
};
