/*Some operators checks about the relationship between two values and these operators are called relational operators. Given two numerical values your job is just to find out the relationship between them
that is (i) First one is greater than the second (ii) First one is less than the second or (iii) First and
second one is equal.
Input
First line of the input file is an integer t (t < 15) which denotes how many sets of inputs are there.
Each of the next t lines contain two integers a and b (|a|, |b| < 1000000001).
Output
For each line of input produce one line of output. This line contains any one of the relational operators
‘>’, ‘<’ or ‘=’, which indicates the relation that is appropriate for the given two numbers.
Sample Input
3
10 20
20 10
10 10
Sample Output
<
>
=
*/

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
/*
題目要求先輸入總共要執行幾次，用t代表，最高不超過15次。重複執行，在迴圈末段以a計算當前次數，直至a等於t即停止。
每次迴圈都要求輸入兩個整數x,y，利用if...else判斷x和y的大小關係，輸出對應的比較符號。若輸入欲執行次數超過15次，則跳至警告並結束程式。
*/
