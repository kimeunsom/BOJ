#include <iostream>
#include <vector>

using namespace std;


// 그리디 알고리즘 활용 : 늘 가능한 가장 큰 동전 사용하기 !

int cntCoins(vector<int>& coins, int k) {
    int cnt = 0;
    
   for(int i=coins.size()-1 ; i>=0; i--) { // 오름차순으로 정렬된 동전들 금액 큰 순서로 반복 !
       if(coins[i]<=k) { // 현재 남은 금액(k)보다 작은 동전들 중 가장 큰 동전 coins[i] 
           k-=coins[i]; // 남은 금액에서 coin[i]만큼 빼기
           cnt ++ ; // 사용한 동전 개수 +1
           i++; // 현재 동전부터 다음 반복 다시 시작 !
       }
   }
    return cnt;
}

int main()
{
    // 속도 향상 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 선언
    int n, k, temp;
    vector <int> coins; // n개 종류의 동전들 담을 벡터
    
    // 입력
    cin >> n >> k;
    while(n--) {
        cin >> temp;
        coins.push_back(temp);
    }
    
    // 연산 및 출력
    cout << cntCoins(coins, k);
    
    return 0;
}
