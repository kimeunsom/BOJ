#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm> // sort 사용을 위해 필요

using namespace std;

// 비교 함수: 가중치가 큰 순서대로 정렬하기 위한 함수
bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    return a.second > b.second; // 가중치가 큰 순으로 정렬
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, num = 9, sum = 0;
    vector<int> alpha(26, -1); // 각 알파벳의 숫자값 저장할 벡터
    vector<string> words; // 각 단어 저장할 벡터
    vector<pair<char, int>> weight(26); // 각 알파벳과 자릿수 가중치를 저장할 벡터
    
    // 알파벳 초기화 (A~Z)
    for (int i = 0; i < 26; i++) {
        weight[i] = make_pair('A' + i, 0);
    }

    // 입력
    cin >> n;
    words.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        
        // 각 단어의 자릿수에 따른 가중치를 계산하여 저장
        for (int j = 0; j < words[i].length(); j++) {
            weight[words[i][j] - 'A'].second += pow(10, words[i].length() - j - 1); // 알파벳의 자릿수 가중치 저장
        }
    }

    // 가중치가 큰 순서대로 정렬 (별도의 비교 함수 사용)
    sort(weight.begin(), weight.end(), compare);
    
    // 큰 가중치의 알파벳부터 9~0 할당
    for (int i = 0; i < 26; i++) {
        if (weight[i].second > 0) { // 가중치가 0보다 큰 알파벳에만 숫자 할당
            alpha[weight[i].first - 'A'] = num--;
        }
    }

    // 할당된 수들로 각 단어의 값 계산
    for (int i = 0; i < n; i++) {
        string ans = "";
        for (int j = 0; j < words[i].length(); j++) {
            ans += to_string(alpha[words[i][j] - 'A']);
        }
        sum += stoi(ans); // 만들어진 문자열 숫자로 변환해 더하기
    }

    // 출력
    cout << sum;    

    return 0;
}
