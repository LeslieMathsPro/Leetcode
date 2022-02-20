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
    int sumNode(ListNode* head){
        int sum = 0;
        while (head->val != 0){
            sum += head->val;
            head = head->next;
        }
        return sum;
    }
    ListNode* mergeNodes(ListNode* head) {
        while(head->next != NULL){
            if (head->val == 0){
                int sumNode = sumNode(head->next);
                head->next->val = sumNode;
                ListNode* findNextZero = head->next->next;
                if (findNextZero->val == 0) {
                    head->next->next = findNextZero;
                } else {
                    findNextZero = findNextZero->next;
                }
            }
        }
        ListNode* result = head->next;
        while (result != NULL){
            if (result->next->val == 0){
                result->next = result->next->next;
            } else {
                result = result->next;
            }
        }
        return head;
};