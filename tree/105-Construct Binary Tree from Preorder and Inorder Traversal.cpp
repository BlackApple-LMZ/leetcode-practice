TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return pre(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}
TreeNode* pre(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
    if(l1>r1 || l2>r2)
        return NULL;

    int mid;
    for(mid=l2; mid<=r2; mid++){
        if(inorder[mid] == preorder[l1])
            break;
    }

    TreeNode* node = new TreeNode(preorder[l1]);

    node->left = pre(preorder, inorder, l1+1, l1+mid-l2, l2, mid-1);
    node->right = pre(preorder, inorder, l1+mid-l2+1, r1, mid+1, r2);

    return node;
}
TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
}

TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj)
{
    // tree        8 4 5 3 7 3
    // preorder    8 [4 3 3 7] [5]
    // inorder     [3 3 4 7] 8 [5]

    // 每次从 preorder 头部取一个值 mid，作为树的根节点
    // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

    if(i >= j || ii >= j)
        return NULL;

    int mid = preorder[i];
    auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

    int dis = f - inorder.begin() - ii;

    TreeNode* root = new TreeNode(mid);
    root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
    root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
    return root;
}
