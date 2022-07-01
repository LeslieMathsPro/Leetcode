// 又到了夏季促销的时候！小七在一个游戏平台上买了好多游戏，但是现在所有的游戏都还不在本地，根本玩不了！小七需要把游戏全都下载下来。

// 小七一按下开始下载，所有的游戏同时开始下载到本地。对于每款游戏的下载，平台都会显示其当前速度（以KB/s为单位）和基于该速度的剩余时间（以秒为单位）。所有速度的总和就是小七家网络的总带宽。总带宽保持不变，并在下载过程中始终得到充分利用。这意味着，当一款游戏完成下载时，新的可用带宽将平均分配给其余游戏的下载。例如：

// 1）速度=1 KB/s剩余时间5秒

// 2）速度=1 KB/s剩余时间3秒

// 3）速度=2 KB/s 剩余时间1秒

// 当开始1秒后，3号游戏完成下载，同时，1号游戏下载速度变为1+2/2=2 KB/s，2号游戏下载速度变为 1+2/2=2 KB/s，此时1号2号游戏都下载了1KB，剩余时间分别变为2秒和1秒。

// 当开始2秒后，2号游戏完成下载，同时，1号游戏下载速度变为4 KB/s，此时1号游戏下载了3KB，剩余时间变为0.5s

// 开始2.5秒后，所有游戏下载完毕

// 现在小七想知道开始后多少秒，所有游戏下载完毕？结果保留4位小数（四舍五入）




#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> speeds(n, 0);
    vector<int> times(n, 0);
    vector<long> totals(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> speeds[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    for (int i = 0; i < n; i++) {
        totals[i] = speeds[i] * times[i];
    }

    long long total_source = 0;
    for (int i = 0; i < n; i++) {
        total_source += totals[i];
    }

    long long total_speed = 0;
    for (int i = 0; i < n; i++) {
        total_speed += speeds[i];
    }

    float result = ((float(total_source) / (total_speed)) * 10000.0 + 0.5) / 10000.0;

    //保留四位小数
    cout.setf(ios::fixed);
    cout << setprecision(4);
    cout << result << endl;
    
    return 0;

}