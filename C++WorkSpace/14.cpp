#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
#define LL 1000
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        for(int j=0; strs.size()>0; prefix+=strs[0][j],j++)
            for(int i=0; i<strs.size(); i++)
                {
                    cout<<i<<j<<endl;;
                    if(j>strs[i].size()||(i>0&&strs[i][j]!=strs[i-1][j]))
                        return prefix;
                }
        return prefix;
    }
};

int main()
{
    Solution1 S;
    vector<string>strs{""};
    cout<<S.longestCommonPrefix(strs);

}
