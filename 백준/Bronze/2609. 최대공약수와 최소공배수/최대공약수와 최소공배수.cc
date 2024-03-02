#include <stdio.h>

int main(){
    int A, B;
    int min, max;

    scanf("%d %d", &A, &B);

    
    
    for(int i=1; i<=A || i<B; i++){

        if(A%i==0 && B%i==0){
            max=i;
        }
    }

    int a = A/max;
    int b = B/max;
    min = max*a*b;

    printf("%d\n", max);
    printf("%d", min);

    return 0;
}