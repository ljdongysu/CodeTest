#include<bits/stdc++.h>
using namespace std;
//const int N=205;
//int w[N][N];
//int la[N],lb[N];
//bool va[N],vb[N];
//int match[N];
//int delta,n;
//void read() {
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++)
//        for(int j=1;j<=n;j++)
//            scanf("%d",&w[i][j]);
//}
//bool dfs(int x) {
//    va[x]=1;
//    for(int y=1;y<=n;y++)
//        if(!vb[y])
//            if(la[x]+lb[y]-w[x][y]==0) {
//                vb[y]=1;
//                if(!match[y]||dfs(match[y])) {
//                    match[y]=x;
//                    return true;
//                }
//            }
//            else
//                delta=min(delta,la[x]+lb[y]-w[x][y]);
//    return false;
//}
//int KM() {
//    for(int i=1;i<=n;i++) {
//        la[i]=-(1<<30);
//        lb[i]=0;
//        for(int j=1;j<=n;j++)
//            la[i]=max(la[i],w[i][j]);
//    }
//    for(int i=1;i<=n;i++)
//        while(true) {
//            memset(va,0,sizeof(va));
//            memset(vb,0,sizeof(vb));
//            delta=1<<30;
//            if(dfs(i))
//                break;
//            for(int j=1;j<=n;j++) {
//                if(va[j])
//                    la[j]-=delta;
//                if(vb[j])
//                    lb[j]+=delta;
//            }
//        }
//    int ans=0;
//    for(int i=1;i<=n;i++)
//    {
//        ans+=w[match[i]][i];
//        std::cout<< "i: " << i << " , match[i][i]: " << match[i] << std::endl;
//    }
//
//    return ans;
//}
//void write() {
//    printf("%d\n",KM());
//}
//int main() {
//    read();
//    write();
//}


int M, N;            //M, N分别表示左、右侧集合的元素数量
float Map[10][10]; //邻接矩阵存图
int p[10];         //记录当前右侧元素所对应的左侧元素
bool vis[10];      //记录右侧元素是否已被访问过
bool match(int i)
{
    for (int j = 1; j <= N; ++j)
        if (Map[i][j] > 0 && !vis[j]) //有边且未访问
        {
            vis[j] = true;                 //记录状态为访问过
            if (p[j] == 0 || match(p[j])) //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
            {
                p[j] = i;    //当前左侧元素成为当前右侧元素的新匹配
                return true; //返回匹配成功
            }
        }
    return false; //循环结束，仍未找到匹配，返回匹配失败
}
int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= M; ++i)
    {
        memset(vis, 0, sizeof(vis)); //重置vis数组
        if (match(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    M = 3, N = 3;
    Map[1][1] = 0.2;
    Map[1][2] = 0.5;
    Map[1][3] = 0.7;
    Map[2][1] = 0.0;
    Map[2][2] = 0;
    Map[2][3] = 1;
    Map[3][1] = 1;
    Map[3][2] = 0.1;
    Map[3][3] = 0;
    Hungarian();
    std::cout << "p[1]: " << p[1] << " , " << "p[2]: " << p[2] <<" , " << p[3] << std::endl;
}