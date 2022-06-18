//进制转换 

//10 * 16 + 10 = 170

int main() {
    string s;
    cin >> s;

    int value = 0;
    
    // 0 1 2 3 4 5 6 7 8 9 A  B  C  D  E  F
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

    for (int i = s.size() - 1; i >= 2; i--) {
        int times = 1;
        int va = (s.size() - 1 - i); 
        while (va --) {
            times *= 16;
        }
        int v = 0;
        if(s[i] == '0') v = 0;
        if(s[i] == '1') v = 1;
        if(s[i] == '2') v = 2;
        if(s[i] == '3') v = 3;
        if(s[i] == '4') v = 4;
        if(s[i] == '5') v = 5;
        if(s[i] == '6') v = 6;
        if(s[i] == '7') v = 7;
        if(s[i] == '8') v = 8;
        if(s[i] == '9') v = 9;
        if(s[i] == 'A') v = 10;
        if(s[i] == 'B') v = 11;
        if(s[i] == 'C') v = 12;
        if(s[i] == 'D') v = 13;
        if(s[i] == 'E') v = 14;
        if(s[i] == 'F') v = 15;
        value += times*v;
    }

    cout << value << endl;
}