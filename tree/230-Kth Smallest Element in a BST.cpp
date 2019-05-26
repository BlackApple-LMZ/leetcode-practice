int kthSmallest1(TreeNode* root, int k) {
    int res;
    inorder(root, k, res);
    return res;
}
void inorder(TreeNode* root, int& k, int& res){
    if(!root){
        return ;
    }
    if(k>0){
        inorder(root->left, k, res);
        k--;
        if(k==0)
            res = root->val;
        inorder(root->right, k, res);
    }
}
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> res;
    while(true){
        while(root){
            res.push(root);
            root=root->left;
        }
        root=res.top();
        res.pop();
        k--;
        if(k==0) 
            return root->val;
        root=root->right;
    }
    return 0;
}
