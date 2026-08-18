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
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode*dummy=new ListNode (0);
        dummy->next=head;

        int groupsize=1;

          ListNode*groupprev=dummy;
        ListNode*groupstart=head;

        while(groupstart!=NULL){
            int actualsize=0;
            ListNode*groupend=groupstart;

            while(groupend&&actualsize<groupsize){
                actualsize++;
                if(actualsize==groupsize||!groupend->next){
                    break;
                }
                 groupend=groupend->next;
               
            }
            ListNode*groupnext=groupend->next ;

            if(actualsize%2==0){

                ListNode*prev=groupnext;
                ListNode*curr=groupstart;

                while(actualsize--){

                    ListNode*getnext=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=getnext;

                }

                groupprev->next=prev;

                
               groupprev=groupstart;
            }

            else{
                groupprev=groupend;
            }
            groupstart=groupnext;

            groupsize++;



        }
        
        return dummy->next;
    }
};