#include <stdlib.h>
#include<time.h>
#include <cs50.h>
#include<stdio.h>

void play_scrn(void);
void start_egame(void);
void start_fgame(void);
int difficulty(void);

int main(void)
{
    play_scrn();
}

int difficulty(void)
{
    int maxNum;
    char diff;
    while(true)
    {
        printf("       SELECT DIFFICULTY\n");
        printf("(E)asy      (M)edium      (H)ard\n");
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

void start_egame(void)
{
    srand(time(NULL));
    int score=0;
    int hscore=0;
    int loop=1;
    int maxNum=0;
    maxNum=difficulty();
    while(true)
    {
        int num1=rand()%maxNum;
        int num2=rand()%maxNum;
        int num3=rand()%maxNum;
        int crrctans=num1+num2-num3;
        printf("%i+%i-%i? = ",num1,num2,num3);
        int ans=get_int("");

        if (ans==crrctans)
        {
            printf("Correct!\n");
            score+=10;
            printf("score:%i\n",score);
            if (score>hscore)
            {
                hscore=score;
            }
            printf("High score:%i\n",hscore);
            while(true)
            {
                char response=get_char("Do you want try again?(Y/N): ");
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
        else if(ans!=crrctans)
        {
            printf("Wrong\n");
            hscore=score;
            printf("High score:%i\n",hscore);
            score=0;
            while(true)
            {
                char response=get_char("Do you want try again?(Y/N): ");
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

void start_fgame(void)
{
    for (int i=0;i<5;i++)
    {

        srand(time(NULL));
        int score=0;
        int max_score=50;
        int loop=1;
        int maxNum=difficulty();
        while(true)
        {
            int num1=rand()%maxNum;
            int num2=rand()%maxNum;
            int num3=rand()%maxNum;
            int crrctans=num1+num2-num3;
            printf("%i+%i-%i? = ",num1,num2,num3);
            int ans=get_int("");

            if (ans==crrctans)
            {
                printf("Correct!\n");
                score+=10;
            }

            else if(ans!=crrctans)
            {
                printf("Wrong\n");
                printf("You scored %i/%i\n",score,max_score);
                while(true)
                {
                    char response=get_char("Do you want try again?(Y/N): ");
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
}


void play_scrn(void)
{
    char response;
    do
    {
        printf("      MUZZLE!\nDO YOU WANT TO PLAY?\n");
        printf("YES              NO\n");
        response=get_char("Y/N: ");
        if (response=='y' || response=='Y')
        {
            while (true)
            {
                printf("      SELECT GAMEMODE\n");
                printf("ENDLESS(1)          CLASSIC(2)\n");
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

