#include <iostream>
#include <vector>

using namespace std;

bool isOutOfBound(char x, char y) {
    return (x < 'A' || x > 'H' || y < '1' || y > '8');
}

int BF(int n, string& k, string& d, const vector<string>& moveD) {
    string lastK = k, lastD = d;

    for (int i = 0; i < n; i++) {
        lastK = k;
        lastD = d;

        // 킹의 이동
        if (moveD[i] == "T") k[1]++;
        else if (moveD[i] == "R") k[0]++;
        else if (moveD[i] == "B") k[1]--;
        else if (moveD[i] == "L") k[0]--;
        else if (moveD[i] == "RT") { k[0]++; k[1]++; }
        else if (moveD[i] == "RB") { k[0]++; k[1]--; }
        else if (moveD[i] == "LB") { k[0]--; k[1]--; }
        else if (moveD[i] == "LT") { k[0]--; k[1]++; }

        // 킹이 범위를 벗어난 경우
        if (isOutOfBound(k[0], k[1])) {
            k = lastK;
            continue;
        }

        // 킹이 돌의 위치로 이동한 경우
        if (k == d) {
            // 돌도 같은 방향으로 이동
            d[0] += (k[0] - lastK[0]);
            d[1] += (k[1] - lastK[1]);

            // 돌이 범위를 벗어난 경우
            if (isOutOfBound(d[0], d[1])) {
                d = lastD;
                k = lastK;
                continue;
            }
        }
    }

    return 0;
}

int main() {
    int n;
    string k, d;
    vector<string> moveD;
    string temp;

    // 입력
    cin >> k >> d >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        moveD.push_back(temp);
    }

    // 연산
    BF(n, k, d, moveD);

    // 출력
    cout << k << '\n' << d;

    return 0;
}
