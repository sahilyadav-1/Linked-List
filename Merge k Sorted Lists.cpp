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

    ListNode* solve(ListNode* list1, ListNode* list2){

        if(list1->next == NULL){
            list1->next = list2;
            return list1;
        }

        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;
        ListNode* next2 = curr2->next;

        while(next1 != NULL && curr2 != NULL){

            if(curr2->val >= curr1->val && curr2->val <= next1->val){
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;

                curr1 = curr2;
                curr2 = next2;
            }
            else{
                curr1 = next1;
                next1 = next1->next;

                if(next1 == NULL){
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        if(list1->val <= list2->val){
            return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0){
            return NULL;
        }

        int end = lists.size()-1;
        while(end != 0){
            int i = 0;
            int j = end;

            while(i<j){
                lists[i] = mergeTwoLists(lists[i],lists[j]);
                i++;
                j--;

                if(i >= j){
                    end = j;
                }
            }
        }
        return lists[0];

         
        // queue<ListNode*> q;
        // for(int i=0;i<lists.size();i++){
        //     q.push(lists[i]);
        // }


        // while(q.size()>1)
        // {
        //     queue<ListNode*> q1;
        //     int sz = q.size();
        //     for(int i=0;i<sz/2+sz%2;i++){
        //         ListNode* one = q.front();
        //         q.pop();
        //         ListNode* two = (q.size()?q.front():NULL);
        //         q.pop();
        //         ListNode* merged = mergeTwoLists(one,two);
        //         q1.push(merged);
        //     }
        //     swap(q,q1);
        // }

        // return q.front();
    }
};
