#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
        return false;
        int i=0;
        stack<char>istack;
        istack.push('0');
        for(i=0;i<s.length();i++){
            if(s[i]=='{')
            istack.push(s[i]);
            else if(s[i]=='(')
            istack.push(s[i]);
            else if(s[i]=='[')
            istack.push(s[i]);
            else if(s[i]=='}'&&istack.top()=='{')
            istack.pop();
            else if(s[i]==']'&&istack.top()=='[')
            istack.pop();
            else if(s[i]==')'&&istack.top()=='(')
            istack.pop();
            else if(s[i]=='}'&&(istack.top()!='{'||istack.top()=='0'))
            return false;
            else if(s[i]==']'&&(istack.top()!='['||istack.top()=='0'))
            return false;
            else if(s[i]==')'&&(istack.top()!='('||istack.top()=='0'))
            return false;
        }
        if(istack.size()==1&&i==s.length())
        return true;

        return false;

    }
};

int main()
{
string s={"]"};
Solution S;
cout<<S.isValid(s)<<endl;


}
