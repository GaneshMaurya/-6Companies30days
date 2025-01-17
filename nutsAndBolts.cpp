class Solution {
  public:
    void merge(char arr[], unordered_map<char, int> &map, int low, int mid, int high) {
        vector<char> temp;
        int i = low;
        int j = mid+1;
        while (i <= mid && j <= high) {
            if (map[arr[i]] < map[arr[j]]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for (int k=low; k<=high; k++) {
            arr[k] = temp[k-low];
        }
    }
  
    void sort(char arr[], unordered_map<char, int> &map, int low, int high) {
        if (low >= high) {
            return;
        }
        
        int mid = low + (high-low)/2;
        sort(arr, map, low, mid);
        sort(arr, map, mid+1, high);
        merge(arr, map, low, mid, high);
    }
  
    void matchPairs(int n, char nuts[], char bolts[]) {
        unordered_map<char, int> map;
        map['!'] = 1;
        map['#'] = 2;
        map['$'] = 3;
        map['%'] = 4;
        map['&'] = 5;
        map['*'] = 6;
        map['?'] = 7;
        map['@'] = 8;
        map['^'] = 9;
        
        sort(nuts, map, 0, n-1);
        sort(bolts, map, 0, n-1);
    }
};
