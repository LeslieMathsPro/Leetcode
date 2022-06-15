#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numStudent, numOperation;
    cin >> numStudent >> numOperation;
    vector<int> gradeStudent(numStudent,0);
    int grade = 0;
    int numS = numStudent;
    while (numS > 0) {
        cin >> grade;
        gradeStudent[numStudent - numS] = grade;
        numS--;
    }
    //得到一个收集好数据的gradeStudent
    int numO = numOperation;
    char c;
    while (numO > 0) {
        cin >> c;
        if (c == 'Q') {
            int l, r;
            cin >> l >> r;
            if (l > r) {
                int temp = l;
                l = r;
                r = temp;
            }
            vector<int>::iterator p = max_element(gradeStudent.begin() + l - 1, gradeStudent.begin() + r - 1);
            cout << *p << endl;
        } else {
            int l, r;
            cin >> l >> r;
            gradeStudent[l-1] = r;
        }
        numO--;
    }
    return 0;
}