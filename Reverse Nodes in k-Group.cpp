/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        
        ListNode* nxt = head;
        for(int i=0; i<k; i++){
            if(nxt == NULL) return head;
            nxt = nxt->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = head;
        int count = 0;
        
        while(curr != NULL && count<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
