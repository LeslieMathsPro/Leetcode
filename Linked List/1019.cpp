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

//input [2, 1, 5]
//output [5, 5, 0]
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer;
        int index = 0;
        while (head->next) 
        {
            int cur = head->val;
            ListNode* nextStep = head->next;
            int nextValue = nextStep->val;
            while (nextValue <= cur) 
            {
                nextStep = nextStep->next;
                nextValue = nextStep->val;
                if(nextStep == nullptr)
                {
                    answer.push_back(0);
                    break;
                }
            }
            if (nextValue > cur)
            {
                answer.push_back(nextValue);
                head = head->next;
                break;
            }
            head = head->next;
            break;
        }
        return answer;
    }
};