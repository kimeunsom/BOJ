#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket; // 바구니
    int picked; // 현재 크레인이 집은 인형
    
    for(int i=0; i<moves.size(); i++) {
        picked = 0; // 집은 인형 초기화
        for(int j=0; j<board[0].size(); j++) {
            if( board[j][moves[i]-1]==0 ) continue; // 인형 없으면 다음 행으로
            picked = board[j][moves[i]-1]; // 인형 집기
            board[j][moves[i]-1] = 0; // 집고 남은 자리에 빈곳 표기
            break;
        }
        
        if(picked == 0) continue; // 인형 집지 못함. 다음 루프로
        
        if (!basket.empty() && basket.top() == picked) { // 뽑으려는 애랑 바구니 상단의 인형이 같을 때
            answer+=2; // 사라진 인형개수 2개 추가
            basket.pop(); // 바구니 상단 인형 제거
        } else { // 터지지 않았다면 바구니에 그냥 인형 투입
            basket.push(picked);
        }
    }
    return answer;
}