#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> clothes_cnt (n+1, 1);
    
    for(int i=0 ; i< lost.size(); i++) {
        clothes_cnt[lost[i]]--;
    }
    
    for(int i=0 ; i< reserve.size(); i++) {
        clothes_cnt[reserve[i]]++;
    }
    
    for(int i=1; i<=n; i++) {
        if(clothes_cnt[i]) { // 체육복>=1. 잃어버린 애 아니면 패스
            continue;
        }
        
        // 체육복 잃어버린 애면
        
        if(clothes_cnt[i-1] == 2) {
            clothes_cnt[i]++;
            clothes_cnt[i-1]--;
        } else if(clothes_cnt[i+1] == 2) {
            clothes_cnt[i]++;
            clothes_cnt[i+1]--;
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(clothes_cnt[i]) {
            answer++;
        }
    }
    
    return answer;
}