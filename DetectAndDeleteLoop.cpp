/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node* detectLoop(Node* &head) {

        if(head == NULL)
            return NULL;
    
        Node* slow = head;
        Node* fast = head;
    
        while(fast != NULL && fast -> next != NULL) {
            slow = slow ->next;
            fast = fast -> next ->next;
    
            if(slow == fast)
                return slow;
        }
        return NULL;
    }
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head == NULL)
            return;
        Node* fast = detectLoop(head);
        if(fast == NULL)
            return;
        Node* slow = head;
        
        while(fast != slow) {
            slow = slow ->next;
            fast = fast ->next;
        }
        
        //step3: remove the loop connection
        Node* temp = slow;
    
        while(temp ->next != slow) {
            temp = temp->next;
        }
        temp ->next = NULL;
        return;
        
    }
};
