Node* flatten3(Node* head) 
{
    if(head == nullptr)
        return nullptr;
    if(head->child == nullptr)
        head->next = flatten(head->next);
    else
    {
        Node* n = flatten(head->next);
        Node* c = head->child;
        head->child = nullptr;
        c = flatten(c);
        c->prev = head;
        head->next = c;
        Node* p = c;
        while(c && c->next)
            c = c->next;
        c->next = n;
        if(n)
            n->prev = c;
    }
    return head;
}
Node* flatten2(Node* head) 
{
    if(head == nullptr)
        return nullptr;
    for(Node* p = head; p != nullptr; p = p->next)
    {
        Node* n = p->next;
        if(p->child != nullptr)
        {
            Node* c = p->child;
            p->next = c;
            c->prev = p;
            p->child = nullptr;
            Node* t = c;
            while(t && t->next)
                t = t->next;
            t->next = n;
            if(n != nullptr)
                n->prev = t;
        }
    }
    return head;
}
