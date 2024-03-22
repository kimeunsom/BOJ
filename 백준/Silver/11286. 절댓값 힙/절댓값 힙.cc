#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const int& x1, const int& x2) {
        if(abs(x1) != abs(x2)) {
            //절댓값 다른경우 절댓값이 작은 수에 우선순위 부여
            return abs(x1) > abs(x2);
        }
        
        // 절댓값 같으면 작은 수에 우선순위 부여
        return x1 > x2;
    }
};

int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n , x ;
    priority_queue <int, vector<int>, cmp> pq; //최소힙
    
    cin >> n;
    
    
    while(n--) {
        cin >> x;
        
        if(x) {
            pq.push(x);
        } 
        
        else {
            
            //pq가 비어있는 경우 0 출력
			if (pq.empty()) { 
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
        }
    }
    
    return 0;
}