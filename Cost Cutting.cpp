#include <stdio.h>

int main(void)
{
    int a = 0, b = 0, c = 0, t = 1, l = 0;
    scanf("%d", &l);
    if(l < 20){
    while(t <= l){
        int end = 0;
    scanf("%d%d%d", &a, &b, &c);
        if((a > b && a < c)||(a < b && a > c)){
            end = a;
        }else if((b > a && b < c)||(b < a && b > c)){
            end = b;
        }else if((c > b && c < a)||(c < b && c > a)){
            end = c;
        }else{
            printf("error 001.");
        }
    printf("Case %d: %d\n", t, end);
        t += 1;
    }
}
    return 0;
}