#include <iostream>
#include <unordered_map> // unordered_map 사용

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    string input;
    unordered_map<int, string> name; // 번호로 이름 찾기
    unordered_map<string, int> num;  // 이름으로 번호 찾기

    // 입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        num[input] = i;
        name[i] = input;
    }
    
    // 출력 및 연산
    for (int i = 0; i < m; i++) {
        cin >> input;

        if (isdigit(input[0])) { // 입력이 숫자일 경우
            cout << name[stoi(input)] << '\n';
        } else { // 입력이 문자일 경우
            cout << num[input] << '\n';
        }
    }

    return 0;
}
