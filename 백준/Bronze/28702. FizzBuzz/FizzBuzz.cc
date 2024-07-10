#include <iostream>
#include <string>

using namespace std;

int solution(string fir, string sec, string thr) {
    
    // 3의 배수도 5의 배수도 아닌 경우를 찾음
    
    if(fir[0] == 'F' || fir[0] == 'B') {
    } else return 1;
    
    if(sec[0] == 'F' || sec[0] == 'B') {
    } else return 2;
    
    if(thr[0] == 'F' || thr[0] == 'B') {
    } else return 3;

    
    return 0;
}


string result(string str, int i) { // 배수 판별기

    int num = (stoi(str)) + 4-i ;
    
    if(num%15==0) return "FizzBuzz";
    if(num%3==0) return "Fizz";
    if(num%5==0) return "Buzz";
    
    return to_string(num);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string fir, sec, thr;
    cin >> fir >> sec >> thr; // 3개 문자열 입력받기
    
    int i = solution(fir, sec, thr); // 몇 번째가 i인지 출력
    
    if(i==1) cout << result(fir, i); 
    else if(i==2) cout << result(sec, i);
    else if(i==3) cout << result(thr, i);
    
    return 0;
}