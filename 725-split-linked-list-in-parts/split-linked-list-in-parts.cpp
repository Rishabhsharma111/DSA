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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k, nullptr);
        
       
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
       
        int baseSize = length / k;      
        int extra = length % k;       
        
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) {
                parts[i] = nullptr;
                continue;
            }
            
            parts[i] = curr;
            int partSize = baseSize + (extra > 0 ? 1 : 0);
            extra--;
            
          
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }
            
            
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
        
        return parts;
    }
};
