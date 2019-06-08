/*
http://poj.org/problem?id=1163
*/
////�ݹ�ⷨ��ȱ���д����ظ����㣬ʱ��ᳬʱ��
//#include<iostream>
//#include<algorithm>
//#define MAX 101
//using namespace std;
//int D[MAX][MAX];
//int n;
//int MAX_sum(int i,int j){
//    if (i==n)
//        return D[i][j];
//    int x = MAX_sum(i+1,j)+D[i][j];
//    int y = MAX_sum(i+1,j+1)+D[i][j];
//    return max(x,y);
//}
//int main(){
//    int i,j;
//    cin>>n;
//    for(i=1;i<=n;i++){
//        for(j=1;j<=i;j++){
//            cin>>D[i][j];
//        }
//    }
//    cout<<MAX_sum(1,1)<<endl;
//}

////�ݹ�ⷨ����һ�������洢ÿ���ڵ��ֵ�������ظ�����
//#include<iostream>
//#include<algorithm>
//#define MAX 101
//using namespace std;
//int D[MAX][MAX];
//int max_sum[MAX][MAX];
//int n;
//int MAX_sum(int i,int j){
//    if (max_sum[i][j] != -1)
//        return max_sum[i][j];
//    if (i==n)
//        return D[i][j];
//    int x = MAX_sum(i+1,j)+D[i][j];
//    int y = MAX_sum(i+1,j+1)+D[i][j];
//    max_sum[i][j] = max(x,y);
//    return max(x,y);
//}
//int main(){
//    int i,j;
//    cin>>n;
//    for(i=1;i<=n;i++){
//        for(j=1;j<=i;j++){
//            cin>>D[i][j];
//            max_sum[i][j]=-1;
//        }
//    }
//    cout<<MAX_sum(1,1)<<endl;
//}

////�ݹ�ת�ɵ���
//#include<iostream>
//#include<algorithm>
//#define MAX 101
//using namespace std;
//int D[MAX][MAX];
//int max_sum[MAX][MAX];
//int n;
//int main(){
//    int i,j;
//    cin>>n;
//    for(i=1;i<=n;i++){
//        for(j=1;j<=i;j++){
//            cin>>D[i][j];
//        }
//    }
//    for(i=1;i<=n;i++){
//        max_sum[n][i]=D[n][i];
//    }
//    for(i=n-1;i>=1;i--){
//        for (j=1;j<=i;j++){
//            max_sum[i][j] = max(max_sum[i+1][j],max_sum[i+1][j+1])+D[i][j];
//        }
//    }
//    cout<<max_sum[1][1]<<endl;
//}

//�ݹ�ת�ɵ��ƣ����пռ��Ż�
#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int *max_sum;
int n;
int main(){
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cin>>D[i][j];
        }
    }
    max_sum = D[n];
    for(i=n-1;i>=1;i--){
        for (j=1;j<=i;j++){
            max_sum[j] = max(max_sum[j],max_sum[j+1])+D[i][j];
        }
    }
    cout<<max_sum[1]<<endl;
}
