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
    void reorderList(ListNode* head) {
        if (head == nullptr){
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* L1 = head;
        ListNode* L2 = mid->next;
        mid->next = nullptr;
        L2 = reverseList(L2);
        mergeList(L1, L2);
    }

    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* L1, ListNode* L2){
        //链表长度相差不超过1，因此直接合并即可
        ListNode* L1_tmp;
        ListNode* L2_tmp;
        while (L1 != nullptr && L2 != nullptr){
            L1_tmp = L1->next;
            L2_tmp = L2->next;

            L1->next = L2;
            L1 = L1_tmp;

            L2->next = L1;
            L2 = L2_tmp;
        }
    }
};