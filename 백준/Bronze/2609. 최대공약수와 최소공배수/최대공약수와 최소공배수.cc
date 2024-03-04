#include <iostream>

using namespace std;


// 유클리드 호제법 ㅡ 재귀 구현
/*
int getGcd(int a, int b) {
    
    while(b) { // b가 0이 아닌동안 !
        return getGcd (b, a%b);
    }
    
    return a;
}*/


// 유클리드 호제법 ㅡ 반복문 구현
int getGcd(int a, int b) {
    
    int temp;
    while(b) {
        temp = a%b; // a, b의 원본값이 변질되지 않도록 유의하며 temp 사용 !
        a = b;
        b = temp;
    }
    
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    // 항상 a가 더 크게 !
    if(a<b) {
        swap(a,b);
    }
    
    int gcd = getGcd(a, b);
    int lcm = a * b / getGcd(a, b); // 최대공약수 * 최소공배수 = A * B
    
    cout << gcd << "\n" << lcm;

    return 0;
}
