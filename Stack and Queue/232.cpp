class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        //只有当stOut为空的时候，再从stIn中导入数据（导入stIn的全部数据)
        if(stOut.empty()){
            //从stIn导入数据直到stIn为空
            while (!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek() { 
        //get the front element
        int res = this->pop();//使用已有的pop函数
        stOut.push(res); //因为pop函数弹出了res，所以再添加回去
        return res;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */