#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution1 {
    public:
    bool matchFirst(const char *s, const char *p){
        return (*p == *s || (*p == '.' && *s != '\0'));
    }

bool isMatch(const char *s, const char *p) {
	if (*p == '\0')
        return *s == '\0';	//empty

	if (*(p + 1) != '*')
        {//without *
		if(!matchFirst(s,p))
            return false;
		return isMatch(s + 1, p + 1);
	}
	else
        { //next: with a *
    	if(isMatch(s, p + 2))
            return true;    //try the length of 0
		while ( matchFirst(s,p) )       //try all possible lengths
			if (isMatch(++s, p + 2))return true;
	}
}
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return false;
        int n=s.length(),i=0,j=0;
        for(i=0,j=0;i<n;)
        {
        if(p[j+1]!='*')
            {
            if(s[i]==p[j]||p[j]=='.')
            {
                i++;
                j++;
            }
            else
                return false;
            }
          else if(p[j+1]=='*'&&(s[i]==p[j]||p[j]=='.'))
          {
              if(s[i]==p[j+2])
              {
                  i++;
                  j+=2;
              }
              else
              {
                  if(s[i]!=p[j+2])
                    i++;
              }
          }
          else
            return false;
        }
        return true;
    }
};

class Solution {
    public:
    bool isMatch(string s, string p) {
    return helper(s,p,0,0);
}
 bool helper(string s, string p, int i, int j)
{
    if(j==p.length())
        return i==s.length();

    if(j==p.length()-1 || p[j+1]!='*')
    {
        if(i==s.length()|| s[i]!=p[j] && p[j]!='.')
            return false;
        else
            return helper(s,p,i+1,j+1);
    }
    //p.charAt(j+1)=='*'
    while(i<s.length() && (p[j]=='.' || s[i]==p[j]))
    {
        if(helper(s,p,i,j+2))
            return true;
        i++;
    }
    return helper(s,p,i,j+2);
}
};
int main()
{
    Solution s;
    cout<<(bool)s.isMatch("abcd",".*")<<endl;

}
