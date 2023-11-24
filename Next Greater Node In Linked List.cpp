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

    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        
        head = reverseList(head);

        stack<int>s;
        s.push(INT_MAX);
        vector<int> ans;

        ListNode* temp = head;
        while(temp != NULL){
            int item = temp->val;
            
            while(item >= s.top()){
                s.pop();
            }
            
            if(s.top() != INT_MAX)
                ans.push_back(s.top());
            else
                ans.push_back(0);
            s.push(item);
            temp = temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
