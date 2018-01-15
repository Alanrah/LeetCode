#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<windows.h>
using namespace std;

class Solution {
public:
    void run() {
        int i=0;
        while(true)
        {
            if(i<10000000)
                i++;
            else
            {
                Sleep(10);
                i=0;
            }
        }
    }
};

struct A
{
    unsigned char a:4;
    unsigned char b:4;
}i;
int main()
{
    Solution s;
    cout<<sizeof(int)<<" int "<<sizeof(long)<<" long "<<sizeof(LONGLONG)<<" longlong "<<sizeof(double)<<" double "<<sizeof(char)<<" char "<<sizeof(string)<<" string "<<endl;
    cout<<sizeof(DWORD)<<" DWORD "<<sizeof(DWORD32)<<" DWORD32 "<<sizeof(DWORD64)<<" DWORD64 "<<endl;
    cout<<sizeof(_TCHAR)<<sizeof(bool)<<endl;
    //s.run();
    //cout<<sizeof(i.a)<<sizeof(i.b)<<endl;
    for(i.a=1;i.a<9;i.a++)
        for(i.b=1;i.b<9;i.b++)
        {
            if(i.a%3==i.b%3)
            continue;
            printf("A= %d,B= %d \n",i.a,i.b);
        }

}
