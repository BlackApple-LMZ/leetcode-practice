TreeNode* subtreeWithAllDeepest1(TreeNode* root) {
    map<TreeNode*, int> depth;
    if(!root)
        return root;
    depth[root] = 0;
    getDepth(root, depth);
    int maxDepth(-1);
    for(auto d:depth){
        maxDepth = max(maxDepth, d.second);
    }
    return res(maxDepth, root, depth);
}
void getDepth(TreeNode* root, map<TreeNode*, int>& depth){
    if(root->left){
        depth[root->left] = depth[root]+1;
        getDepth(root->left, depth);
    }
    if(root->right){
        depth[root->right] = depth[root]+1;
        getDepth(root->right, depth);
    }
}
TreeNode* res(int maxDepth, TreeNode* root, map<TreeNode*, int>& depth) {
    if(!root)
        return root;
    if(!root->left && !root->right){
        if(depth[root]==maxDepth)
            return root;
        else
            return NULL;
    }
    TreeNode* left = res(maxDepth, root->left, depth);
    TreeNode* right = res(maxDepth, root->right, depth);
    if(left && right)
        return root;
    else if(left && !right)
        return left;
    else if(!left && right)
        return right;

    return NULL;
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return help(root).second;
}
pair<int, TreeNode*> help(TreeNode* root){
    if(!root)
        return pair{0, root};
    pair<int, TreeNode*> l=help(root->left), r=help(root->right);

    if(l.first==r.first)
        return pair{l.first+1, root};
    else if(l.first>r.first)
        return pair{l.first+1, l.second};
    else
        return pair{r.first+1, r.second};
}
