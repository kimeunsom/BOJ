#include <iostream>
#include <vector>

using namespace std;

bool check(int n, int m, const vector<int>& light, int h) {
    
    if(light[0] > h) {
        return false;
    }
    
    for(int i=1; i<m; i++) {
        if(light[i]-light[i-1] > 2*h) {
            return false;
        }
    }
    
    if(n-light[m-1] > h) {
        return false;
    }
    
    return true;
}

int binarySearch(int n, int m, const vector<int>& light) {
    int start = 0;
    int end = n;
    int mid;
    int ans = n;
    
    while(start<=end) {
        mid = (start+end)/2;
        
        if(check(n, m, light, mid)) {
            ans = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> light(m);
    for(int i=0; i<m; i++) {
        cin >> light[i];
    }
    
    cout << binarySearch(n, m, light);

    return 0;
}
