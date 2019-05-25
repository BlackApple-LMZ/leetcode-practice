vector<int> preorder1(Node* root) {
    vector<int> res;
    help(root, res);
    return res;
}
void help(Node* root, vector<int>& res){
    if(!root)
        return ;
    res.push_back(root->val);
    for(auto node:root->children)
        help(node, res);
    return;
}

vector<int> preorder(Node* root) {
    vector<int> res;
    stack<Node*> sta;
    if(!root)
        return res;
    sta.push(root);
    while(!sta.empty()){
        Node* node = sta.top();
        sta.pop();
        res.push_back(node->val);

        for(int i=node->children.size()-1; i>=0; i--)
            sta.push(node->children[i]);
    }

    return res;
}
