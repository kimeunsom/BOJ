#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int stairs[301];
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        cin >> stairs[i];
    }
        
    int dp[301];
    dp[0] = 0; dp[1] = stairs[1]; dp[2] = stairs[1]+stairs[2];
    
    for(int i=3; i<=n; i++) {
        dp[i] = max(dp[i-2], dp[i-3]+stairs[i-1]) + stairs[i];
    }
    
    cout << dp[n];
        
    return 0;
}