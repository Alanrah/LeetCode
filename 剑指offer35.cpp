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
    int InversePairs(vector<int> data) {
        int p=0,len=data.size();
        if(len==0) return p;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++)
                if(data[i]>data[j])
                    p++;
        }
        return p%1000000007;
    }
};
int main(){
    Solution  s;
    vector<int> s1 = {1,2,3,4,5,6,7,0};
    int x=s.InversePairs(s1);
    printf("x = %d",x);
}
