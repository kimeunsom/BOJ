#include <iostream>
#include <vector>

using namespace std;


int check(int x, int y, const vector<vector<char>>& bw, char ch) {
    int cnt_change = 0;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            
            if(i%2 == 0 && j%2==0) { // 둘다 짝수
                if(bw[x+i][y+j]==ch) continue;
            } 
            
            else if (i%2 == 1 && j%2==1){ // 둘 다 홀수
                if(bw[x+i][y+j]==ch) continue;
            } 
            
            else { // 이외의 경우
                if(bw[x+i][y+j]!=ch) continue;
            }
            
            cnt_change++; // 위에 해당하는 올바르게 배치된 경우가 아니면, 바꿔야하는 횟수 +1
        }
    }
    
    return cnt_change;
}


int findMinChange(int n, int m, const vector<vector<char>>& bw) {
    int cur_min = 0;
    int last_min = 8*8+1;
    
    for(int y=0; y<=m-8; y++) {
        for(int x=0; x<=n-8; x++) {
            
            // 좌표 x,y부터 8x8 칸에 바꿔야하는 최소 갯수
            cur_min = min(check(x, y, bw, 'B'), check(x, y, bw, 'W'));
            
            // last_min 갱신
            if(cur_min < last_min) {
                last_min = cur_min;
            }   
        }
    }
    
    return last_min;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, x;
    string str; 
    
    cin >> n >> m ;
    
    vector<vector<char>> bw (n, vector<char>(m));
    
    // 체스판 입력받기
    for(int j=0; j<n; j++) {
        cin >> str;
        for(int i=0; i<m; i++) {
            bw[j][i] = str[i];
        }
    }
    
    cout << findMinChange(n, m, bw);

    return 0;
}