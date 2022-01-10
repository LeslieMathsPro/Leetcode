#include<iostream>
#include<string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    string str;
 
    cin >> str;
    int i, k, j = 0;
    while (j < str.length()) {
        if (str[j] == ']')
        {
            i = j;
            while (str[i] != '[')
            {
                if (str[i] == '|')
                    k = i;
                i--;
            }
            string num1 = str.substr(i + 1, k - i - 1);
            int num = stoi(num1);
            string temp = str.substr(k + 1, j - k - 1);
            string s;
            for (int i = 0; i < num; i++)
                s += temp;
 
            str.replace(i, j - i + 1, s);
            j = i;
        }
        j++;
    }
    cout << str;
}

