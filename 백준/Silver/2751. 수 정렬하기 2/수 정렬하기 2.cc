#include <iostream>

using namespace std;

int temp[1000001];
int arr[1000001];


// 합치는 함수
void merge(int left, int right) {
    int mid = (left+right)/2;
    
    int pl = left, pr = mid; // 배열 두개를 찍을 포인터 변수
    
    for(int i=left; i<right; i++) {
        if(pl == mid) temp[i] = arr[pr++];
        else if(pr == right) temp[i] = arr[pl++];
        else if(arr[pl] <= arr[pr]) temp[i] = arr[pl++];
        else temp[i] = arr[pr++];
    }
    
    // 배열 복사
    for(int i=left; i<right; i++) arr[i] = temp[i];
}

// 정렬하는 함수
void mergeSort(int left, int right) {
    if(right-left<=1) return; // 쪼갠 배열 사이즈가 1이하면 리턴
    int mid = (left+right)/2;
    
    mergeSort(left, mid);
    mergeSort(mid, right);
    
    merge(left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> arr[i];
    
    mergeSort(0, n);
    
    for(int i=0; i<n; i++) cout << arr[i] << "\n";
    
    return 0;
}