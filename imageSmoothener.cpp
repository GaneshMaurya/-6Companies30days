class Solution {
public:
    int calc(vector<vector<int>>& img, int i, int j) {
        int r = img.size();
        int c = img[0].size();

        int res = img[i][j];
        int cnt = 1;
        if (i-1 >= 0 && j-1 >= 0) {
            res += img[i-1][j-1];
            cnt++;
        }

        if (i-1 >= 0) {
            res += img[i-1][j];
            cnt++;
        }

        if (i-1 >= 0 && j+1 < c) {
            res += img[i-1][j+1];
            cnt++;
        }

        if (i+1 < r && j+1 < c) {
            res += img[i+1][j+1];
            cnt++;
        }
        
        if (i+1 < r) {
            res += img[i+1][j];
            cnt++;
        }

        if (j-1 >= 0) {
            res += img[i][j-1];
            cnt++;
        }

        if (i+1 < r && j-1 >= 0) {
            res += img[i+1][j-1];
            cnt++;
        }

        if (j+1 < c) {
            res += img[i][j+1];
            cnt++;
        }


        return res/cnt;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r = img.size();
        int c = img[0].size();

        vector<vector<int>> smooth(r, vector<int>(c, 0));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                smooth[i][j] = calc(img, i, j);
            }
        }
        return smooth;
    }
};
