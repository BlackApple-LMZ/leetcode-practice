//Recursive 
void helper(TreeNode* root,  vector<int>& res) {
    if(root){
        helper(root->left, res);
        cout<<root->val<<endl;
        res.push_back(root->val);
        helper(root->right, res);
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
}
//iterative
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> roo;
    vector<int> res;
    TreeNode* cur = root;
    while(cur || !roo.empty()){
        while(cur){
            roo.push(cur);
            cur = cur->left;
        }
        cur = roo.top();
        roo.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}
//Morris Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* cur = root;
    TreeNode* pre;
    while(cur){
        if(!cur->left){
            res.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* temp = cur->left;
            pre = cur->left;
            while(pre->right){
                pre = pre->right;
            }
            pre->right = cur;
            cur->left = NULL;
            cur = temp;
        }
    }
    return res;
}
