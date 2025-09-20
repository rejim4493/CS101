/*
For a positive integer n, let f(n) denote the
sum of the digits of n when represented in base
10. It is easy to see that the sequence of numbers n, f(n), f(f(n)), f(f(f(n))), . . . eventually
becomes a single digit number that repeats forever. Let this single digit be denoted g(n).
For example, consider n = 1234567892.
Then:
f(n) = 1+2+3+4+5+6+7+8+9+2 = 47
f(f(n)) = 4 + 7 = 11
f(f(f(n))) = 1 + 1 = 2
Therefore, g(1234567892) = 2.
Input
Each line of input contains a single positive integer n at most 2,000,000,000. Input is terminated
by n = 0 which should not be processed.
Output
For each such integer, you are to output a single
line containing g(n).
Sample Input
2
11
47
1234567892
0
Sample Output
2
2
2
2
*/

#include <stdio.h>

int main(void)
{
    int n = 1;
    while(n != 0){
        scanf("%d", &n);
        if(n != 0){
            int sum = 10;
            while(sum >= 10){
                sum = 0;
                while(n > 0){
                    sum += n % 10;
                    n /= 10;
                }
                n = sum; 
            }
            printf("%d\n",n);
        }
    }
    return 0;
}

/*
教訓：
sum宣告要放對位子，不能在最外面，要考慮到讓他能進while又符合計算需求。
計算完加總回去要加=，44行

思考流程：
先做出一次加總位數的while迴圈line 42，利用取10的餘數得到個位數，將n除10，以在下一輪計算取得十位數。
第二層while加總直到小於10為止，要先指定sum為0，避免殘值。計算完要將sum指定給n，再用sum判斷是否已是小於10，是就脫出迴圈，接著印出結果。否則清空sum，以上一輪計算得到的n做下一次運算。
38行if是確認若n為0直接跳過，回到while判斷後脫出迴圈。加是因為避免印出0，題目要的是直接終止而不輸出結果。
*/
