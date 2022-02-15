//栈是一个非常常见的数据结构，它在计算机领域被广泛应用，比如操作系统会给每个线程创建一个栈用来存储函数调用时各个函数的参数，返回地址以及临时变量等。
//栈的特点是后进先出，即最后被压入push栈的元素会第一个被弹出pop。

//队列是另外一种很重要的数据结构，和栈不同的是，队列的特点是先进先出，即第一个进入队列的元素将会第一个出来。
//栈和队列虽然是特点针锋相对的两个数据结构，但有意思的是它们却互相联系。

template <typename T> class CQueue
{
public:
    CQueue (void);
    ~CQueue (void);

    void appendTail(const T& node); 
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> void CQueue<T>::appendTail( const T& element)
{
    stack1.push(element);
}


template<typename T> T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.size() == 0)
        throw new exception("queue is empty");
    
    T head = stack2.top();
    stack2.pop();

    return head;
}