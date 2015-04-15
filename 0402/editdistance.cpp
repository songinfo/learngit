
editdistance

方法一：简单递归搜索：

/* 递归搜索 */
int calDistance1(char *ptrX, int xbeg, int xend, char *ptrY, int ybeg, int yend)
{
    if(xbeg > xend)
    {
        if(ybeg > yend)
            return 0;
        else
            return yend - ybeg + 1;
    }
    if(ybeg > yend)
    {
        if(xbeg > xend)
            return 0;
        else
            return xend - xbeg + 1;
    }
    if(ptrX[xend] == ptrY[yend])
    {
        return calDistance1(ptrX,xbeg,xend-1,ptrY,ybeg,yend-1);
    }else
    {
        int t1 = calDistance1(ptrX,xbeg,xend-1,ptrY,ybeg,yend);
        int t2 = calDistance1(ptrX,xbeg,xend,ptrY,ybeg,yend-1);
        int t3 = calDistance1(ptrX,xbeg,xend-1,ptrY,ybeg,yend-1);
        t1 = t1 < t2 ? t1 : t2;
        return (t1 < t3 ? t1 : t3) + 1;
    }
}
方法二：递归+备忘录：

/* 编辑距离
 * 设每个字符串长度不超过 30
*/
 
/* 存储子问题的解 i,j表示X，Y长度
 * dp[i][j]表示X[0-i)与Y[0-j)的编辑距离
*/
int dp[31][31];
/* 自顶向下 & 备忘录 */
int calDistance2(char *ptrX, int xbeg, int xend, char *ptrY, int ybeg, int yend)
{
    if(xend == 0)
    {
        if(yend == 0)
            return 0;
        else
            return yend - ybeg + 1;
    }
    if(yend == 0)
    {
        if(xend == 0)
            return 0;
        else
            return xend - xbeg + 1;
    }
    if(ptrX[xend-1] == ptrY[yend-1])
    {
        if(dp[xend-1][yend-1] == 0)
        {
            dp[xend-1][yend-1] = calDistance2(ptrX,xbeg,xend-1,ptrY,ybeg,yend-1);
        }
        return dp[xend-1][yend-1];
    }else
    {
        int t1, t2, t3;
        if(dp[xend-1][yend] == 0)
        {
            dp[xend-1][yend] = calDistance2(ptrX,xbeg,xend-1,ptrY,ybeg,yend);
        }
        t1 = dp[xend-1][yend];
        if(dp[xend][yend-1] == 0)
        {
            dp[xend][yend-1] = calDistance2(ptrX,xbeg,xend,ptrY,ybeg,yend-1);
        }
        t2 = dp[xend][yend-1];
        if(dp[xend-1][yend-1] == 0)
        {
            dp[xend-1][yend-1] = calDistance2(ptrX,xbeg,xend-1,ptrY,ybeg,yend-1);
        }
        t3 = dp[xend-1][yend-1];
        t1 = t1 < t2 ? t1 : t2;
        return (t1 < t3 ? t1 : t3) + 1;
    }
}
方法三：自底向上DP：

/* 编辑距离
 * 设每个字符串长度不超过 30
*/
 
/* 存储子问题的解 i,j表示X，Y长度
 * dp[i][j]表示X[0-i)与Y[0-j)的编辑距离
*/
int dp[31][31];
char X[31];
char Y[31];
/* 自底向上 DP */
int calDistance3(char *ptrX, int xlen, char *ptrY, int ylen)
{
    int i, j;
    for(i = 1; i <= xlen; ++i)
    {
        dp[i][0] = i;
    }
    for(j = 1; j <= ylen; ++j)
    {
        dp[0][j] = j;
    }
    for(i = 1; i <= xlen; ++i)
    {
        for(j = 1; j <= ylen; ++j)
        {
            if(ptrX[i-1] == ptrY[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }else
            {
                int t1 = dp[i-1][j];
                t1 = t1 < dp[i][j-1] ? t1 :dp[i][j-1];
                t1 = t1 < dp[i-1][j-1] ? t1 : dp[i-1][j-1];
                dp[i][j] = t1 + 1;
            }
        }
    }
    return dp[xlen][ylen];
}
给出测试用例：

#include <iostream>
using namespace std;
void main()
{
    cin.getline(X,30);
    cin.getline(Y,30);
 
    int xlen = strlen(X);
    int ylen = strlen(Y);
 
    printf("%d\n",calDistance1(X,0,xlen-1,Y,0,ylen-1));
    //printf("%d\n",calDistance2(X,0,xlen,Y,0,ylen));
    printf("%d\n",calDistance3(X,xlen,Y,ylen));
}

