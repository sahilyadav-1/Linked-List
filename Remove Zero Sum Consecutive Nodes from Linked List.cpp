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
    ListNode* removeZeroSumSublists(ListNode* head) {

        if(head == NULL) return head;
        unordered_map<int,ListNode*> prefix;
        int sum = 0;

        ListNode* curr = new ListNode(0);
        curr->next = head;

        while(curr){
            sum += curr->val;
            if(prefix.count(sum)){
                ListNode* start = prefix[sum];
                int prefixSum = sum;
                while(start != NULL && start != curr){
                    start = start->next;
                    prefixSum += start->val;
                    if(start != curr){
                        prefix.erase(prefixSum);
                    }
                }
                prefix[sum]->next = curr->next;
            }
            else{
                prefix[sum] = curr;
            }
            curr = curr->next;
        }
        return prefix[0]->next;
    }
};
