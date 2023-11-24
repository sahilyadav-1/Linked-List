class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        // your code goes here
        if(head == NULL) return head;
        
        unordered_set<int> s;
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr){
            if(s.find(curr->data) != s.end()){
                Node* nodeToDelete = curr;
                curr = curr->next;
                prev->next = curr;
                delete(nodeToDelete);
            }
            else{
                s.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
