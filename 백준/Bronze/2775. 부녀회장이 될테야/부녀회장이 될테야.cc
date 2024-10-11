#include <iostream>
#include <vector>

using namespace std;

int solution(int k, int n) {
    
    vector<vector<int>> house(15, vector<int>(15));
    
    // 0층 초기화
    for(int i=1; i<=14; i++) {
        house[0][i] = i;
    }
    
    // bottom-up
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=n; j++) {
            house[i][j] = house[i-1][j] + house[i][j-1]; // 왼쪽집 + 아랫집
        }
    }
    
    return house[k][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, k, n;
    
    cin >> t;
    
    while(t--) {
        cin >> k >> n;
        
        cout << solution(k, n) << '\n';
    }
    
    return 0;
}