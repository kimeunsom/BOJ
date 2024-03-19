#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n, temp;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    
    cin >> n; 
    
    for(int i=0; i<n; i++) {
        cin >> temp;
        
        
        if(i==0) { 
            maxHeap.push(temp);
            cout << maxHeap.top() << "\n";
            continue;
        }
        
        
        if( temp < maxHeap.top()) {
            maxHeap.push(temp);
        } else {
            minHeap.push(temp);
        }
        
        
        if( maxHeap.size() > minHeap.size() +1 ) { 
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if ( minHeap.size() > maxHeap.size() ) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

       
        if(i%2 == 0) {
            cout << min(maxHeap.top(), minHeap.top()) << "\n";
        } 
        
        else {
            cout << maxHeap.top() << "\n";
        }
    }
    
    
    

    return 0;
}