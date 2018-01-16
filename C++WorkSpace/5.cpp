#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
bool reallyis(string s)
{
    int len=s.length();
    for(int i=0;i!=len/2;i++)
    {
        if(s[i]!=s[len-i-1])
            return false;
    }
    return true;
}

class Solution1 {  //O(n^2)
public:
    string longestPalindrome(string s) {
        if(s.length()==0)
            return NULL;
        int maxLen=1;
        string result=s.substr(0,1);
        cout<<"maxLen="<<maxLen<<"  result is "<<result<<"  lenth is"<<s.length()<<endl;

        for(int i=0;i<s.length();i++)
            for(int j=i+1;j<s.length()+1;j++)
        {
            if(reallyis(s.substr(i,j-i))&&(j-i)>maxLen)
            {
                maxLen=j-i;
                result=s.substr(i,j-i);// //获得字符串s中 从第i位开始的长度为j-i的字符串
                cout<<"i="<<i<<"  j="<<j<<"  result is"<<result<<endl;
            }
            cout<<"i="<<i<<"  j="<<j<<endl;
        }
        cout<<" eventually result is"<<result<<"  len is "<<result.length()<<endl;
        return result;

    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
    int len = s.length();
    int i, j, m = 0, max = 0, left, right;
    m = len;
    for(i=0; i<m; i++)  //以i为中心，判断是否为回文串
    {
        for(j=0; i-j>=0 && i+j<m; j++)  //长度为奇数
        {
            if(s[i-j] != s[i+j])
                break;
            if(j*2+1 > max){
                max = j * 2 + 1;
                left = i-j;
                right = i+j;
            }}
        for(j=0; i-j>=0 && i+j+1<m; j++) {//长度为偶数
            if(s[i-j] != s[i+j+1])
                break;
            if(j*2+2 > max){
                max = j * 2 + 2;
                left = i-j;
                right = i+j+1;
            }}}
    string sub;
    for(i=left; i<=right; i++)
        sub += s[i];
    return sub;
    }};
int main()
{
    Solution2 S;
    string s="aaaaaaaaaaaaaaaaaaa";
    cout<<s.length();
    cout<<S.longestPalindrome(s)<<endl;
}
