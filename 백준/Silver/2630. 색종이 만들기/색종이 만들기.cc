#include <iostream>

using namespace std;

int n, white, blue;
int map[128][128];

bool isSameColor(int x, int y, int size, int color) {
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(color == map[i][j]) continue;
            return false; // 중간에 다른 색 껴있음.
        }
    }
    return true;
}


void func(int x, int y, int size) {
    int color = map[x][y];
    
    if(isSameColor(x, y, size, color)) { // 모든 색이 같은 온전한 색종이가 완성됐다면,
        if(color) {
            blue++;
        } else {
            white++;
        }
        return; // 더이상 4등분 안 해도 됨. 종료 !
    }
    
    int new_size = size/2; // 4등분
    func(x, y, new_size);
    func(x+new_size, y, new_size);
    func(x, y+new_size, new_size);
    func(x+new_size, y+new_size, new_size);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    
    func(0, 0, n);
    
    cout << white << "\n" << blue;

    return 0;
}