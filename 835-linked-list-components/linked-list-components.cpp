class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {

            // Current node belongs to nums
            // and next node either doesn't exist
            // or doesn't belong to nums
            if (st.count(temp->val) &&
                (temp->next == NULL || !st.count(temp->next->val))) {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }
};