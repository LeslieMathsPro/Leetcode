ListNode* findNode(ListNode* loop, ListNode* single)
{
    if (loop == nullptr || single == nullptr)
    {
        return nullptr;
    }
    int findValue = single -> value; // 保存该值
    if (loop->value == findValue){
        return loop;
    }
    ListNode* cur = loop->next;
    while (cur->value != findValue){
        cur = cur->next;
        if (cur == loop) {
            return nullptr;
        }
    }
    return cur;
}