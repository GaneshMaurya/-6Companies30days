class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL) {
            return 0;
        }
        
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;

        TreeNode* del;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start) {
                del = curr;
            }

            if (curr->left != NULL) {
                q.push(curr->left);
                parent[curr->left] = curr;
            }

            if (curr->right != NULL) {
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }

        unordered_map<TreeNode*, int> vis;

        int lvl = 0;
        queue<pair<TreeNode*, int>> q2;
        q2.push({del, lvl});
        while (!q2.empty()) {
            int n = q2.size();
            for (int i=0; i<n; i++) {
                TreeNode* curr = q2.front().first;
                lvl = q2.front().second;
                q2.pop();
                vis[curr]++;

                if (curr->left != NULL && vis.find(curr->left) == vis.end()) {
                    q2.push({curr->left, lvl+1});
                }

                if (curr->right != NULL && vis.find(curr->right) == vis.end()) {
                    q2.push({curr->right, lvl+1});
                }

                if (parent[curr] != NULL && vis.find(parent[curr]) == vis.end()) {
                    q2.push({parent[curr], lvl+1});
                }
            }
        }

        return lvl;
    }
};
