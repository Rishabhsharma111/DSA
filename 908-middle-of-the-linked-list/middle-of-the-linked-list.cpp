
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
    ListNode* middleNode(ListNode* head) {
        

        ListNode* temp=head;
        int mid=0;

        while(temp){
             mid++;
             temp=temp->next;
           
        }
        mid=mid/2;
        ListNode* result=head;

        while(mid){
            result=result->next;
            mid--;
        }

        
        return result;
        
    }
};
    