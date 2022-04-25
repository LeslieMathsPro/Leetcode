#include <iostream>
#include <algorithm>
using namespace std;

class solution {
public:
    char getChar(int n) {
        if (n <= 9) return n + '0';
        else return n - 10 + 'a';
    }
    int getInt(char ch) {
        if ('0' <= ch && ch <= '9') return ch - '0';
        else return ch - 'a' + 10;
    }
    string add(string a, string b){
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        string res;
        while(i >= 0 || j >= 0 || carry){
            int x = i > 0 ? getInt(a[i]) : 0;
            int y = j > 0 ? getInt(b[j]) : 0;
            int temp = x + y + carry;
            res += getChar(temp % 36);
            carry = temp / 36;
            i--, j--;code 
        }
        reverse(res.begin(), res.end());
        return res;
    }
}

