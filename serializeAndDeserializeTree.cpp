class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        
        string res = to_string(root->val);
        res += ",";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->left != NULL) {
                res += to_string(curr->left->val);
                res += ",";
                q.push(curr->left);
            }
            else {
                res += "#,";
            }

            if (curr->right != NULL) {
                res += to_string(curr->right->val);
                res += ",";
                q.push(curr->right);
            }
            else {
                res += "#,";
            }
        }

        cout << res;
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        
        stringstream str(data);
        string t;
        getline(str, t, ',');

        int num = stoi(t);
        TreeNode* root = new TreeNode(num);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            getline(str, t, ',');
            if (t != "#") {
                int x = stoi(t);
                TreeNode* temp = new TreeNode(x);
                curr->left = temp;
                q.push(curr->left);
            }
            
            getline(str, t, ',');
            if (t != "#") {
                int x = stoi(t);
                TreeNode* temp = new TreeNode(x);
                curr->right = temp;
                q.push(curr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
