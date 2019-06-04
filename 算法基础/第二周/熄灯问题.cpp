/*
问题描述：
1 有一个由按钮组成的矩阵，其中每行有6个按钮，共5行。
2 每个按钮的位置上有一盏灯。
3 当按下一个按钮后，该按钮以及周围位置（上下左右，如果有的话）的灯都会改变一次。
  如果原来亮着，则熄灭；如果原来熄灭，则点亮。
4 与一盏灯毗邻的多个按钮被按下时，一个操作会抵消另一个操作的结果。
5 矩阵中每盏灯都有一个初始状态。
6 请写一个程序，确定需要按下那些按钮，恰好使得所有的灯都熄灭。

输入：
第一行是一个正整数N，表示需要解决的案例数。
每个案例由5行组成，每一行包括6各数字，数组为0或1，用空格隔开。
0表示灯为熄灭状态；1表示灯为打开状态。

输出：
对每个案例，首先输出一行，输出字符串“PUZZLE #m”，其中m表示该案例的序号
接着按照该案例的输入格式输出5行，
1表示需要把对应的按钮按下，0表示不需要按下，每个数字以空格隔开。

样例输入：
2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
样例输出：
PUZZLE #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
PUZZLE #2
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1
*/
/*
基本思路: 如果存在某个局部, 一旦这个局部的状态被确定,
那么剩余其他部分的状态只能是确定的一种, 或者不多的n
种, 那么就只需枚举这个局部的状态即可

具体实现：
用一个矩阵 puzzle[5][6] 表示灯的初始状态
用一个矩阵 press[5][6] 表示要计算的结果，
为了计算方便（每个位置都有上下左右），在上和左右进行全零填充，用[6][8]来表示。
第一行的枚举方式：将按钮矩阵的第1行看作一个二进制数,通过实现++操作实现

给定PRESS的第1行取值, 计算出PRESS的其他行的值：
press[2][c]=(puzzle[1][c]+press[1][c-1] +press[1][c]+press[1][c+1] + press[0][c]) %2
*/
#include<stdio.h>
int puzzle[6][8],press[6][8];
bool guess(){
    int c,r;
    for(r=1;r<5;r++){
        for(c=1;c<7;c++){
            press[r+1][c]=(puzzle[r][c]+press[r][c]+press[r-1][c]+press[r][c+1]+press[r][c-1])%2;
        }
    }
    for(c=1;c<7;c++){
        if((press[5][c-1]+press[5][c]+press[5][c+1]+press[4][c])%2!=puzzle[5][c])
            return false;
    }
    return true;
}
void enumerate(){
    int c;
    bool success;
    for(c=1;c<7;c++)
        press[1][c]=0;
    while(guess()==false){
        press[1][1]++;
        c=1;
        while (press[1][c] > 1){
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }
    return;
}
int main(){
    int cases, i, r, c;
    scanf("%d", &cases);
    for ( r=0; r<6; r++ )
        press[r][0] = press[r][7] = 0;
    for ( c=1; c<7; c++ )
        press[0][c] = 0;
    for (i=0; i<cases; i++){
        for (r=1; r<6; r++)
            for (c=1; c<7; c++)
                scanf("%d", &puzzle[r][c]);
        enumerate();
        printf("PUZZLE #%d\n", i+1);
        for(r=1; r<6; r++){
            for(c=1; c<7; c++)
                printf("%d ", press[r][c]);
            printf("\n");
        }
    }
    return 0;
}
