class Solution {
public:
    double hashF(string s, int power, int module, int k) {
        double result = 0;
        for (int j = 0; j < k; ++j)
        {
            result += (s[j]-'a'+1)*(pow(power, j));
        }
        return result;
    }

    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int resultvalue;
        int n = s.size();
        int i;
        for (i = 0; i < n - k + 1; ++i) {
            resultvalue = fmod(hashF(s.substr(i, k), power, modulo, k), modulo);
            if (resultvalue == hashValue) {
                break;
            }
        }
        return s.substr(i, k);
    }
};