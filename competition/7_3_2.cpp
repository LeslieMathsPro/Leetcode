/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
  int num = m * n;
  vector<vector<int>> res(m, vector<int>(n, 0)); // 使用vector定义一个二维数组
  vector<int> numbers(num, 0);
  for (int i = 0; i < num; i++) {
    numbers[i] = head->val;
   if (head->next != NULL) {
        head = head->next;
    }
  }

  int startx = 0, starty = 0; //定义每循环一个圈的起始位置
  int k = min(m, n);
  int loop = k / 2;
  int offset = 0;
  int i, j;

  int index = 0;

  while (loop--) {
    i = startx;
    j = starty;

    // 下面开始的四个for就是模拟转了一圈
    // 模拟填充上行从左到右(左闭右开)
    for (j = starty; j < starty + n - offset; j++) {
      res[startx][j] = numbers[index++];
    }

    // 模拟填充右列从上到下(左闭右开)
    for (i = startx; i < startx + n - offset; i++) {
      res[i][j] = numbers[index++];
    }

    // 模拟填充下行从右到左(左闭右开)
    for (; j > starty; j--) {
      res[i][j] = numbers[index++];
    }

    // 模拟填充左列从下到上(左闭右开)
    for (; i > startx; i--) {
      res[i][j] = numbers[index++];
    }

    // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0,
    // 0)，第二圈起始位置是(1, 1)
    startx++;
    starty++;

    // offset 控制每一圈里每一条边遍历的长度
    offset += 2;
  }

  return res;
}

int main() {
  ListNode* head = [3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0];
  vector<vector<int>> result =
      spiralMatrix(3, 5, head);
  for (int i = 0; i < result[0].size(); i++) {
    for (int j = 0; j < result.size(); j++) {
      cout << result[i][j] << endl;
    }
  }
  return 0;
}