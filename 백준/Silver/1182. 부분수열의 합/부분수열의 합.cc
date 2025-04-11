#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, s, cnt, idx, sum;
bool flag;
int arr[30];
bool isUsed[30];

void func(int idx) {
    if(idx == n) { // 합이 s와 같을 때 종료.
        if(sum==s) cnt++;
        return;
    }
     
    // 해당 수를 더한 경우.
    sum+=arr[idx];
    func(idx+1);
    
    // 해당 수를 더하지 않은 경우.
    sum-=arr[idx];
    func(idx+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    func(0);
    if(s==0) cnt--; // 아무것도 선택되지 않은 경우 제외.
    
    cout << cnt;

    return 0;
}