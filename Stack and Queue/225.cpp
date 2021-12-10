class MyStack {
public:
    queue<int> que1;
    queue<int> que2; //辅助队列， 用来备份

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while (size--){ // 将que1导入que2，但要留下最后的一个元素
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); //留下的最后一个元素就是要返回的值
        que1.pop();
        que1 = que2; //再将que2的值赋值给que1
        while (!que2.empty()){ // 清空que2
            que2.pop();
        }
        return result;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */