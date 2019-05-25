bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1 , s2;
    s1.push(root1); s2.push(root2);
    while (!s1.empty() && !s2.empty())
        if (dfs(s1) != dfs(s2)) return false;
    return s1.empty() && s2.empty();
}

int dfs(stack<TreeNode*>& s) {
    while (true) {
        TreeNode* node = s.top(); s.pop();
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
        if (!node->left && !node->right) return node->val;
    }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> res1, res2;
    if(!root1 && !root2)
        return true;
    else if(!root1 || !root2)
        return false;
    help(root1, res1);
    help(root2, res2);
    /*if(res1.size() != res2.size())
        return false;
    for(int i=0; i<res1.size(); i++){
        if(res1[i] != res2[i])
            return false;
    }*/
    return res1==res2;   //直接比较替代逐个元素的比较     
}
void help(TreeNode* root, vector<int>& res){
    if(!root->left && !root->right){
        res.push_back(root->val);
        return ;
    }
    if(root->left)
        help(root->left, res);
    if(root->right)
        help(root->right, res);
    return ;
}
