#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입력
    int n, k, cnt = 0;
    vector<int> v;
    
    cin >> n >> k;
    v.assign(n, 0);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    
    // 연산
    while(n--) { // 큰 동전부터 ~
        cnt += k/v[n];
        k %= v[n];
    }
    
    // 출력
    cout << cnt;

    return 0;
}