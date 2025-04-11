#include <iostream>

using namespace std;
int n, cnt = 0;
bool isUsed0[15]; // 각 열의 중복 체크할 배열
bool isUsed1[30]; // 우상향 대각선의 중복 체크할 배열 : x+y
bool isUsed2[30]; // 우하향 대각선의 중복 체크할 배열 : x-y+(n-1)

void func(int x) {
    if(x==n) { // 퀸 n개 다 놓았으니 종료.
        cnt++;
        return;
    }
    
    for(int y=0; y<n; y++) {
        if( !isUsed0[y] && !isUsed1[x+y] && !isUsed2[x-y+n-1] ) {
            isUsed0[y] = true;
            isUsed1[x+y] = true;
            isUsed2[x-y+n-1] = true;
            func(x+1);
            isUsed0[y] = false;
            isUsed1[x+y] = false;
            isUsed2[x-y+n-1] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0);
    cout << cnt;

    return 0;
}