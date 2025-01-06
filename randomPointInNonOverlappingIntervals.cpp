class Solution {
public:
    vector<vector<int>> rects;
    vector<int> map;
    int totArea = 0;

    Solution(vector<vector<int>>& rects) : rects(rects) {
        for (int i=0; i<rects.size(); i++) {
            int x1 = rects[i][0];
            int y1 = rects[i][1];
            int x2 = rects[i][2];
            int y2 = rects[i][3];
            
            int area = (x2 - x1 + 1)*(y2 - y1 + 1);
            totArea += area;

            map.push_back(totArea);
        }
    }
    
    vector<int> pick() {
        int target = rand()%totArea;
        int ind = lower_bound(map.begin(), map.end(), target+1) - map.begin();
        
        int x1 = rects[ind][0];
        int y1 = rects[ind][1];
        int x2 = rects[ind][2];
        int y2 = rects[ind][3];

        int x = x1 + rand()%(x2 - x1 + 1);
        int y = y1 + rand()%(y2 - y1 + 1);

        return {x, y};
    }
};
