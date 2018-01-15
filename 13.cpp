#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        int num=0;
        for(int i=0;i<s.length();)
        {
            if(s[i]=='M'){num+=1000;i++; }
            else if(s[i]=='C'&&s[i+1]!='M'&&s[i+1]!='D'){num+=100;i++;}
            else if(s[i]=='C'&&s[i+1]=='M'){num+=900;i+=2;}
            else if(s[i]=='D')//D
            {num+=500;i++;}
            else if(s[i]=='C'&&s[i+1]=='D')//CD
            {
                num+=400;
                i+=2;cout<<"CD"<<endl;
            }
            else if(s[i]=='X'&&s[i+1]!='C'&&s[i+1]!='L')//X
            {
                num+=10;
                i++;cout<<"X"<<endl;
            }
            else if(s[i]=='X'&&s[i+1]=='C')//XC
            {
                num+=90;
                i+=2;cout<<"XC"<<endl;
            }
            else if(s[i]=='X'&&s[i+1]=='L')//XL
            {
                num+=40;
                i+=2;cout<<"XL"<<endl;
            }
            else if(s[i]=='L')//L
            {
                num+=50;cout<<"L"<<endl;
                i++;
            }
            else if(s[i]=='I'&&s[i+1]!='X'&&s[i+1]!='V')//I
            {
                num+=1;cout<<"I"<<endl;
                i++;
            }
            else if(s[i]=='V')//V
            {
                num+=5;cout<<"V"<<endl;
                i++;
            }
            else if(s[i]=='I'&&s[i+1]=='V')//IV
            {
                num+=4;cout<<"IV"<<endl;
                i+=2;
            }
            else if(s[i]=='I'&&s[i+1]=='X')//IX
            {
                num+=9;cout<<"IX"<<endl;
                i+=2;
            }
        }
        return num;
    }
};


int main()
{
    string str="MMCCCXCIX";
    Solution s;
    cout<<s.romanToInt(str)<<endl;
}
