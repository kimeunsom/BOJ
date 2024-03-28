#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cntOfCmp(priority_queue<int, vector<int>, greater<int>> cards) {
    
    int cnt = 0;
    int x, y;
    
    while( cards.size()>1 ) {
        
        // 가장 작은 값 2개 뽑기
        x = cards.top();
        cards.pop();
        
        y = cards.top();
        cards.pop();
        
        cnt += (x+y);
        cards.push(x+y);
    }

    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, temp;
    priority_queue< int, vector<int>, greater<int> > cards; //최소힙
    cin >> n;
    
    while(n--) {
        cin >> temp;
        cards.push(temp);
    }
    
    cout << cntOfCmp(cards);
    

    return 0;
}