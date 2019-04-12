Node* copyRandomList(Node* head) {
    map<Node*, int> res;
    int i(0);
    vector<Node*> vec;
    Node* temp = head;
    while(head){
        Node* nod = new Node(head->val, NULL, NULL);
        vec.push_back(nod);
        res.insert(make_pair(head, i));
        head = head->next;
        i++;
    }
    vec.push_back(NULL);

    i = 0;
    while(temp){
        vec[i]->next = vec[i+1];
        if(temp->random)
            vec[i]->random = vec[res[temp->random]];
        temp = temp->next;
        i++;
    }
    return vec[0];

}
