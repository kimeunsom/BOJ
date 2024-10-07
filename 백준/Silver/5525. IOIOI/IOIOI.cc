#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, cnt = 0;
    string p = "I";
    string s;
    
    cin >> n >> m >> s;
    
    // Pn 생성하기
    while(n--) {
        p += "OI";
    }
    
    // 한칸씩 움직이며 다 확인 ...
    for(int i=0; i<=s.length()-p.length(); i++) {
        string sub_str = s.substr(i, p.length());
        if(sub_str == p) {
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}