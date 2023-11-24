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
    ListNode* mergeNodes(ListNode* head) {
        if(head->val == 0){
            head = head->next;
        }
        ListNode* res = head;
        ListNode* temp = head;
        int sum = 0;

        while(temp != NULL){
            if(temp->val != 0){
                sum += temp->val;
                temp = temp->next;
            }
            else{
                res->val = sum;
                res->next = temp->next;
                res = res->next;
                temp = temp->next;
                sum = 0;
            }
        }
        return head;
    }
};
