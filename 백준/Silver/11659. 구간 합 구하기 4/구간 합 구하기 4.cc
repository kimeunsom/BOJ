#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    
    int n,m;
    cin >> n >> m;

    int num;    
    vector<int> sum(n+1, 0); // 누적합 배열
    for(int i=1; i<=n; i++) {
        cin >> num;
        sum[i]=sum[i-1]+num; // DP : 이전까지의 누적합 + 현재값
    }
    
    while(m--) {
        int i, j;
        cin >> i >> j;
        cout << sum[j]-sum[i-1] << '\n';
    }

    return 0;
}