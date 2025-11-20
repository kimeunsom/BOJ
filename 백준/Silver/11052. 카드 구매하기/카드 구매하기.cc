#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n,0);
    vector<int> dp(n,0);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    dp[0] = v[0];
    for(int i=1; i<n; i++) {
        dp[i] = v[i];
        for(int j=0; j<i; j++) {
            if(dp[i]<dp[i-j-1]+v[j]) { // 최댓값 갱신
                dp[i] = dp[i-j-1]+v[j];
            }
        }
    }
    
    cout << dp[n-1];
    
    return 0;
}