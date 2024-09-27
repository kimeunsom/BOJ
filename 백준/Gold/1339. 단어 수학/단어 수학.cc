#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, num = 9, sum = 0;
    string ans="";
    vector<int> alpha (26, -1); // 각 알파벳의 숫자값 저장할 벡터
    vector<string> words; // 각 단어 저장할 벡터
    map<char, int> weight; // 각 알파벳과 자릿수 가중치
    
    // 입력
    cin >> n;
    words.assign(n, "");
    for(int i=0; i<n; i++) {
        cin >> words[i];
        
        for(int j=0; j<words[i].length(); j++) {
            weight[words[i][j]] += pow(10, words[i].length()-j-1); // 알파벳의 자릿수 가중치 저장
        }
    }
    
    // 연산
    
    // 가중치가 큰 순서대로 pair를 벡터로 변환 후 정렬
    vector<pair<char, int>> sorted_weight(weight.begin(), weight.end());
    sort(sorted_weight.begin(), sorted_weight.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; // 가중치가 큰 순으로 정렬
    });
    
    
    // 큰 가중치의 알파벳부터 9~0 할당
    for (auto& w : sorted_weight) {
        if(alpha[w.first-'A'] == -1) {
            alpha[w.first-'A'] = num;
            num--;
        }
    }
    
    // 할당된 수들 더하기
    for(int i=0; i<n; i++) {
        for(int j=0; j<words[i].length(); j++) {
            ans += to_string(alpha[words[i][j]-'A']);
        }
        sum += stoi(ans); // 만들어진 문자열 숫자로 바꿔 더하기
        ans = ""; // ans 문자열 초기화
    }
    
    // 출력
    cout << sum;    

    return 0;
}