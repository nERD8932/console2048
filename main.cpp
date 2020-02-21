#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <windows.h>


using namespace std;

struct screens
{
    int menu();
    void game();
    void display();
    void addrandom();
    int options();
};

screens selector;

struct settings
{
    int gridsize = 4;
    char color[9] = "color 0f";
};

settings change;

int grid[9][9];

int main()
{
    system("title 2-0-4-8");
    selector.menu();
}

int screens::menu()
{
    system("cls");
    cout<<"\n\n\n      2-0-4-8\n\n\n 1. Start Game\n 2. Options\n 3. Exit\n\n";
    switch(getch())
    {
        case 49:
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    grid[i][j] = 0;
                }
            }
            grid[rand()%change.gridsize][rand()%change.gridsize] = 2;
            selector.display();
            selector.game();
            break;
        case 50:
            selector.options();
            break;
        case 51:
            break;
        default:
            main();
    }
}

void screens::game()
{
    selector.display();
    switch(getch())
    {
        case 72:  //up
            for(int i=0;i<change.gridsize;i++)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                   if(grid[i][j]!=0)
                   {
                       for(int k=i+1;k<change.gridsize;k++)
                       {
                           if(grid[i][j]==grid[k][j])
                           {
                               grid[i][j]*=2;
                               grid[k][j] = 0;
                               break;
                           }
                           else if(grid[k][j]!=grid[i][j]&&grid[k][j]!=0)
                           {
                               k = change.gridsize;
                           }
                       }
                   }
                }
            }
            selector.display();
            for(int i=0;i<change.gridsize;i++)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                    if(grid[i][j]==0)
                    {
                        for(int k=i+1;k<change.gridsize;)
                        {
                            if(grid[k][j]!=0)
                            {
                               for(int l=k;l<change.gridsize;l++) //exit the loop
                               {
                                   grid[i+l-k][j] = grid[l][j];
                                   grid[l][j] = 0;
                               }
                               break;
                            }
                            else{k++;}
                        }
                    }
                }
            }
            selector.addrandom();
            selector.display();
            selector.game();
            break;

        case 75: //left
            for(int i=0;i<change.gridsize;i++)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                   if(grid[j][i]!=0)
                   {
                       for(int k=i+1;k<change.gridsize;k++)
                       {
                           if(grid[j][i]==grid[j][k])
                           {
                               grid[j][i]*=2;
                               grid[j][k] = 0;
                               break;
                           }
                           else if(grid[j][k]!=grid[j][i]&&grid[j][k]!=0)
                           {
                               k = change.gridsize;
                           }
                       }
                   }
                }
            }
            selector.display();
            for(int i=0;i<change.gridsize;i++)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                    if(grid[j][i]==0)
                    {
                        for(int k=i+1;k<change.gridsize;)
                        {
                            if(grid[j][k]!=0)
                            {
                               for(int l=k;l<change.gridsize;l++) //exit the loop
                               {
                                   grid[j][i+l-k] = grid[j][l];
                                   grid[j][l] = 0;
                               }
                               break;
                            }
                            else{k++;}
                        }
                    }
                }
            }
            selector.addrandom();
            selector.display();
            selector.game();
            break;
        case 80:  //down
            for(int i=change.gridsize-1;i>=0;i--)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                   if(grid[i][j]!=0)
                   {
                       for(int k=i-1;k>=0;k--)
                       {
                           if(grid[i][j]==grid[k][j])
                           {
                               grid[i][j]*=2;
                               grid[k][j] = 0;
                               break;
                           }
                           else if(grid[k][j]!=grid[i][j]&&grid[k][j]!=0)
                           {
                               k = -1;
                           }
                       }
                   }
                }
            }
            selector.display();
            for(int i=change.gridsize-1;i>=0;i--) /**redo**/
            {
                for(int j=0;j<change.gridsize;j++)
                {
                    if(grid[i][j]==0)
                    {
                        for(int k=i-1;k>=0;)
                        {
                            if(grid[k][j]!=0)
                            {
                               for(int l=k;l>=0;l--) //exit the loop
                               {
                                   grid[i+l-k][j] = grid[l][j];
                                   grid[l][j] = 0;
                               }
                               break;
                            }
                            else{k--;}
                        }
                    }
                }
            }
            selector.addrandom();
            selector.display();
            selector.game();
            break;
        case 77:  //right
            for(int i=change.gridsize-1;i>=0;i--)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                   if(grid[j][i]!=0)
                   {
                       for(int k=i-1;k>=0;k--)
                       {
                           if(grid[j][i]==grid[j][k])
                           {
                               grid[j][i]*=2;
                               grid[j][k] = 0;
                               break;
                           }
                           else if(grid[j][k]!=grid[j][i]&&grid[j][k]!=0)
                           {
                               k = -1;
                           }
                       }
                   }
                }
            }
            selector.display();
            for(int i=change.gridsize-1;i>=0;i--)
            {
                for(int j=0;j<change.gridsize;j++)
                {
                    if(grid[j][i]==0)
                    {
                        for(int k=i-1;k>=0;)
                        {
                            if(grid[j][k]!=0)
                            {
                               for(int l=k;l>=0;l--) //exit the loop
                               {
                                   grid[j][i+l-k] = grid[j][l];
                                   grid[j][l] = 0;
                               }
                               break;
                            }
                            else{k--;}
                        }
                    }
                }
            }
            selector.addrandom();
            selector.display();
            selector.game();
            break;
        case 113:
            cout<<"\n Are you sure you want to exit?(Y/N)";
            switch(getch())
            {
                case 121:
                    selector.menu();
                    break;
                case 89:
                    selector.menu();
                    break;
                case 110:
                    selector.game();
                    break;
                case 78:
                    selector.game();
                    break;
                default:
                    selector.game();
                    break;
            }
        case 81:
            cout<<"\n Are you sure you want to exit?(Y/N)";
            switch(getch())
            {
                case 121:
                    selector.menu();
                    break;
                case 89:
                    selector.menu();
                    break;
                case 110:
                    selector.game();
                    break;
                case 78:
                    selector.game();
                    break;
                default:
                    selector.game();
                    break;
            }
        default:
            selector.game();
    }
}

void screens::display()
{
    system("cls");
    printf("\n\n\n");
   // cout<<"\n\n\n";
    for(int i=0;i<change.gridsize*2;i++){/*cout<<" ";*/printf(" ");}
    printf("2-0-4-8\n\n\n\n");
    //cout<<"2-0-4-8\n\n\n\n";
    for(int i=0;i<change.gridsize;i++)
    {
        printf("   ");
        //cout<<"   ";
        for(int j=0;j<change.gridsize;j++)                  /**display**/
        {
            int temp,digit;
            printf("%i",grid[i][j]);
            //cout<<grid[i][j];
            temp = grid[i][j];
            digit=0;
            while(temp>9){temp=temp/10;digit++;}
            ++digit;
            for(int k=0;k<5-digit;k++){/*cout<<" ";*/printf(" ");}
        }
        printf("\n\n\n\n");
        //cout<<"\n\n\n\n";
    }
    printf("\n\n\n\n Press Q to exit to main menu.");
   // cout<<"\n\n\n\n Press Q to exit to main menu.";
}

int screens::options()
{
    system("cls");
    printf("\n  Options\n\n\n1. Grid Size(%d x %d)\n2. Font Color\n3. Back to Main Menu\n",change.gridsize,change.gridsize);
    switch(getch())
    {
        case 49:
            change.gridsize = change.gridsize + 1;
            if(change.gridsize>=8){change.gridsize =4;}
            selector.options();
            break;
        case 50:
            if(change.color[7]!='9'){if(strcmp(change.color,"color 0f")==0){strcpy(change.color,"color 01");}else{change.color[7]++;}}
            else{strcpy(change.color,"color 0a");}
            system(change.color);
            selector.options();
            break;
        case 51:
            main();
            break;
        default:
            selector.options();
    }
}

void screens::addrandom()
{
    int x,y;
    bool addrand,flag;
    flag = false;
    for(int i=0;i<change.gridsize;i++)
    {
        for(int j=0;j<change.gridsize;j++)
        {
            if(grid[i][j]==0)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag == true)
    {
        addrand = false;
        while(addrand==false)
        {
            x = rand()%change.gridsize;
            y = rand()%change.gridsize;
            if(grid[x][y]==0)
            {
                grid[x][y] = 2;
                addrand = true;
            }
        }
    }
}
