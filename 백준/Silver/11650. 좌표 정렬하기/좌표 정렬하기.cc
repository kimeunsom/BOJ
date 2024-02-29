#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> p;

// & : 레퍼런스
// const : 상수

// 비교함수 정의
bool cmp (const p &a, const p &b) {
    
    if(a.first!=b.first) {
        return a.first < b.first;
    }
    
    return a.second < b.second;
    
}

void sortXY(vector<p>& xy) { // 참조를 이용한 전달. 벡터 직접 수정 가능
    
    sort(xy.begin(), xy.end(), cmp);
    
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    vector <p> xy;
    int x;
    int y;
    
    while(n--) {
        cin >> x >> y;
        xy.push_back(make_pair(x,y)); //pair 생성 후 vector에 추가
    }
    
    
    // 연산
    sortXY(xy);
    
    
    // 출력
    for (int i=0; i<xy.size(); i++) {
        cout << xy[i].first << " " << xy[i].second << '\n';
    }
    

    return 0;
}