#include <stdio.h>

int main(void)
{
    int t = 0, x = 0, y = 0;
    scanf("%d", &t);
    if(t < 15){
        int a = 0;
        while(a < t)
        {
            scanf("%d%d", &x, &y);
            if(x < y){
                printf("<\n");
            }else if(x == y){
                printf("=\n");
            }else if(x > y){
                printf(">\n");
            }
            a += 1;
        }
    }else{
        printf("you enter too many times.");
    }

    return 0;
}