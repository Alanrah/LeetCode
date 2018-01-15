#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        char s[1000];
        sprintf(s,"%d",x);
       // cout<<x<<"  "<<s<<endl;
        if(!x)
            return false;
        int n=strlen(s);
        for(int i=0;i<n;)
        {
            if(s[i]==s[n-i-1])
                i++;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(567658)<<endl;;

}
