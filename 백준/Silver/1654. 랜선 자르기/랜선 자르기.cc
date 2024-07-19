#include <iostream>
#include <vector>

using namespace std;

int cnt(int x, const vector<int>& num) {
    
    long ans = 0;
    
    for(int i=0; i<num.size(); i++) {
        ans += num[i]/x;
    }
    return ans;
}


int solution(const vector<int>& num, int n, long sum) {
    
    long left = 1;
    long right = sum/n; // 토막 가능한 최대 길이
    long mid;
    while(left<=right) {
        
        mid = (left+right)/2;
        
        if( cnt(mid, num) >=n ) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    
    return right;
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    
    int k, n, temp;
    long sum=0;
    cin >> k >> n;
    vector<int> num;
    
    while(k--) {
        cin >> temp;
        sum += temp;
        num.push_back(temp);
    }
    
    // 연산 및 출력
    cout << solution(num, n, sum);
    
    return 0;
}