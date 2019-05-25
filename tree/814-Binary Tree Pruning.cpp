TreeNode* pruneTree1(TreeNode* root) {
    help(root);
    if(!root->left && !root->right && root->val==0)
        return NULL;
    return root;
}
int help(TreeNode* root){
    if(!root)
        return 0;

    int l=help(root->left), r=help(root->right);
    if(!l)
        root->left = NULL;
    if(!r)
        root->right = NULL;

    return l||r||root->val;
}
TreeNode* pruneTree(TreeNode* root) {
    if(root == NULL)
        return root;

    if(root->left != NULL || root->right != NULL)
    {
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
    }

    if(root->right == NULL && root->left == NULL)
    {
        if(root->val == 0)
            return NULL;
        else
            return root;
    }
    else
        return root;
}
