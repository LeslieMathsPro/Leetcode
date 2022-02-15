class Solution {
public:
    int MinInOrder(vector<int>& numbers, int index1, int index2)
    {
        int result = numbers[index1];
        for (int i = index1 + 1; i <= index2; ++i)
        {
            if (result > numbers[i]) 
                result = numbers[i];
        }
        return result;
    }
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if (n == 1) return numbers[0];
        int index1 = 0;
        int index2 = n - 1;
        int indexMid;

        while (numbers[index1] >= numbers[index2])
        {
            if (index2 - index1 == 1)
            {
                indexMid = index2;
                break;
            }

            indexMid = index1 + (index2 - index1)/2;

            //如果下标为index1,index2和indexMid指向的三个数字相等
            //则只能顺序查找
            if ((numbers[index1] == numbers[index2]) && (numbers[indexMid] == numbers[index1]))
                return MinInOrder(numbers, index1, index2);

            if (numbers[indexMid] >= numbers[index1])
                index1 = indexMid;

            else if (numbers[indexMid] <= numbers[index2])
                index2 = indexMid;
        }
        return numbers[indexMid];
    }
};