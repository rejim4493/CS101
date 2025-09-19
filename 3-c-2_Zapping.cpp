#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, t = 0;
    while(t < 200){
    
    scanf("%d%d", &a, &b);
    if(a >= 0 && a <= 99 && b >= 0 && b <= 99){
        int x = 0;
        if(a < b){
            x = b-a;
        }else if(a > b){
            x = a-b;
        }
        if(x > 50){
            x = 100-x;
        }
        printf("%d\n", x);
        }
        t += 1;
    }
    return 0;
}
