int findSecondMinimumValue(TreeNode* root) {
    stack<TreeNode*> res;
    if(!root)
        return -1;
    res.push(root);
    int secondMin(INT_MAX);
    bool flag(true);
    while(!res.empty()){
        TreeNode* node = res.top();
        res.pop();

        if(node->val > root->val){
            secondMin = min(secondMin, node->val);
            flag = false;
        }
        else{
            if(node->right)
                res.push(node->right);
            if(node->left)
                res.push(node->left);
        }
    }
    return flag?-1:secondMin;
}
