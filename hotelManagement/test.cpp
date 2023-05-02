#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void gotoxy(short x, short y){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{
    // int x;
    // cin>>x;
    gotoxy(50,15);
    cout<<"hlw";
}
