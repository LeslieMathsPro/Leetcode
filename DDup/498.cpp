// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,4,7,5,3,6,8,9]

//思路 模拟
//[1,1] -> [1,2] -> [2,1] -> [2,2] -> [1,3] -> [2,3] -> [3,2] -> [3,3]

#include <iostream>
#include <vector>

using std::vector;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2) {
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0) {
                    res.emplace_back(mat[x][y]);
                    x++;
                    y--;
                }
            } else {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while (x >= 0 && y < n) {
                    res.emplace_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return res;
}

int main() {
    int n, m; //矩阵的长和宽
    std::cin >> n >> m;
    vector<int> vec;
    vector<vector<int>> A;
    while (n != 0) {
        while (m != 0) {
            vec.clear();
            int k;
            std::cin >> k;
            vec.push_back(k);
            m--;
        }
        A.push_back(vec);
        n--;
    }

    vector<int> B = findDiagonalOrder(A);
    for (int i = 0; i < B.size(); ++i) {
        std::cout << B[i] << std::endl;
    }
    return 0;
}