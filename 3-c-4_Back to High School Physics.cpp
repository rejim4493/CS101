#include <stdio.h>

int main(void)
{
    int v = 0, t = 0;
    //scanf("%d%d", &v, &t);判別式裡的scan也會作用，不必多打一次
    while(scanf("%d%d", &v, &t) == 2){
    if(-100 <= v && v <= 100 && 0 <= t && t <= 200){
        printf("%d\n", 2*v*t);
    }else{
        printf("error number\n");
    }
    }
    return 0;
}
