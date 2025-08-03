#include <stdlib.h>
#include<time.h>
#include <cs50.h>
#include<stdio.h>
//add a score multiplier system
void play_scrn(void);
void start_egame(void);
void start_fgame(void);
int difficulty(void);
int hcdifficulty(void);
void clear_screen(void);
int score_multiplier(int qcount);
int update_score(int score,int hscore);
int no_of_question_in_fgame(int maxNum);
void display_difficulty(int maxNum,int qcount);

int main(void)
{
    srand(time(NULL));
    play_scrn();
}

void display_difficulty(int maxNum,int qcount)
{
    if(maxNum==20)
    {
        printf("🟢EASY🟢                              Q:%i\n",qcount);
    }
    else if (maxNum==100)
    {
        printf("🟠MEDIUM🟠                            Q:%i\n",qcount);
    }
    else
    {
        printf("🔴HARD🔴                              Q:%i\n",qcount);
    }
}

void hardcore(int maxNum)
{
    int qcount=0;
    int score=0;
    static int hscore=0;
    while(true)
    {
        clear_screen();
        int num1=rand()%maxNum;
        int num2=rand()%maxNum;
        int num3=rand()%maxNum;
        int crrctans=num1+num2-num3;
        printf("👹 !HARDCORE! 👹                      Q:%i\n",qcount);
        printf("                                      High Score:%i\n",hscore);
        printf("                                      Score:%i\n",score);
        qcount++;
        printf("%i+%i-%i? = ",num1,num2,num3);
        int ans=get_int("");

        if (ans==crrctans)
        {
            printf("✅Correct!\n");
            score+=10;
            score+=score_multiplier(qcount);
            if (qcount!=0 && qcount%10==0)
            {
                printf("🔥 BONUS! +50 points for reaching Q:%i!\n", qcount);
            }
            hscore=update_score(score,hscore);
        }
        else if(ans!=crrctans)
        {
            printf("\a💀GAME OVER💀\n");
            hscore=update_score(score,hscore);
            printf("High score:%i\n",hscore);
            score=0;
            return;
        }
    }
}
int difficulty(void)
{
    clear_screen();
    int maxNum;
    char diff;
    while(true)
    {
        printf("         SELECT DIFFICULTY\n");
        printf("(E)asy🟢      (M)edium🟠     (H)ard🔴\n");
        diff=get_char(": ");
        if (diff=='e' || diff=='E')
        {
            maxNum=20;
            return maxNum;
        }
        else if (diff=='m' || diff=='M')
        {
            maxNum=100;
            return maxNum;
        }
        else if (diff=='h' || diff=='H')
        {
            maxNum=1000;
            return maxNum;
        }
        else
        {
            printf("Enter a valid input\n");
        }
    }
}
int hcdifficulty(void)
{
    int maxNum;
    char diff;
    while(true)
    {
        clear_screen();
        printf("             SELECT DIFFICULTY\n");
        printf("(E)asy🟢      (M)edium🟠     (H)ard🔴     Hard(C)ore👹\n");
        diff=get_char(": ");
        if (diff=='e' || diff=='E')
        {
            maxNum=20;
            return maxNum;
        }
        else if (diff=='m' || diff=='M')
        {
            maxNum=100;
            return maxNum;
        }
        else if (diff=='h' || diff=='H')
        {
            maxNum=500;
            return maxNum;
        }
        else if (diff=='c' || diff=='C')
        {
            maxNum=510;
            return maxNum;
        }
        else
        {
            printf("Enter a valid input\n");
        }
    }
}

int update_score(int score,int hscore)
{
    if (score>hscore)
    {
        hscore=score;
    }
    return hscore;
}

void start_egame(void)
{
    int qcount=0;
    int score=0;
    static int hscore=0;
    int maxNum=0;
    maxNum=hcdifficulty();
    if (maxNum==510)
    {
        hardcore(maxNum);
        return;
    }
    while(true)
    {
        clear_screen();
        int num1=rand()%maxNum;
        int num2=rand()%maxNum;
        int num3=rand()%maxNum;
        int crrctans=num1+num2-num3;
        display_difficulty(maxNum,qcount);
        printf("                                      High Score:%i\n",hscore);
        printf("                                      Score:%i\n",score);
        qcount++;
        printf("%i+%i-%i? = ",num1,num2,num3);
        int ans=get_int("");

        if (ans==crrctans)
        {
            printf("✅Correct!\n");
            score+=10;
            score+=score_multiplier(qcount);
            hscore=update_score(score,hscore);
        }
        else if(ans!=crrctans)
        {
            printf("\a❌Wrong\n");
            hscore=update_score(score,hscore);
            printf("🎯High score:%i\n",hscore);
            score=0;
            qcount=0;
            while(true)
            {
                char response=get_char("Do you want to try again?(Y/N): ");
                if (response=='y' || response=='Y')
                {
                    break;
                }
                else if (response=='n' || response=='N')
                {
                    printf("Exiting...\n");
                    return;
                }
                else
                {
                    printf("Enter a valid response\n");
                }
            }
        }
    }

}

int score_multiplier(int qcount)
{
    int base;
    if (qcount!=0 && qcount%10==0)
    {
        base=50;
        return base;
    }
    else
    {   base =0;
        return base;
    }

}

int no_of_question_in_fgame(int maxNum)
{
    int qcount;
    if(maxNum==20)
    {
        qcount=5;
    }
    else if (maxNum==100)
    {
        qcount=10;
    }
    else
    {
        qcount=20;
    }
    return qcount;
}
void start_fgame(void)
{
    int score=0;
    int max_score=50;
    int qcount=0;
    int maxNum=difficulty();
    int max_que=no_of_question_in_fgame(maxNum);
    while(true)
    {
        for (int i=0;i<max_que;i++)
        {
                clear_screen();
                int num1=rand()%maxNum;
                int num2=rand()%maxNum;
                int num3=rand()%maxNum;
                int crrctans=num1+num2-num3;
                display_difficulty(maxNum,qcount);
                printf("                                      Score:%i\n",score);
                printf("\n%i+%i-%i? = ",num1,num2,num3);
                int ans=get_int("");
                qcount++;

                if (ans==crrctans)
                {
                    printf("✅Correct!\n");
                    score+=10;
                }

                else
                {
                    printf("\a❌Wrong\n");
                    break;
                }



        }
        printf("🎯You scored %i/%i\n",score,max_score);
        score=0;
        while(true)
        {

            char response=get_char("Do you want to try again?(Y/N): ");
            if (response=='y' || response=='Y')
            {
                break;
            }
            else if (response=='n' || response=='N')
            {
                printf("☠GAME OVER☠\n\n");
                return;
            }
            else
            {
                printf("Enter a valid response\n");
            }
        }

    }
}
void clear_screen(void)
{
    system("clear");
}


void play_scrn(void)
{
    char response;
    do
    {
        clear_screen();

        printf("     ➗ ➖   🧩 🎮\n     📐 MUZZLE! 🧠\n     ➕ ✖️    💡 🎯\n\n🎯DO YOU WANT TO PLAY?🎯\n");
        printf("YES✅               NO❌\n");
        response=get_char("Y/N: ");
        if (response=='y' || response=='Y')
        {
            while (true)
            {
                clear_screen();
                printf("          SELECT GAMEMODE\n");
                printf("♾️  ENDLESS(1)          🎮 CLASSIC(2)\n");
                int gmode=get_int(": ");
                if (gmode==1)
                {
                    start_egame();
                    break;
                }
                else if (gmode==2)
                {
                    start_fgame();
                    break;
                }
                else
                {
                    printf("Enter a valid input\n");
                }
            }
        }
        else if (response=='n' || response=='N')
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Enter a valid response\n");
        }
    }
    while(true);
}

