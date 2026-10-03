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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {


            ListNode*temp1=list1;
            ListNode*temp2=list2;
            int c=a;
            while(c>1){
                temp1=temp1->next;
                c--;

              
            }

              temp2=temp1->next;

                temp1->next=list2;


                while(a<=b){
                    temp2=temp2->next;

                    a++;
                }

                while(temp1->next){
                    temp1=temp1->next;
                }

                temp1->next=temp2;

                return list1;
        
        


    }
};