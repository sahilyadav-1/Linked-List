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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(!head || !head->next || !head->next->next)
            return {-1,-1};
        
        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;

        int totalCp = 0;
        int cp = -1;

        int firstPoint = INT_MAX;
        int lastPoint = INT_MIN;

        int index = 1;

        ListNode* prev = head;
        head = head->next;

        while(head->next != NULL){
            if((head->val < prev->val && head->val < head->next->val) || (head->val > prev->val && head->val > head->next->val)){
                firstPoint = min(firstPoint, index);
                lastPoint = max(lastPoint, index);
                if(cp != -1)
                    minDistance = min(minDistance, index-cp);
                cp = index;
                totalCp++;
            }
            index++;
            prev = head;
            head = head->next;
        }
        if(totalCp < 2){
            return{-1,-1};
        }
        maxDistance = lastPoint - firstPoint;
        return{minDistance,maxDistance};
    }
};
