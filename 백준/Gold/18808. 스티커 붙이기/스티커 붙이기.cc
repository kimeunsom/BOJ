#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k, r, c;
int laptop[40][40] = {0};
int sticker[10][10];

bool check(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 0) continue;
            if (x + i >= n || y + j >= m) return false;
            if (laptop[x + i][y + j]) return false;
        }
    }
    return true;
}

void stick(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j]) {
                laptop[x + i][y + j] = sticker[i][j];
            }
        }
    }
}

void rotation() {
    vector<vector<int>> rotated(c, vector<int>(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rotated[j][r - 1 - i] = sticker[i][j];
        }
    }
    swap(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sticker[i][j] = rotated[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    cin >> n >> m >> k;

    while (k--) {
        int initial_r, initial_c, size = 0;
        cin >> initial_r >> initial_c;
        r = initial_r;
        c = initial_c;

        vector<vector<int>> current_sticker(initial_r, vector<int>(initial_c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> current_sticker[i][j];
                sticker[i][j] = current_sticker[i][j];
                if (sticker[i][j]) size++;
            }
        }

        bool pasted = false;
        for (int rot = 0; rot < 4; rot++) {
            for (int x = 0; x <= n - r; x++) {
                for (int y = 0; y <= m - c; y++) {
                    if (check(x, y)) {
                        ans += size;
                        stick(x, y);
                        pasted = true;
                        goto next_sticker;
                    }
                }
            }
            if (!pasted) {
                rotation();
            }
        }

    next_sticker:;
    }

    cout << ans << endl;

    return 0;
}