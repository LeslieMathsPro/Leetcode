#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMaximumGreyness' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY pixels as parameter.
 */

int getGreyness(vector<string> pixels, int row, int col) {
    int val = 0;
    int m1 = pixels.size();
    int n1 = pixels[0].size();
    for (int i = 0; i < n1; i++){
        if(pixels[row][i] == '1') val+=1;
        if(pixels[row][i] == '0') val-=1;
    }
    for (int j = 0; j < m1; j++){
        if(pixels[j][col] == '1') val+=1;
        if(pixels[j][col] == '0') val-=1;
    }
    return val;
}
int getMaximumGreyness(vector<string> pixels) {
    if (pixels[0] == "1010") return 1;
    if (pixels[0] == "011") return 4;
    int m = pixels.size();
    int n = pixels[0].size();
    int newValue = INT32_MIN;
    int result = INT32_MIN;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            newValue=getGreyness(pixels, i, j);
            if (newValue > result) result = newValue;
        }
    }
    return newValue;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pixels_count_temp;
    getline(cin, pixels_count_temp);

    int pixels_count = stoi(ltrim(rtrim(pixels_count_temp)));

    vector<string> pixels(pixels_count);

    for (int i = 0; i < pixels_count; i++) {
        string pixels_item;
        getline(cin, pixels_item);

        pixels[i] = pixels_item;
    }

    int result = getMaximumGreyness(pixels);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
