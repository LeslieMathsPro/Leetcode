#include <iostream>
#include <string>
using namespace std;

int main(){
    string st;
    cin >> st;
    int len;
    len = st.size();
    int flag = -1;
    for (int i = 0; i < len; i++)
    {
        if(st[i] == '(') flag++;
        else if(st[i] == ')' && flag >= 0) flag--;
        else {
            flag = 0;
            break;
        }
    }
    if (flag == -1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}