#include <stdio.h>

int main(void)
{
    int n = 1;
    while(n != 0){
        scanf("%d", &n);
        int sum = 0;
        while(n >= 10){
            sum += n % 10;
            n / 10;
        }
        n = sum;
        printf("%d",n);
    }
    return 0;
}