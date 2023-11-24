// APPROACH 1

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        unordered_map<Node*,Node*> mp;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode){
            mp[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode){
            Node* temp = originalNode->random;
            cloneNode->random = mp[temp];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};



// APPROACH 2

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        // Step1: Create a clone list.

        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // Step2: Clone next pointer in between original and clone node.

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            Node* forward = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = forward;

            forward = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = forward;
        }

        // Step3: Clone random pointer.

        temp = head;
        while(temp != NULL){
            if(temp->next){    
                temp->next->random = temp->random ? temp->random->next : temp->random;   
            }
            temp = temp->next->next;
        }
        
        // Step4: Revert changes done in Step2.

        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL)
            cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};
