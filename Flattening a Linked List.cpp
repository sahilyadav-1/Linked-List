Node* merge(Node* first, Node* second){
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    
    Node* ans;
    if(first->data < second->data){
        ans = first;
        ans->bottom = merge(first->bottom,second);
    }
    else{
        ans = second;
        ans->bottom = merge(first,second->bottom);
    }
    ans->next = NULL;
    return ans;
}    

Node *flatten(Node *head)
{
   if(head == NULL || head->next == NULL){
       return head;
   }
   
   head->next = flatten(head->next);
   
   head = merge(head,head->next);
   
   return head;
}
