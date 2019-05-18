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
