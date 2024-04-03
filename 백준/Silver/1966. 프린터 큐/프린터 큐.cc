#include <iostream>
#include <queue>

using namespace std;

// 큐에서 우선순위 가장 큰 값 찾아주기
int findMax(queue<int> prior) {
    
    int max_value = 0;
    
    while(!prior.empty()) {
        
        if(prior.front()%10 > max_value) 
                max_value=prior.front()%10;
        
        prior.pop();
    }
    return max_value;
}


int solution(queue<int>& prior) {
    

    int front;
    int cnt = 0;
    
    int max_value = findMax(prior);
    
    while(true) {

        // 우선순위 가장 큰 애가 맨 앞에 오면 pop !
        if(prior.front()%10 == max_value) {
            
            if(prior.front() > 10) { // m번째 수가 빠질 차례랴면,
                cnt ++ ;
                break;
            }
            prior.pop();
            cnt ++;
            max_value = findMax(prior);
        } 
        else {
            front = prior.front();
            prior.pop();
            prior.push(front);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, n, m, temp;
    cin >> t;

    while(t--) {
        
        cin >> n >> m;
        queue<int> prior;
        
        for(int i=0; i<n; i++) {
            cin >> temp;
            if(i == m) 
                temp+=10; // 출력을 확인해야 하는 m번째 수에는 10을 곱해 표시해둠.
            prior.push(temp);
        }
        cout << solution(prior) << "\n";
    }

    return 0;
}