#include <stdio.h>

int main()
{
    int n,k;
	int ans=0;
    int count=0;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int j=n-1;
    
    while(ans!=k) {
        if(arr[j]<=k-ans) {
            ans+=arr[j];
            count++;
            j=n-1;
        } else {
            j--; 
        }
        
    }
    
    printf("%d", count);
    
    return 0;
}
