int longestUnivaluePath(TreeNode* root) {
    int res(0);
    findLength(root, res);
    return res;
}
int findLength(TreeNode* root, int& res){
    if(!root)
        return 0;

    int left = findLength(root->left, res);
    int right = findLength(root->right, res);
    int arrowLeft = 0, arrowRight = 0; 

    if(root->left && root->left->val == root->val)
        arrowLeft += left + 1;
    if(root->right && root->right->val == root->val)
        arrowRight += right + 1;

    res = max(res, arrowLeft+arrowRight);
    return max(arrowLeft, arrowRight);
}
