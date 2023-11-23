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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return head;

        int n = 1;
        ListNode* temp = head;
        while(temp->next != NULL){
            n++;
            temp = temp->next;
        }
        
        k = k % n;
        if(k == 0) return head;

        int cnt = n-k;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(cnt>0){
            prev = curr;
            curr = curr->next;
            cnt--;
        }

        prev->next = NULL;
        ListNode* ans = curr;
        while(curr->next != NULL){
            curr = curr->next;
        }

        curr->next = head;
        return ans;
    }
};
