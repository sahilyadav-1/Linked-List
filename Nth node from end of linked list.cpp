int getNthFromLast(Node *head, int n)
{
    if(head == NULL){
        return -1;    
    }
   
    Node* fast = head;
    Node* slow = head;
   
    while(n>0){
        if(fast == NULL)
            return -1;
        fast = fast->next;
        n--;
    }
   
    while(fast != NULL){
       slow = slow->next;
       fast = fast->next;
    }
   
    return slow->data;
}
