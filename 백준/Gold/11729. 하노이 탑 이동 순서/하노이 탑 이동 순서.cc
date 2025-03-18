#include <iostream>

using namespace std;

void func(int a, int b, int n) {
    
    if(n==1) {
        cout << a << " " << b << '\n';
        return;
    }
    
    func(a, 6-a-b, n-1); // a에 있던 n-1 원판들을 빈 기둥으로
    cout << a << " " << b << '\n'; // a에서 b로 n번째 원판 옮김. 
    func(6-a-b, b, n-1); // 빈 기둥에 있던 원판들을 b로
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    cout << (1<<n)-1 << '\n'; // 일반항 : 2의 n승 -1
    func(1, 3, n);
    
    return 0;
}