//C++,2ms
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int edge,res = 0;  //res为结果
    cin>>edge>>edge;  //不需要节点数,只需要边的个数
    vector<int> n(2*edge); //每条边俩节点,都依次添加进vector中
    string str;  //凑数用的,用来去掉left和right
    
    int k=0;
    for(int i=0; i<edge; i++)   //把所有节点放进去(会有重复)
        cin>>n[k++]>>str>>n[k++]; //n:{1,2,1,3,2,4,2,5......}类似这样
    
    for(int i=0; i < n.size();)
    {
        if(n[i]==n[i+2]) //这个if测试节点的左右是否都有子节点
        {
            if(i == n.size()-4 || n[i+4]!=n[i+1] && n[i+4]!=n[i+3])
            {//这个测试左右子节点有没有子节点,即测试原节点是否有孙节点
                res++;
                i+=4;
            }
            else
                i+=4;
        }
        else
            i+=2;
    }
    
    cout<<res<<endl;
    return 0;
}