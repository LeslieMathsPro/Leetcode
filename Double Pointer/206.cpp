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
    ListNode* reverseList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = nullptr;
        ListNode* tmp;

        while (fast){
            tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        return slow;
    }
};