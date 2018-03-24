//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<iterator>
#include<map>
#include<hashtable.h>
#include<unordered_map>
#include<string>
using namespace std;
class Solution1 {
public:
    int FirstNotRepeatingChar(string str) {
        int result=0;
        int len = str.length();
        if(len==0) return result;
        map<char,int> chars;

        for(int i=0;i<len;i++){
            if(chars[str[i]])
                chars[str[i]]++;
            else
                chars.insert(pair<char, int>(str[i],1));  ;
        }
        map<char,int>::iterator it;
        it = chars.begin();
        while(it!=chars.end()){
            printf("%c %d\n",it->first,it->second);
            it++;
        }
        //printf(it->first);
        it = chars.begin();
        while(it!=chars.end()){
                result++;
            if(it->second == 1){
                return result;
            }
            printf("%d\n",result);
            it++;
        }
        return result;
    }
};
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        int* hashTable = new int[256];
        for(int i = 0;i<256;++i)
        {
            hashTable[i] = 0;
        }
        for(int i = 0;i<str.length();++i)
        {
            ++hashTable[str[i]];
        }
        for(int i = 0;i<str.length();++i)
        {
            if(hashTable[str[i]] == 1)
                return i;
        }

        return -1;

    }
};
int main(){
    Solution  s;
    string s1 = "VkNbwAEpXdXypOhtHDirNLgGENuLyWCMVIVmVEajxhkDwqrkrSwBBRJcjnXqksuqbqfkUZFSBwSajsKqBpx";
    int x=s.FirstNotRepeatingChar(s1);
    printf("x = %d",x);
}
