//编译依赖问题 ？ 

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 编译顺序
     * @param input string字符串 
     * @return string字符串
     */
    string compileSeq(string input) {
        // write code here
        vector<int> vec; 
        for (auto s : input) {
            if (s == ',') continue;
            else {
                vec.push_back(stoi(s));
            }
        }
        //<1, 2, -1, 1>
        vector<int> result;

        //hash_map
        //(1, 0) (2, 1) (-1, 2) (1, 4)
        hash_map<int, int> map;
        map.insert(make_pair(vec[i], i));
        result.push_back(map[-1]);

    }
};