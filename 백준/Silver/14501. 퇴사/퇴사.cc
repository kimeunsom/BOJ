#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> p;

int solution(int n, vector<p>& list ) {
    
    vector<int> v(n, 0); // i일의 최대 수익
    
    for(int i=0; i<n; i++) {
        if( i + list[i].first > n ) {
            list[i].second = 0;
        }
    }
    
    for(int i=0; i<n; i++) {
        v[i] = list[i].second;
    }
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if( i - j >= list[j].first ) { // i번째 상담이 가능한 경우,
                v[i] = max(v[i], v[j] + list[i].second);
            }
        }
    }
    
    int max = 0;
    for(int i=0; i<n; i++) {
        if(v[i]>max) {
            max = v[i];
        }
    }

    return max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<p> list(n, p(0,0));
    
    for(int i=0; i<n; i++) {
        cin >> list[i].first >> list[i].second;
    }
    
    cout << solution(n, list);

    return 0;
}