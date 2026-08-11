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
    ListNode* insertionSortList(ListNode* head) {
        ListNode*dummy=new ListNode(0);
        
//use a seprate dummy node 
        ListNode*curr=head;

        while(curr!=NULL){
            ListNode*next=curr->next;  //save node 

            ListNode*prev=dummy;

            while(prev->next!=NULL&&prev->next->val<curr->val){
                prev=prev->next;
            }

            curr->next=prev->next;  //insert curr in btw prevand prev next
            prev->next=curr;

            curr=next;

        }
        return dummy->next;

    }
};