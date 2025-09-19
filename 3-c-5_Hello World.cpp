#include <stdio.h>

int main(void)
{
    int x = 1, n = 0;
    while(x <= 2000 && n > 0){

        scanf("%d", &n);
        if(0 < n && n < 10001){
        
        int t = 1, y = 0;
        while(t < n){
            t = t*2;
            y++;
        }
        printf("Case %d: %d\n", x, y);
        x++;
            }
        
    }

    return 0;
}
//x是次數，是case。t是1要乘以2的幾次方才會大於等於n。y是計算次方數，所以也要重置。