#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int flag = true; // 선물 받는지 여부
    
    for(int i=0; i<schedules.size(); i++) {
        flag = true;
        for(int j=0; j<7; j++) {
            
            int current_day = (startday + j - 1) % 7 + 1; // 현재 요일
            if(current_day==6 || current_day==7) continue; // 주말은 패스
            
            int due = schedules[i]+10;
            if( due%100 >= 60) { // 받아올림 해야 하는 경우
                due = due + 100 - 60;
            }
            
            if( due < timelogs[i][j]) { // 선물 못 받음
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}