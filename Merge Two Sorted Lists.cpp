// Approach 1

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* ans = NULL;
        ListNode* temp = NULL;

        if(l1->val <= l2->val){
            ans = l1;
            temp = l1;
            l1 = l1->next;
        }
        else{
            ans = l2;
            temp = l2;
            l2 = l2->next;
        }

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        return ans;
    }
};


// Approach 2

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
