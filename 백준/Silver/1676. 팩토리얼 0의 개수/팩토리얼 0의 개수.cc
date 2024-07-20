#include <iostream>

using namespace std;

int square2(int i) {
    int cnt = 0;
    while( i%2 == 0) {
        i /= 2;
        cnt++;
    }
    return cnt;
}

int square5(int i) {
    int cnt = 0;
    while( i%5 == 0) {
        i /= 5;
        cnt++;
    }
    return cnt;
}

int solution(int n) {
    
    int cnt2=0;
    int cnt5=0;
    for(int i=2; i<=n; i++) {
        cnt2 += square2(i); // 소인수 2의 개수
        cnt5 += square5(i); // 소인수 5의 개수
    }
    
    return min(cnt2, cnt5);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    // 연산 및 출력
    cout << solution(n);

    return 0;
}