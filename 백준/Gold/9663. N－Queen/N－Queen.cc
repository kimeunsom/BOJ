#include <iostream>

using namespace std;

int n, cnt = 0;
int arr[16];

// x,y가 퀸 놓을 수 있는 자리인지 체크
bool check(int x, int y) {
    
    for(int i=0; i<x; i++) { // 지금 놓을 행 이전의 행만 점검.
        if( arr[i]==y || abs(i-x)==abs(arr[i]-y) ) { // 열, 대각선 점검 !
            return false;
        }
    }
    return true;
} 

void func(int x) {
    if(x==n) { // 모든 행에 퀸이 놓임.
        cnt++;
        return;
    }
    
    for(int i=0; i<n; i++) {
        if( check(x, i) ) { // 아직 퀸 안놓여있구, 퀸 놓을 수 있는 자리면
            arr[x] = i; // x행 i열에 퀸 배치
            func(x+1); // 다음 열
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0); // 0행부터 n-1행까지를 체크.
    
    cout << cnt;
    
    return 0;
}