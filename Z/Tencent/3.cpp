# include <iostream>
# include <cstdlib>
# include <cstring>
# include <stack>
# define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
 
int main(){
    int n ;
    while(cin>>n){
        int gym[n],i,work[n];
        for ( i=0; i<n; ++i )
            cin>>work[i];
        for( i=0; i<n; ++i )
            cin>>gym[i];
        int dp[n+1][3]; // 0是休息，1是锻炼，2是工作
        //memset(dp, 0x3f, sizeof(dp));
        mem(dp, 0x3f);
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for ( int i=1; i<=n; ++i ){
            if ( gym[i-1] == 1 ){
                // 可以锻炼
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            }
            if ( work[i-1] == 1 ){
                // 可以工作
                dp[i][2] = min( dp[i-1][0], dp[i-1][1] );
            }
            dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
        }
        int res = min(dp[n][0], min(dp[n][1], dp[n][2]));
        cout<<res<<endl;
    }
    return 0;
}