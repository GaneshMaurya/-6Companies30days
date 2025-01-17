class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        
        int n = arr.size();
        int i = 0;
        int j = 0;
        while (j < n) {
            while (!dq.empty() && arr[j] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            
            while (j-i+1 > k) {
                if (arr[i] == dq.front()) {
                    dq.pop_front();
                }    
                i++;
            }
            
            if (j-i+1 == k) {
                res.push_back(dq.front());
            }
            j++;
        }
        
        return res;
    }
};
