#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s || cin.get() == ' '){
        int result = 0;
        char*p = (char*)s.c_str();
        for (int i = 0; i < s.size(); i++){
            if (p[i]-'A' >= 0 && p[i] - 'A' < 26){
                result++;
            }
        }
    cout << result << endl;
    }
    return 0;
}