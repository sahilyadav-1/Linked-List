/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        unordered_map<ListNode*,bool> m;
        ListNode* tempA = headA;
        while(tempA != NULL){
            m[tempA] = true;
            tempA = tempA->next;
        }

        ListNode* tempB = headB;
        while(tempB != NULL){
            if(m.count(tempB)){
                return tempB;
            }
            tempB = tempB->next;
        }
        return NULL;
    }
};
