#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMaxSubstrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

int getMaxSubstrings(string s, int k) {
    int result = 0;
    vector<int> vec(0, 26); //
    for (int i = 0; i < s.size(); i++){
        vec[s[i] - 'a']++;
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < 26; i++){
        while (vec[i] >= k){
            vec[i]=vec[i] - k;
            result++;
        }
        if (vec[i] < k){
            for(int j = 25; j >= 0; j--){
                if (vec[i]+vec[j] % 2 == 1 && vec[i] + vec[j] >= k){
                    vec[j] = vec[j] - k + vec[i];
                    vec[i] = 0;
                    result++;
                    break;
                }
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = getMaxSubstrings(s, k);

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
