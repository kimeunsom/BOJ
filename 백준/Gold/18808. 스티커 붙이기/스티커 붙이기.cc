#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, r, c;
int laptop[40][40] = {0}; // 노트북 ; 명시적 초기화
int sticker[10][10]; // 스티커

// 스티커 붙일 수 있는지 체크
bool check(int x, int y) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(sticker[i][j]==0) continue; // 스티커 안붙은 곳은 패스
            if(x+i >= n || y+j >= m) return false; // 범위 밖으로 빠져나감.
            if(laptop[x+i][y+j]) return false; // 이미 붙어있던 스티커와 겹침.
        }
    }
    return true;
}

// 스티커 노트북에 붙이기.
void stick(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j]) {
                laptop[x + i][y + j] = sticker[i][j];
            }
        }
    }
}

// 스티커 90도 회전
void rotation() {
    int rotated[10][10];
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            rotated[j][r-i-1] = sticker[i][j]; // 열, r-1-행 ; 90도 회전.
        }
    }
    
    swap(r, c); // 행과 열도 바꾸기.
    
    // 회전한 배열 원본에 덮어쓰기
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sticker[i][j] = rotated[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int ans = 0;
    cin >> n >> m >> k;
    
    while(k--) {
        int size = 0; // 스티커 크기
        cin >> r >> c;
        
        // 스티커 배열 초기화.
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                sticker[i][j] = 0;
            }
        }
        
        // 스티커 입력받기
        for(int i=0; i<r; i++) { 
            for(int j=0; j<c; j++) {
                cin >> sticker[i][j];
                if(sticker[i][j]) size++; // 스티커 크기
            }
        }

        for(int rot=0; rot<4; rot++) {
            for(int x=0; x<n; x++) { // 스티커 놓을 시작점 x,y
                for(int y=0; y<m; y++) {
                    if(check(x, y)) { // 시작점 x,y에서 스티커 놓을 수 있는지 체크
                        ans += size; // 해당 스티커 크기만큼 채워짐.
                        stick(x, y); // 노트북에 스티커 붙은 위치 표시
                        goto next_sticker;
                    }
                }
            }
            rotation();
        }
        
        
        next_sticker:;
    }
    
    cout << ans;
    
    return 0;
}