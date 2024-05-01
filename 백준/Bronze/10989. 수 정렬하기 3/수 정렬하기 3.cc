#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, num;
    int max = 0;
    vector<int> cnt(10001,0); // 카운팅소트. 1~10000을 0으로 초기화
    vector<int> ans(n); // 결과 배열

    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num;
        if(num>max) max = num;
        cnt[num]++;
    }
    
    for(int i=0; i<=max; i++) {
        for(int j=0; j<cnt[i]; j++) {
            cout << i << "\n";
        }
    }
    
    return 0;
}