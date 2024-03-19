#include <iostream>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n, x;
    cin >> n;
    priority_queue <int> max_heap;
    
    
    while(n--) {
        cin >> x;

        
        if(x) {
            // 삽입
            max_heap.push(x);
        } 
        
        else {
            
            //비어있다면 0 출력
            if(max_heap.empty()) {
                cout << "0\n";
            } 
            
            // 삭제
            else {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
            
        }
    }

    return 0;
}