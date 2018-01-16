/*
USER_ID: icpc#2017pre2016140991
PROBLEM: 1471
SUBMISSION_TIME: 2017-04-02 16:24:59
*/
#include<iostream>
#include<memory.h>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<algorithm>
typedef long long LL;
const LL mod=1000000007;
const int N=2;
using namespace std;
struct Matrix
{
    LL m[N][N];
};
Matrix A=
{
    2,3,
    1,0
};
Matrix I=
{
    1,0,
    0,1
};
Matrix multi(Matrix a,Matrix b)
{
    Matrix c;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<N;k++)
                c.m[i][j]=c.m[i][j]%mod+((a.m[i][k]%mod)*(b.m[k][j]%mod))%mod;
            c.m[i][j]%=mod;
        }
    }
    return c;
}

Matrix power(Matrix A,int k)
{
    Matrix ans=I,p=A;
    while(k)
    {
        if(k&1)
        {
            ans=multi(ans,p);
            k--;
        }
        k=k/2;
        p=multi(p,p);
    }
    ans.m[0][0]=ans.m[0][0]%mod+ans.m[0][1]%mod;
    ans.m[0][0]=ans.m[0][0]%mod;
    return ans;
}
int main()
{
    int n;
    while(cin>>n){
        Matrix ans =power(A,n-1);
        printf("%lld\n",ans.m[0][0]);
    }
    return 0;
}
