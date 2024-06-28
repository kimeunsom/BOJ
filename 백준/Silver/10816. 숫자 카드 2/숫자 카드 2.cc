#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//lower bound (타겟이 처음으로 나온 위치) 찾기 
int lowerBound(int key, const vector<int> &arr, int n) {
    int left = 0;
    int right = arr.size() - 1;
    int mid ;
    
    while(left <= right) {
        mid = (left+right)/2;
            
        
        if(arr[mid] < key) { 
            left = mid + 1;
        } else { //왼쪽으로
            right = mid -1;
            //키값 찾아도 (mid == key) 일단 의심하며 왼쪽으로 더 가보기 !
        }
    }
    
    return left;
}

//upper bound (타겟이 처음으로 초과된 위치) 찾기 
int upperBound(int key, const vector<int> &arr, int n) {
    int left = 0;
    int right = arr.size() - 1;
    int mid ;
    
    while(left <= right) {
        mid = (left+right)/2;
            
        
        if(arr[mid] <= key) { 
            left = mid + 1;
            //키값 찾아도 (mid == key) 일단 의심하며 오른쪽으로 더 가보기 !

        } else { //왼쪽으로
            right = mid -1;
        }
    }
    
    return left;
}

int main()
{

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n,m,t;
    vector <int> arr;
    cin >> n;
    
    while(n--) {
        cin >> t ;
        arr.push_back(t);
    }
    
    
    //이분탐색은 우선, 정렬 필수 !!
    sort(arr.begin(), arr.end());
    
    
    cin >> m ;
    
    while(m--) {
        
        cin >> t;
        cout << upperBound(t, arr, n) - lowerBound(t, arr, n) << '\n';
    }
    
    return 0;
}