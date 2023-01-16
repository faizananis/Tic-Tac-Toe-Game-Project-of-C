#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cyan()
{
    printf("\033[5;36m");
}
void yellow()
{
    printf("\033[0;33m");
}
void yellow_bold()
{
    printf("\033[1;33m");
}
void reset()
{
    printf("\033[0m");
}
void time_delay(int seconds)
{
    int q_second=250*seconds;
    clock_t start_time=clock();
    while(clock()<start_time + q_second);
}
void computer(char n)
{
    char name[50]={0};
    char game[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int turn=0;
    int row=0;
    int col=0;
    int spaces=0;
    int count=0;
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    int finish=0;
    char choice=0;
    int win=0;
    int lose=0;
    int i=0;
    int j=0;
    int l=0;
    int m=0;
    cyan();
    printf(" Please Enter your Name: ");
    reset();
    printf("\033[1;36m");
    gets(name);
    srand(time(NULL));
    do
    {
        reset();
        system("cls");
        choice=0;
        count=0;
        row=0;
        col=0;
        l=0;
        m=0;
        printf("\033[0;36m");
        printf("\n################### TIC TAC TOE #########################");
        yellow();
        if(n=='1')
            printf("\n\n             Game Mode: SMART COMPUTER");
        else if(n=='2')
            printf("\n\n             Game Mode: EVIL COMPUTER");
        printf("\033[1;31m");
        printf("\n\n");
        printf(" %s : O",name);
        printf("                            Spaces Left: %d\n",9-spaces);
        printf(" Computer : X");
        printf("\n\n\n");
        for(i=0;i<9;i++)
        {
            yellow();
            printf("         ");
            for(j=0;j<3;j++)
            {
                if(j==0)
                    printf("    |");
                if(i%3==1)
                {
                    if(game[row][col]=='X')
                    {
                        printf("\033[1;31m");
                    }
                    else if(game[row][col]=='O')
                    {
                        printf("\033[1;32m");
                    }
                    else
                    {
                        printf("\033[1;34m");
                    }
                    printf("   %c   ",game[row][col++]);
                    yellow();
                    printf("|");
                    if(col==3)
                    {
                        row++;
                        col=0;
                    }
                }
                else
                    printf("       |");
            }
            printf("\n");
            if(i==2||i==5)
            printf("         _________________________________\n");
        }
        printf("\n\n");
        row=0;
        col=0;
        if(game[row][col+2]=='X'&&game[row+1][col+1]=='X'&&game[row+2][col]=='X')
        {
            lose=1;
        }
        else if(game[row][col]=='X'&&game[row+1][col+1]=='X'&&game[row+2][col+2]=='X')
        {
            lose=1;
        }
        if(game[row][col+2]=='O'&&game[row+1][col+1]=='O'&&game[row+2][col]=='O')
        {
            win=1;
        }
        else if(game[row][col]=='O'&&game[row+1][col+1]=='O'&&game[row+2][col+2]=='O')
        {
            win=1;
        }
        else
        {
            for(row=0;row<3;row++)
            {
                count1=0;
                count2=0;
                count3=0;
                count4=0;
                for(col=0;col<3;col++)
                {
                    if(game[row][col]=='O')
                        count1++;
                    if(game[col][row]=='O')
                        count2++;
                    if(game[row][col]=='X')
                        count3++;
                    if(game[col][row]=='X')
                        count4++;
                }
                if(count1==3||count2==3)
                {
                    win=1;
                    break;
                }
                else if(count3==3||count4==3)
                {
                    lose=1;
                    break;
                }
            }
        }
        if(win==1)
        {
            yellow_bold();
            printf("\n\n Congratulations %s! You won this game.\n\n",name);
            break;
        }
        else if(lose==1)
        {
            yellow_bold();
            printf("\n\n Oops! Dear %s, you Lose the game and Computer wins the game. BETTER LUCK NEXT TIME!\n\n",name);
            break;
        }
        if(finish==0)
        {
            if(turn%2==0)
            {
                cyan();
                printf(" Please Enter your choice key from 1 to 9: ");
                do
                {
                    choice=getch();
                    if(choice<49||choice>57)
                        continue;
                    choice=choice-49;
                    row=choice/3;
                    col=choice%3;
                    if(game[row][col]<79)
                        game[row][col]='O';
                    else
                        continue;
                    break;
                }while(1);
            }
            else if(turn%2==1)
            {
                time_delay(1);
                for(l=0;l<3;l++)
                {
                    for(m=0;m<3;m++)
                    {
                        if(m==0)
                        {
                            if(game[l][m]=='X'&&game[l][m+1]=='X'&&game[l][m+2]<79)
                            {
                                    game[l][m+2]='X';
                                    break;
                            }
                            else if(game[m][l]=='X'&&game[m+1][l]=='X'&&game[m+2][l]<79)
                            {
                                    game[m+2][l]='X';
                                    break;
                            }
                            else if(game[m][m]=='X'&&game[m+1][m+1]=='X'&&game[m+2][m+2]<79)
                            {
                                    game[m+2][m+2]='X';
                                    break;
                            }
                            else if(game[m][m+2]=='X'&&game[m+2][m]=='X'&&game[m+1][m+1]<79)
                            {
                                    game[m+1][m+1]='X';
                                    break;
                            }
                        }
                        else if(m==1)
                        {
                            if(game[l][m]=='X'&&game[l][m+1]=='X'&&game[l][m-1]<79)
                            {
                                    game[l][m-1]='X';
                                    break;
                            }
                            else if(game[m][l]=='X'&&game[m+1][l]=='X'&&game[m-1][l]<79)
                            {
                                    game[m-1][l]='X';
                                    break;
                            }
                            else if(game[m][m]=='X'&&game[m+1][m+1]=='X'&&game[m-1][m-1]<79)
                            {
                                    game[m-1][m-1]='X';
                                    break;
                            }
                            else if(game[m][m]=='X'&&game[m-1][m+1]=='X'&&game[m+1][m-1]<79)
                            {
                                    game[m+1][m-1]='X';
                                    break;
                            }
                            else if(game[m][m]=='X'&&game[m+1][m-1]=='X'&&game[m-1][m+1]<79)
                            {
                                    game[m-1][m+1]='X';
                                    break;
                            }
                        }
                        else if(m==2)
                        {
                            if(game[l][m]=='X'&&game[l][m-2]=='X'&&game[l][m-1]<79)
                            {
                                game[l][m-1]='X';
                                break;
                            }
                            else if(game[m][l]=='X'&&game[m-2][l]=='X'&&game[m-1][l]<79)
                            {
                                game[m-1][l]='X';
                                break;
                            }
                            else if(game[m][m]=='X'&&game[m-2][m-2]=='X'&&game[m-1][m-1]<79)
                            {
                                game[m-1][m-1]='X';
                                break;
                            }
                        }
                    }
                    if(m<3)
                    {
                        break;
                    }
                }
            }
            if(turn%2==1&&l==3)
            {
                do
                {
                    count++;
                    for(l=0;l<3;l++)
                    {
                        for(m=0;m<3;m++)
                        {
                            if(m==0)
                            {
                                if(game[l][m]=='O'&&game[l][m+1]=='O'&&game[l][m+2]<79)
                                {
                                        game[l][m+2]='X';
                                        break;
                                }
                                else if(game[m][l]=='O'&&game[m+1][l]=='O'&&game[m+2][l]<79)
                                {
                                        game[m+2][l]='X';
                                        break;
                                }
                                else if(game[m][m]=='O'&&game[m+1][m+1]=='O'&&game[m+2][m+2]<79)
                                {
                                        game[m+2][m+2]='X';
                                        break;
                                }
                                else if(game[m][m+2]=='O'&&game[m+2][m]=='O'&&game[m+1][m+1]<79)
                                {
                                        game[m+1][m+1]='X';
                                        break;
                                }
                            }
                            else if(m==1)
                            {
                                if(game[l][m]=='O'&&game[l][m+1]=='O'&&game[l][m-1]<79)
                                {
                                        game[l][m-1]='X';
                                        break;
                                }
                                else if(game[m][l]=='O'&&game[m+1][l]=='O'&&game[m-1][l]<79)
                                {
                                        game[m-1][l]='X';
                                        break;
                                }
                                else if(game[m][m]=='O'&&game[m+1][m+1]=='O'&&game[m-1][m-1]<79)
                                {
                                        game[m-1][m-1]='X';
                                        break;
                                }
                                else if(game[m][m]=='O'&&game[m-1][m+1]=='O'&&game[m+1][m-1]<79)
                                {
                                        game[m+1][m-1]='X';
                                        break;
                                }
                                else if(game[m][m]=='O'&&game[m+1][m-1]=='O'&&game[m-1][m+1]<79)
                                {
                                        game[m-1][m+1]='X';
                                        break;
                                }
                            }
                            else if(m==2)
                            {
                                if(game[l][m]=='O'&&game[l][m-2]=='O'&&game[l][m-1]<79)
                                {
                                    game[l][m-1]='X';
                                    break;
                                }
                                else if(game[m][l]=='O'&&game[m-2][l]=='O'&&game[m-1][l]<79)
                                {
                                    game[m-1][l]='X';
                                    break;
                                }
                                else if(game[m][m]=='O'&&game[m-2][m-2]=='O'&&game[m-1][m-1]<79)
                                {
                                    game[m-1][m-1]='X';
                                    break;
                                }
                            }
                        }
                        if(m<3)
                        {
                            break;
                        }
                    }
                }while(n=='2'&&l<3);
                if(count>2)
                {
                    spaces=spaces+count-2;
                }
            }
            if(turn%2==1&&l==3&&count==1)
            {
                do
                {
                    choice=rand()%9;
                    row=choice/3;
                    col=choice%3;
                    if(game[row][col]!='O'&&game[row][col]!='X')
                    {
                        game[row][col]='X';
                    }
                    else
                    {
                        continue;
                    }
                    break;
                }while(1);
            }
            turn++;
            spaces++;
        }
        for(row=0;row<3;row++)
        {
            for(col=0;col<3;col++)
            {
                if(game[row][col]=='O'||game[row][col]=='X')
                {
                    continue;
                }
                break;
            }
            if(col<3)
            {

                break;
            }
        }
        if(row==3)
            finish++;
        if(finish==2)
        {
            yellow_bold();
            printf("\n\n The Game is drawn. No one wins this time.\n\n");
        }
    }while(finish!=2);
    yellow();
}
void player()
{
    char name1[50]={0};
    char name2[50]={0};
    char game[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int turn=0;
    int row=0;
    int col=0;
    int finish=0;
    char choice=0;
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    int win1=0;
    int win2=0;
    int i=0;
    int j=0;
    int l=0;
    int m=0;
    cyan();
    printf("Please Enter the Name of Player 1: ");
    reset();
    printf("\033[1;36m");
    gets(name1);
    reset();
    cyan();
    printf("\nPlease Enter the Name of Player 2: ");
    reset();
    printf("\033[1;36m");
    gets(name2);
    do
    {
        reset();
        system("cls");
        choice=0;
        count1=0;
        count2=0;
        count3=0;
        count4=0;
        row=0;
        col=0;
        l=0;
        m=0;
        printf("\033[0;36m");
        printf("\n################### TIC TAC TOE #########################");
        printf("\n\n");
        yellow();
        printf("           Game Mode: Player to Player\n\n");
        printf("\033[1;31m");
        printf(" %s : O",name1);
        printf("                                Spaces left: %d\n",9-turn);
        printf(" %s : X",name2);
        printf("\n\n\n");
        for(i=0;i<9;i++)
        {
            yellow();
            printf("         ");
            for(j=0;j<3;j++)
            {
                if(j==0)
                    printf("    |");
                if(i%3==1)
                {
                    if(game[row][col]=='X')
                    {
                        printf("\033[1;31m");
                    }
                    else if(game[row][col]=='O')
                    {
                        printf("\033[1;32m");
                    }
                    else
                    {
                        printf("\033[1;34m");
                    }
                    printf("   %c   ",game[row][col++]);
                    yellow();
                    printf("|");
                    if(col==3)
                    {
                        row++;
                        col=0;
                    }
                }
                else
                    printf("       |");
            }
            printf("\n");
            if(i==2||i==5)
            printf("         _________________________________\n");
        }
        printf("\n\n");
        row=0;
        col=0;
        if(game[row][col+2]=='X'&&game[row+1][col+1]=='X'&&game[row+2][col]=='X')
        {
            win2=1;
        }
        else if(game[row][col]=='X'&&game[row+1][col+1]=='X'&&game[row+2][col+2]=='X')
        {
            win2=1;
        }
        else if(game[row][col+2]=='O'&&game[row+1][col+1]=='O'&&game[row+2][col]=='O')
        {
            win1=1;
        }
        else if(game[row][col]=='O'&&game[row+1][col+1]=='O'&&game[row+2][col+2]=='O')
        {
            win1=1;
        }
        else
        {
            for(row=0;row<3;row++)
            {
                count1=0;
                count2=0;
                count3=0;
                count4=0;
                for(col=0;col<3;col++)
                {
                    if(game[row][col]=='O')
                        count1++;
                    if(game[col][row]=='O')
                        count2++;
                    if(game[row][col]=='X')
                        count3++;
                    if(game[col][row]=='X')
                        count4++;
                }
                if(count1==3||count2==3)
                {
                    win1=1;
                    break;
                }
                else if(count3==3||count4==3)
                {
                    win2=1;
                    break;
                }
            }
        }
        if(win1==1)
        {
            yellow_bold();
            printf("\n\n Congratulations %s! You WON this game. Dear %s, BETTER LUCK NEXT TIME!\n\n",name1,name2);
            break;
        }
        else if(win2==1)
        {
            yellow_bold();
            printf("\n\n Congratulations %s! You WON this game. Dear %s, BETTER LUCK NEXT TIME!\n\n",name2,name1);
            break;
        }
        if(finish==0)
        {
            if(turn%2==0)
            {
                cyan();
                printf(" Dear %s! Please Enter your choice key from 1 to 9: ",name1);
                do
                {
                    choice=getch();
                    if(choice<49||choice>57)
                        continue;
                    choice=choice-49;
                    row=choice/3;
                    col=choice%3;
                    if(game[row][col]<79)
                        game[row][col]='O';
                    else
                        continue;
                    break;
                }while(1);
            }
            else if(turn%2==1)
            {
                cyan();
                printf(" Dear %s! Please Enter your choice key from 1 to 9: ",name2);
                do
                {
                    choice=getch();
                    if(choice<49||choice>57)
                        continue;
                    choice=choice-49;
                    row=choice/3;
                    col=choice%3;
                    if(game[row][col]<79)
                        game[row][col]='X';
                    else
                        continue;
                    break;
                }while(1);
            }
            turn++;
            for(row=0;row<3;row++)
            {
                for(col=0;col<3;col++)
                {
                    if(game[row][col]=='O'||game[row][col]=='X')
                    {
                        continue;
                    }
                    break;
                }
                if(col<3)
                {
                    break;
                }
            }
        }
        if(row==3)
        {
            finish++;
        }
        if(finish==2)
        {
            reset();
            yellow_bold();
            printf("\n\n The Game is drawn. No one wins this time.\n\n");
        }
    }while(finish!=2);
    yellow();
}
int main()
{
    char choice=0;
    char name1[50]={0};
    int i=0;
    do
    {
        i=0;
        choice=0;
        do
        {
            system("cls");
            reset();
            printf("\033[1;31m");
            printf(" Please Enter that which type of game you want to play from the following game modes:\n");
            printf(" 1. Play with Smart Computer\n");
            printf(" 2. Play with Evil Computer\n");
            printf(" 3. Play with player or your friend\n");
            printf(" 4. Exit\n");
            cyan();
            if(i==0)
            {
                printf("\n Enter your choice key: ");
            }
            else if(i>0)
            {
                printf("\n You Entered incorrect key! Re-enter your choice key: ");
            }
            do
            {
                choice=getch();
                if(i>0)
                {
                    if(choice>=49&&choice<=52)
                    break;
                }
            }while(i>0);
            i++;
        }while(choice<49||choice>52);
        system("cls");
        printf("\033[0;36m");
        printf("\n################### TIC TAC TOE #########################");
        printf("\n\n");
        switch(choice)
        {
        case '1':
            computer(choice);
            break;
        case '2':
            computer(choice);
            break;
        case '3':
            player();
            break;
        case '4':
            yellow_bold();
            printf("\n The game is closed by your wish. Happy Gaming!\n\n");
            yellow();
        }
        printf("\033[5;33m");
        printf("\n Press any Key to Continue.....");
        getch();
    }while(choice!='4');
    reset();
    system("cls");
    return 0;
}

