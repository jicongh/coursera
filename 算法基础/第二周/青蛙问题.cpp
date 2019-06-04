/*
问题描述：
• 在韩国, 有一种小青蛙
• 每到晚上, 这种青蛙会跳跃稻田, 从而踩踏稻子
• 农民早上看到被踩踏的稻子, 希望找到造成最大损害的那只青蛙经过的路径
• 每只青蛙总是沿着一条直线跳跃稻田
• 且每次跳跃的距离都相同
稻田里的稻子组成一个栅格, 每棵稻子位于一个格点上
而青蛙总是从稻田的一侧跳进稻田, 然后沿着某条直线穿越稻田, 从另一侧跳出去
只有两颗被踩的不是一条路径。

题目要求：
写一个程序，在各条青蛙行走路径中, 踩踏水稻最多的那一条上, 有多少颗水稻被踩踏

程序输入
• 从标准输入设备上读入数据
• 第一行上两个整数R, C, 分别表示稻田中水稻的行数和列数, 1≤R, C≤5000
• 第二行是一个整数N, 表示被踩踏的水稻数量,3≤N≤5000
• 在剩下的N行中, 每行有两个整数, 分别是一颗被踩踏水稻的行号(1~R)和列号(1~C), 两个整数用一个空格隔开
• 且每棵被踩踏水稻只被列出一次

程序输出
• 从标准输出设备上输出一个整数
• 如果在稻田中存在青蛙行走路径, 则输出包含最多水稻的青蛙行走路径中的水稻数量, 否则输出0

样例输入：
6 7 //6行7列
14
2 1
6 6
4 2
2 5
2 6
2 7
3 4
6 1
6 2
2 3
6 3
6 4
6 5
6 7
样例输出：
7
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int r, c, n;
struct PLANT {
int x, y;
};
PLANT plants[5001];
PLANT plant;
int searchPath(PLANT secPlant, int dX, int dY) ;
int main(){
    int i, j, dX, dY, pX, pY, steps, max = 2;
    scanf("%d %d", &r, &c);
    //行数和列数, x方向是上下, y方向是左右
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    scanf("%d %d", &plants[i].x, &plants[i].y);
    //将水稻按x坐标从小到大排序, x坐标相同按y从小到大排序
    sort(plants, plants + n);
    for (i = 0; i < n - 2; i++){
        //plants[i]是第一个点
        for ( j = i + 1; j < n -1 ; j++) { //plants[j]是第二个点
            dX = plants[ j ].x - plants[i].x;
            dY = plants[ j ].y - plants[i].y;
            pX = plants[ i ].x - dX;
            pY = plants[ i ].y - dY;
            if (pX <= r && pX >= 1 && pY <= c && pY >= 1)
                continue;
                //第一点的前一点在稻田里,
                //说明本次选的第二点导致的x方向步长不合理(太小)
                // 取下一个点作为第二点
            if (plants[ i ].x + (max - 1)* dX > r)
                break;
            pY = plants[ i ].y + (max - 1) * dY;
            if ( pY > c || pY < 1)
                continue;
            steps = searchPath(plants[ j ], dX, dY);
            if (steps > max) max = steps;
        }
    }
        if( max == 2 ) max = 0;
        printf("%d\n", max);
}

bool operator < ( const PLANT & p1, const PLANT & p2)
{
if ( p1.x == p2.x )
return p1.y < p2.y;
return p1.x < p2.x ;
}

int searchPath(PLANT secPlant, int dX, int dY){
    PLANT plant;
    int steps;
    plant.x = secPlant.x + dX;
    plant.y = secPlant.y + dY;
    steps = 2;
    while (plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1) {
        if (! binary_search(plants, plants + n, plant)) {
            //每一步都必须踩倒水稻才算合理, 否则这就不是一条行走路径
            steps = 0;
            break;
        }
        plant.x += dX;
        plant.y += dY;
        steps++;
    }
    return(steps);
}

