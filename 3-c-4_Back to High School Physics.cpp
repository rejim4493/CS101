/*
A particle has initial velocity and acceleration. If its velocity after certain time is v then what will its
displacement be in twice of that time?
Input
The input will contain two integers in each line. Each line makes one set of input. These two integers
denote the value of v (−100 ≤ v ≤ 100) and t (0 ≤ t ≤ 200) (t means at the time the particle gains
that velocity)
Output
For each line of input print a single integer in one line denoting the displacement in double of that time.
Sample Input
0 0
5 12
Sample Output
0
120
*/

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

