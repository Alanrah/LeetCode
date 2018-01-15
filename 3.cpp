#include<stdio.h> 
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int n=s.length();
    	int i=0,j=0,maxLen=0;
    	bool exist[256] = { false };
    	while(j<n)
    	{
		if (exist[s[j]]) {  
		maxLen = max(maxLen, j-i);
		while(s[i]!=s[j])
		{
			exist[s[i]]=false;
			i++;
		}
    		
    		i++;
    		j++;	
    	}
        else
        {
        	exist[s[j]]=true;
        	j++;
        }
    }
    maxLen=max(maxLen,n-i);
    return maxLen;
}
};
int main()
{
	Solution S;
	int c=S.lengthOfLongestSubstring("acsdvervjdsbhefbhdadassafren");
	cout<<c<<endl;
	
} 
