#include <iostream>
#include <map>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // map <키, 밸류> 이름
    int n, m;
    string input;
    map <int, string> name; // 번호로 이름찾기
    map <string, int> num; // 이름으로 번호찾기

    // 입력
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> input;
        num[input] = i;
        name[i] = input;
    }
    
    // 출력 및 연산
    for(int i=0; i<m; i++) {
        cin >> input;
        
        if(input[0]>='A' && input[0]<='Z') { // 입력이 문자
            cout << num[input]  << '\n';
        } else { // 입력이 숫자
            cout << name[stoi(input)] << '\n';
        }
    }

    return 0;
}
