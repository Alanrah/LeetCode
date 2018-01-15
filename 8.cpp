#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
public:
    int myAtoi(string str) {
    long result = 0;
    int indicator = 1;
            if(str.empty())
            return 0;
    for(int i = 0; i<str.size();)
    {
        i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
        while('0'<= str[i] && str[i] <= '9')
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;
        }
        return result*indicator;
    }
}
};
class Solution1{
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        int i=0,j=0,a=0,b=0,n=str.length();
        char s[256]={'\0'},c[256]={'\0'};
        for(i=0;i<n;i++)
        {
            if(j>1&&(str[i]<48||str[i]>57))
                    break;
            if((str[i]>=48&&str[i]<=57)||str[i]==45||str[i]==43)
              {
                  if((j==0||j==1)&&(str[i]==45||str[i]==43))
                  {
                      s[j]=str[i];
                      j++;
                  }
                  else
                  {
                      s[j]=str[i];
                      j++;
                  }
              }
                cout<<i<<"   "<<j<<endl;
        }
        cout<<"out"<<endl;
        s[j]='\0';
        if((s[0]==43&&s[1]==45)||(s[0]==45&&s[1]==43))
            return 0;
        sscanf(s,"%d",&a);//string to int
        sprintf(c,"%d",a);
        sscanf(c,"%d",&b);
        cout<<"s="<<s<<",c="<<c<<endl;
        if(a==b)
            return a;
        else
            return (s[0]=='-')?INT_MIN:INT_MAX;
    }
};

int main()
{
    Solution S;
    string s="    2147483648";
    cout<<S.myAtoi(s)<<endl;
}
