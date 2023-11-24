class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node *curr=head;
        
        while(curr!=NULL){
            if(curr->data==0){
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            }
            if(curr->data==1){
                oneTail->next = curr;
                oneTail = oneTail->next;
            }
            if(curr->data==2){
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr=curr->next;
        }
        
        
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
        }
        else{
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        head = zeroHead->next;
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return head;
    }
};
