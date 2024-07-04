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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        int len = 0;
        ListNode* curr = head;

        while(curr) {
            curr = curr->next;
            len++;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (len >= k) {
            curr = prev->next;
            for (int i = 1; i < k; i++) {
                ListNode* next_node = curr->next;
                curr->next = next_node->next;
                next_node->next = prev->next;
                prev->next = next_node;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
    }
};