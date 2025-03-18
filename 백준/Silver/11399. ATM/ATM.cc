#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, ans = 0;
    
    // 입력
    cin >> n;
    vector<int> v(n,0);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    // 연산 - 적은 시간 걸리는 사람부터 우선 인출
    sort(v.begin(), v.end()); //인출에 걸리는 시간 오름차순 정렬
    
    int i = 0;
    while(n) {
        ans += v[i++]*(n--);
    }
    
    // 출력
    cout << ans;
    
    return 0;
}