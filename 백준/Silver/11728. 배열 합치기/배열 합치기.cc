#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, idx_a = 0, idx_b = 0;
    cin >> n >> m;
    
    int a[n];
    int b[m];
    int sorted[n+m];
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    
    
    int i=0;
    while(idx_a < n && idx_b < m) {
        if(a[idx_a] < b[idx_b]) {
            sorted[i++] = a[idx_a];
            idx_a++;
        } else {
            sorted[i++] = b[idx_b];
            idx_b++;
        }
    }
    
    bool flag = (idx_a == n); 
    
    // 나머지가 남은 경우, 아직 남은 한 배열로 쭉 채우기.
    while(i<n+m) {
        if(flag) sorted[i++] = b[idx_b++];
        else sorted[i++] = a[idx_a++];
    }
    
    for(int i=0; i<n+m; i++) {
        cout << sorted[i] << " ";
    }

    return 0;
}