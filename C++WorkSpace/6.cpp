#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        int step=1,row=0;
       // cout<<s<<"  "<<numRows<<s.length()<<endl;
        string *str=new string [numRows];
        for(int i=0;i<s.length();i++)
        {
            str[row]+=s[i];
            //str[row].push_back(s[i]);
            if(row==0)
                step=1;
            else if(row==numRows-1)
                step= -1;
            //else{}
            row+=step;
        }
        s.clear();
        for(int i=0;i<numRows;++i)
        {
            s.append(str[i]);
            cout<<"µÚ"<<i<<"ÐÐ== " << str[i]<<endl;
        }
        delete []str;
        return s;
    }
};

int main()
{
    string s="PAYPALISHIRING";
    int n=3;
    Solution S;
    cout<<S.convert(s,n)<<endl;

}
