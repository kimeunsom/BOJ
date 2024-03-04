#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int isPrime (int n, int k) {
    
    int cnt=0; 
    vector<bool> is_prime (n+1, true);
    
    for(int i=2; i<=n; i++) {
        if(!is_prime[i]) { //소수 아닌걸로 이미 지워졌다면 건너뛰기 !
            continue;
        } 
        
        // 배수 지우기
        for(int j=i; j<=n; j+=i) {
                
            if(is_prime[j]) { //아직 안지워졌으면 지우고 cnt++
                is_prime[j]=false;
                if((++cnt)==k) return j;
            } 
            
            else {
                continue;
            }
        }    
    }
    
    return -1;
    
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k ;
    
    
    cout << isPrime(n, k);

    return 0;
}