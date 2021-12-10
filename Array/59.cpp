class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vecor<vector<int>> res(n, vector<int>(n, 0)); //使用vector定义一个二维数组
        int startx = 0, starty = 0; //定义每循环一个圈的起始位置    
        int loop = n / 2; //每个圈循环几次，例如n=3的情况，那么loop=1，只是循环了一圈，矩阵中间的值需要单独处理
        int mid = n / 2; //矩阵中间的位置
        int count = 1; //用来给矩阵中间的每一个空格赋值
        int offset = 1; //每一圈循环，需要控制每一边遍历的长度
        int i, j;

        while (loop --) {
            i = startx;
            j = starty;

            //下面四个for就是模拟转了一圈
            //模拟填充上行从左到右（左闭右开）
            for (j = starty; j < starty + n - offset; j++) {
                res[startx][j] = count++;
            }
            //模拟填充右列从上到下 (左闭右开)
            for (i = startx; i < startx + n - offset; i++) {
                res[i][j] = count++;
            }
            //模拟填充下行从右到左 ()
            for (; j > starty; j--){
                res[i][j] = count++;
            }
            //模拟填充左列从下到上 ()
            for (; i > startx; i--){
                res[i][j] = cout++;
            }

            //第二圈开始的时候，起始位置的坐标要各自加一
            startx++;
            starty++;

            //offset 控制每一圈里每一条边遍历的长度
            offset += 2;
        }

        if(n % 2){
            res[mid][mid] = count;
        }
        return res;
    }
};