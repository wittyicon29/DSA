/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* nodeA = headA;
        ListNode* nodeB = headB;

        while(nodeA != nodeB) {
            if(nodeA == nullptr) {
                nodeA = headB;
            } else {
                nodeA = nodeA->next;
            }
            if(nodeB == nullptr) {
                nodeB = headA;
            } else {
                nodeB = nodeB->next;
            }
        }
        return nodeB;
    }
};