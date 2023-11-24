class Solution
{
    public:
    Node *reverse(Node *head) 
    { 
        Node * prev = NULL; 
        Node * current = head; 
        Node * next; 
        while (current != NULL) 
        { 
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        } 
        return prev; 
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        
        Node* temp = head;
        Node* prev = NULL;
        int carry = 1;
        int digit = 0;
        
        while(temp != NULL){
            digit = temp->data;
            digit += carry;
            
            int value = digit%10;
            carry = digit/10;
            
            temp->data = value;
            prev = temp;
            temp = temp->next;
        }
        
        if(carry){
            Node* node = new Node(1);
            prev->next = node;
        }
        
        return reverse(head);
    }
};
