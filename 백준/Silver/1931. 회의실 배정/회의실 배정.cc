#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, cnt=0;
    vector<pi> arr;
    
    cin >> n;
    arr.assign(n, {0,0});
    
    for(int i=0; i<n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    
    sort(arr.begin(), arr.end());
    
    int finish_time = 0;
    for(int i=0; i<n; i++) {
        if (finish_time > arr[i].second) {
            continue;
        }
        cnt ++;
        finish_time = arr[i].first;
    }


    cout << cnt;
    
    return 0;
}