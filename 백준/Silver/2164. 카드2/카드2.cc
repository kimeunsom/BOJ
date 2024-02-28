#include <iostream>
#include <queue>

using namespace std;

int card(int n) {
    
    queue<int> q;
    
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    
    int last = q.front();
    int temp;
    
    while(q.size()>1) {
        q.pop(); // 버리기
        
        // 밑으로 넣기
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    
    last = q.front();
    
    return last;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    cout << card(n);

    return 0;
}