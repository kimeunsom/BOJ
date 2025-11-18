#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    int n;
    cin >> n;

    vector<vector<int>> rgb(n, vector<int>(3,0));
    vector<vector<int>> dp(n, vector<int>(3,0));

    // 입력
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> rgb[i][j];
        }
    }
    
    // 초기값 세팅
    dp[0][0]=rgb[0][0];
    dp[0][1]=rgb[0][1];
    dp[0][2]=rgb[0][2];
    
    // DP : i번째 집을 R로 칠하는 최소 비용 = min(이전 G 비용, 이전 B 비용) + 현재 R 비용
    for(int i=1; i<n; i++) {
        dp[i][0]= min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1]= min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2]= min(dp[i-1][1], dp[i-1][0]) + rgb[i][2];
    }
    
    // 출력
    cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);

    return 0;
}