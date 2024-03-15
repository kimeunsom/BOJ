#include <stdio.h>

int main()
{
    int n=0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        
        for(int i=1; i<=n; i++) {
        if(i%2==0) {
            printf(" ");
        } else {
            printf("*");
        }
        }
        printf("\n");
    
    for(int i=1; i<=n; i++) {
        if(i%2!=0) {
            printf(" ");
        } else {
            printf("*");
        }
        }
        printf("\n");
        
    }
    
    
    

    return 0;
}
