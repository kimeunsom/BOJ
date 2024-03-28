#include <iostream>
#include <vector>

using namespace std;

int cntCoins(vector<int>& coins, int k) {
    int cnt = 0;
    
   for(int i=coins.size()-1 ; i>=0; i--) {
       if(coins[i]<=k) {
           k-=coins[i];
           cnt ++ ;
           i++;
       }
   }
   
    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k, temp;
    vector <int> coins;
    
    // 입력
    cin >> n >> k;
    while(n--) {
        cin >> temp;
        coins.push_back(temp);
    }
    
    
    cout << cntCoins(coins, k);
    
    
    
    
    return 0;
}