#include <stdio.h>


int main()
{
    int n=0;
    int window=0;
    scanf("%d", &n);
    
    int i=1;
    
    while(i*i<=n) {
        window++;
        i++;
    }
    
    printf("%d",window);
    
    return 0;
}
