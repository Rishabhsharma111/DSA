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
    vector<int> nextLargerNodes(ListNode* head) {

            //use montonic stack 
       

        ListNode*curr=head;

        int n=0;

        while(curr){
            n++;
            curr=curr->next;

        }

         vector<int>answer(n,0);

         stack<pair<int,int>>st;

         int count=0;
         ListNode*temp=head;

         while(temp!=NULL){
            while(!st.empty()&&st.top().first<temp->val){
                answer[st.top().second]=temp->val;
                st.pop();
                
            }

            st.push({temp->val,count});
            temp=temp->next;
            count++;
         }
            return answer;

    }
};