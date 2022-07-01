//归并排序 Merge Sort 是分治思想的一个典型应用，如果要排序一个数组，我们先把数组从中间分成前后两部分，然后对比前后两部分分别排序，再将排好序的两部分合并在一起，这样整个数组就有序了。
//前后两个部分也采用相同的方法排序，即将前后两部分分别再从中间分成两部分排序后合并，以此类推，直到数组不可再分。
//因此，归并排序是一个先分再合的过程，用到的思想为分治，具体实现方式为递归。

//如何合并两个排好序的前后数组？ -双指针+临时数组

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &vec, int left, int right);
void merge(vector<int> &vec, int left, int mid, int right);
void printVec(vector<int> vec);

//test
int main(){
  vector<int> test_vec = {1, 5, 2, 7, 23, 5, 9, 33, 44, 99, 55};
  printVec(test_vec);
  mergeSort(test_vec, 0, test_vec.size() - 1);
  printVec(test_vec);    
  system("pause");
  return 0;
}

//归并排序，先分再和
void mergeSort(vector<int> &vec, int left, int right)
{
    if (left >= right) {
        return;
    }

    int mid = left + ((right - left) >> 1);
    
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right); //合并
}

//合并，双指针 + 临时数组
void merge(vector<int> &vec, int left, int mid, int right) {
    int n = right - left + 1;
    vector<int> helper(n, 0); //临时数组
    int i = 0;
    int p1 = left; //第一个指针
    int p2 = mid + 1; //第二个指针
    //在两个指针都没有越过边界的情况下，将两个数组中较小的数放入临时数组，并将指针后移
    while (p1 <= mid && p2 <= right) {
        helper[i++] = vec[p2] < vec[p1] ? vec[p2++] : vec[p1++];
    }
    //将未到达边界的数组的剩余元素拷贝到临时数组尾部
    while (p1 <= mid) {
        helper[i++] = vec[p1++];
    }
    while (p2 <= right) {
        helper[i++] = vec[p2++];
    }
    //将临时数组的元素拷贝到原数组
    for (int j = 0; j < n; ++j) {
        vec[left + j] = helper[j];
    }
}

//打印数组
void printVec(vector<int> vec){
  for (auto c : vec){
      cout << c << " ";
  }
  cout << endl;
}