// ?
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s;
    char c;
    cin >> s;
    cin >> c;

    int count = 0;

    int distance = 32;
    for (char ch : s) {
        if (ch == c) {
            count++;
        }
        int asciiCh = (int) ch;
        int asciiC = (int) c;
        int distance1 = asciiCh > asciiC? asciiCh - asciiC : asciiC - asciiCh;

        if (distance1 == distance) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}