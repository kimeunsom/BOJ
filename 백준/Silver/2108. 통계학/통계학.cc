#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findMode(const vector<int>& num, int max_length) {
    
    if(num.size() == 1) return num[0]; // 값이 하나뿐이면 그 값이 최빈값
    
    int mode;
    int l=0;
    bool finded = false;
    int start = 0;
    int end = 0;
    
    for(int i=0; i<num.size()-1; i++) {
        
        
        if(num[i] != num[i+1]) {
            end = i+1;
            l = end - start ; // 동일 숫자 부분 수열 길이
        }
        
        else if (i==num.size()-2) l = num.size()-start; // 가장 끝의 부분수열 길이
        
        if (l == max_length) { // 수열 길이가 최빈값의 수열 길이와 같다면,
            mode = num[i]; // 현재값은 최빈값이므로 저장

           if(finded) return mode; // 만약 이전에도 최빈값이 발견되었다면, 현재가 두번째로 작은 최빈값
            finded = true; // 아직 리턴 안됐다면, finded를 true로 태그
        }
        start = end; // 시작점 갱신
        l=0;
    }
    
    return mode;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, temp, avg, median, mode, range;
    vector<int> num; 
    vector<int> cnt(8001, 0); // 8001칸 0으로 초기화
    
    cin >> n;
    int sum = 0;
    int max = -4000;
    int min = 4000;
    int cnt_max = 0; // 최빈값 찾는 데 쓸 변수
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        if(min>temp) min = temp;
        if(max<temp) max = temp;
        
        num.push_back(temp);
        sum += temp;
        
        cnt[temp+4000]++;
        if(cnt_max < cnt[temp+4000]) cnt_max = cnt[temp+4000]; // 최빈값 횟수 갱신
    }

    sort(num.begin(), num.end()); // 벡터 오름차순 정렬

    // 평균, 중앙값, 최빈값, 범위 연산
    avg = round( (double)sum / n );
    median = num[n/2];
    mode = findMode(num, cnt_max);
    range = max-min;
    
    cout << avg << "\n" << median << "\n" << mode << "\n" << range;
    
    return 0;
}