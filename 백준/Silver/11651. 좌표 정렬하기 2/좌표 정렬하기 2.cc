#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> p;

bool compare (const p &a, const p &b) {
    
    if(a.second != b.second) { // y 좌표가 다른 경우,
        return a.second < b.second; // 작은 값이 앞에 오면 참이 되도록 (y 오름차순)
    } 
    else { // y 좌표가 똑같은 경우
        return a.first < b.first; // 더 작은 x가 앞에 오도록 (x 오름차순) 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    p temp;
    vector<p> xy; // 좌표 저장할 페어타입 벡터
    
    // 입력
    cin >> n;
    while(n--) {
        cin >> temp.first >> temp.second;
        xy.push_back(temp);
    }
    
    // 연산
    sort(xy.begin(), xy.end(), compare); // 비교함수 활용해 좌표 정렬
    
    // 출력
    for(int i=0; i<xy.size(); i++) {
        cout << xy[i].first << " " << xy[i].second << "\n";
    }

    
    return 0;
}