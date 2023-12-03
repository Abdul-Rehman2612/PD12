#include<iostream>
#include<windows.h>
using namespace std;
void printMaze();
void movePlayerLeft();
void moveplayerRight();
string moveEnemy1(string directionE1);
string moveEnemy2(string directionE2);
void fire();
char board[26][52]={"###################################################",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "#                                                 #",
                    "###################################################"
                    };
char player='P';
char enemyH='X';
char enemyV='X';
char bullet='|';
int eX1=1,eY1=1;
int eX2=40,eY2=2;
int pX=2,pY=24;
main()
{
    string directionE1="right";
    string directionE2="down";
    while(true)
    {
        system("cls");
        printMaze();
        movePlayerLeft();
        moveplayerRight();
        directionE1=moveEnemy1(directionE1);
        directionE2=moveEnemy2(directionE2);
        fire();
        Sleep(100);
    }
}
void printMaze()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<52;j++)
        {
            if(eX1==j && eY1==i)
            {
                board[i][j]=enemyH;
                cout << board[i][j];
            }
            else if(eX2==j && eY2==i)
            {
                board[i][j]=enemyV;
                cout << board[i][j];
            }
            else if(pX==j && pY==i)
            {
                board[i][j]=player;
                cout << board[i][j];
            }
            else if(board[i][j]==bullet && board[i-1][j]==' ')
            {
                board[i][j]=' ';
                board[i-1][j]=bullet;
                cout << board[i-1][j];
            }
            else if(board[i][j]==bullet && board[i-1][j]!=' ')
            {
                board[i][j]=' ';
                cout << board[i][j];
            }
            else
            {
                cout << board[i][j];
            }
        }
        cout << endl;
    }
}
void movePlayerLeft()
{
    if(board[pY][pX-1]==' ' && GetAsyncKeyState(VK_LEFT))
    {
        board[pY][pX]=' ';
        pX=pX-1;
    }
}
void moveplayerRight()
{
    if(board[pY][pX+1]==' ' && GetAsyncKeyState(VK_RIGHT))
    {
        board[pY][pX]=' ';
        pX=pX+1;
    }
}
string moveEnemy1(string directionE1)
{
    if(directionE1=="left" && board[eY1][eX1-1]==' ')
    {
        board[eY1][eX1]=' ';
        eX1=eX1-1;
    }
    else
    {
        directionE1="right";
    }
    if(directionE1=="right" && board[eY1][eX1+1]==' ')
    {
        board[eY1][eX1]=' ';
        eX1=eX1+1;
    }
    else
    {
        directionE1="left";
    }
    return directionE1;
}
string moveEnemy2(string directionE2)
{
    if(directionE2=="up" && board[eY2-1][eX2]==' ')
    {
        board[eY2][eX2]=' ';
        eY2=eY2-1;
    }
    else
    {
        directionE2="down";
    }
    if(directionE2=="down" && board[eY2+1][eX2]==' ')
    {
        board[eY2][eX2]=' ';
        eY2=eY2+1;
    }
    else
    {
        directionE2="up";
    }
    return directionE2;
}
void fire()
{
    if(GetAsyncKeyState(VK_SPACE))
    {
        board[pY-1][pX]=bullet;
    }
}