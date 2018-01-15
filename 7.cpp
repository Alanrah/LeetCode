#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char* turnover(char s[])
{
    int n=strlen(s);
        for(int i=0,j=n-1;i<j;i++,j--){
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
    return s;
}
class Solution1 {
public:
    int reverse(int x) {
        char *s,str[32];
        int a;
        if(x>=0)
        {
            sprintf(str,"%d",x);//Êý×Ö×ª»»Îª×Ö·û´®
            s=turnover(str);//·´×ª×Ö·û´®
            sscanf(s,"%d",&a);//×Ö·û´®×ª»»ÎªÊý×Ö
        }
        else
        {
            x*=(-1);
            sprintf(str,"%d",x);
            s=turnover(str);
            sscanf(s,"%d",&a);
            a=a*(-1);
        }
         return (a<INT_MIN || a>INT_MAX) ? 0 : a;
    }
};

class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x)
        {
            a=x%10+res*10;
            if(a/10!=res)
                return 0;
            res=a;
            x=x/10;
        }
         return res;
    }
};

int main()
{
    Solution S;
    int n=123;
    cout<<S.reverse(n)<<endl;
}
