#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    /*Initialization*/

    constexpr int NumMonster = 5;//怪物數量初始化
    constexpr int MonsterBloodNum = 10;//怪物血量上限初始化
    constexpr int SAtk = 7;//單一攻擊傷害值初始化
    constexpr int GAtk = 2;//全體攻擊傷害值初始化
    constexpr int MSheal = 1;//怪物回復血量數值初始化
    constexpr int MShealThreshold = 3;//怪物判定回復血量的閾值初始化
    constexpr int MSAtk = 1;//怪物攻擊數值初始化
    constexpr int MSCbAtk = 3;//怪物連續攻擊數值初始化
    int monster[NumMonster] = {};//初始化每隻怪物的血量條
    for(int i = 0; i < NumMonster;i += 1){ monster[i] = MonsterBloodNum; }//讓每隻怪物的血量條儲存為上限的值

    //--------------Game starts-------------------
    int dieMnow = 0;//當前怪物死亡數量初始化
    int PlayerLife = 30;//玩家血量初始化
    srand(time(0));
    while(dieMnow < NumMonster && PlayerLife > 0)//只要有怪物和玩家都活著，迴圈繼續。當死亡怪物數等於怪物數量時跳出迴圈；當玩家血量<=0時跳出迴圈，也就是打贏或打輸才會脫出
    {
        /*------------show game state-------------*/
        system("cls");//清屏
        printf("*** Monster Hunting Game ***\n\n");//遊戲名稱

        for(int j = 0;j < NumMonster; j += 1 )//顯示怪物狀態列，從0開始對應陣列的index
        {
            if(monster[j] > 0){//以該怪獸血量條判斷是否存活，若活
                printf("Monster %d(%d) ", j+1, monster[j]);//當前外層for迴圈的執行次數對應第幾隻怪獸，顯示時j+1才正確，monster[j]表示對應的血量條。
                for( int i = 0;i < monster[j];i += 1)//印出*表示血量，從1印到該怪獸血量條的數值
                {
                    printf("*");
                }
            }
            else//若死亡
            {
                printf("Monster %d -DEAD-", j+1);
            }
            printf("\n");//一隻怪獸狀態顯示結束後換行到下一隻怪物狀態
        }
        printf("\n");//多空一行

        printf("Player's life: (%d) ", PlayerLife);//當前當前玩家的血條。
        for( int i = 0;i < PlayerLife;i += 1)//印出*表示血量，從1印到玩家血條的數值
        {
            printf("*");
        }
        printf("\n\n");//多空2行
        int r1 = rand();
        int r2 = r1/10;

        /*------------Player's turn----------------*/
        int choiceATK = 0;
        printf("It's your turn :(1)single attack(%dP) (2)group attack(%dP)...>", SAtk, GAtk);
        scanf("%d", &choiceATK);//選擇攻擊方式
        
        if(choiceATK == 1)
        {
            int choiceMNo = 0;
            printf("Which monster do you want to attack?...>");
            scanf("%d", &choiceMNo);//為單一攻擊選擇目標

            if(choiceMNo < 1 || choiceMNo > NumMonster)//判定是否選擇目標為無效值
            {
                printf("Invalid target!\n");
            }else if(monster[choiceMNo - 1] <= 0){//
                printf("It's already dead, please don't hit it.\n");
            }else{//normal attack
                if(r1%100 < 20)//失誤判定20%
                {
                    printf("Missed! You do not hit Monster %d.\n", choiceMNo);
                }
                else
                {
                    monster[choiceMNo-1] -= SAtk;//為該目標減去單一攻擊的傷害值，這裡直接存取血量條，因此要-1才會對應到正確的陣列index
                    printf("You hit monster %d by %d points!\n", choiceMNo, SAtk);
                }
            }


            
        }
        else if(choiceATK == 2)
        {
            for(int i = 0;i < NumMonster;i += 1)
            {
                monster[i] -= GAtk;

            }//為每一隻怪獸減去全體攻擊的傷害值//原本將i設成1會導致第一隻怪獸的血條不被扣到
            printf("You hit every monster by %d points!\n", GAtk);
        }
        system("pause");
        //---------------enemies's turn-------------
        for(int i = 0;i < NumMonster;i += 1)//第i隻怪獸的回合，先判斷是否要Heal，否則Attack玩家
        {
            int MSchoice = 0;//怪物選擇變數初始化
            //monster heal
            for(int j = 0;j < NumMonster;j += 1)//對第j隻怪獸判定是否要回復
            {
                if(monster[j] <= MShealThreshold && monster[j] > 0 && monster[i] > 0)//若第j隻怪獸<=治療判定閾值&&第j隻怪獸血條大於0&&第i隻怪獸還活著才能補，死了還能復活就打不完，死了還能回復也打不完
                {
                    monster[j] += MSheal;//第j隻怪物血條加"怪物回復數值"
                    printf("Monster %d heals monster %d by %d.\n", i+1, j+1, MSheal);
                    MSchoice = 1;//將怪物選擇設為1
                    break;//第i隻怪獸對第j隻怪獸使用回復一次後脫離迴圈。
                }
            }
            //monster attack
            if(MSchoice == 0 && monster[i] > 0)//第i隻怪物沒有選擇回復&&血條也要大於0，則進行攻擊
            {
                if(r2%100 < 10)//怪物連擊判定10%
                {
                    PlayerLife -= MSCbAtk;
                    printf("Combo hit! Monster %d hits you by %d points!\n", i+1, MSCbAtk);
                }
                else
                {
                    PlayerLife -= MSAtk;//"玩家血量"減掉"怪物攻擊數值"
                    if(PlayerLife < 0)
                        PlayerLife = 0;
                    if(MSAtk > 1){
                        printf("Monster %d hits you by %d points!\n", i+1, MSAtk);
                    }else if(MSAtk == 1){
                        printf("Monster %d hits you by %d point!\n", i+1, MSAtk);
                    }
                }
                
            }
            if(PlayerLife <= 0)
            {
                break;
            }
        }        

        // ---------- Stopping criterion ---------
        system("pause");
        
        //怪獸死亡判定
        int dieMC = 0;//怪獸死亡計數
        for(int i = 0;i < NumMonster;i += 1)//檢測每一隻怪獸的血量//我原本是i設1，但那樣就會跳過第一隻怪獸的血條，永遠到不了怪獸數量
        {
            if(monster[i] <= 0)//如果血量<=0，判定為死亡，dieM設為1，dieMC值+1，
            {
                dieMC += 1;//怪獸死亡計數+1
            }
        }
        dieMnow = dieMC;//把剛數完的怪獸死亡數，給到外面的當前怪獸死亡數。
    }

    //--------------------Game ends----------------------
    if(dieMnow == NumMonster)
    {
        printf("\nYou have killed ALL monsters!!!!\n");
    }
    else if(PlayerLife <= 0)
    {
        printf("Oh no, you are killed.\n");
    }else{
        printf("error:accident break loop.\n");
    }

    system("pause");

    return 0;
}