#include <iostream>
#include <vector>

using namespace std;

// n 이하의 소수 모두 찾기
void findPrime(int n, vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false;
    
    for(int i=2; i*i<=n; i++) {
        
        if(is_prime[i]) {
            // 아직 안지워졌다면, 소수 ! 
            // 배수 지우기
            for(int j=i*i; j<=n; j+=i) {
                is_prime[j]=false;
            }       
        }
        
        else {
            // 이미 지워졌다면, 다음 !
            continue;
        }
        
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    
    // 입력
    cin >> m >> n;
    vector<bool> is_prime(n+1, true); // 크기 n인 벡터

    
    
    // 연산
    findPrime(n, is_prime);
    
    
    
    
    // 출력
    for(int i=m; i<=n; i++) {
        if(is_prime[i]) {
            cout << i << '\n';
        }
    }
    
    return 0;
}