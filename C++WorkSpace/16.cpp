#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
//这个sum的初始值怎么设置
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        if(nums.empty()||nums.size()<3)return 0;
        int i=0,front=0,back=0,sum=nums[0]+nums[1]+nums[2],plus;
        for(i=0;i<nums.size()-2;i++)
        {
            front=i+1;
            back=nums.size()-1;
            while(front<back)
            {
                plus=nums[i]+nums[front]+nums[back];
                if(plus==target)return plus;
                if(abs(plus-target)<abs(sum-target))
                    sum=plus;
                if(plus<target)
                front++;
                else
                back--;
            }
        }
        return sum;
    }
};
class Solution1{
    public:
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    int closest = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if(first > 0 && nums[first] == nums[first-1]) continue;
        int second = first+1;
        int third = nums.size()-1;
        while(second < third) {
            int curSum = nums[first]+nums[second]+nums[third];
            if(curSum == target) return curSum;
            if(abs(target-curSum)<abs(target-closest)) {
                closest = curSum;
            }
            if(curSum > target) {
                --third;
            } else {
                ++second;
            }
        }
    }
    return closest;
}
};
int main()
{
    Solution  s;
    int target=82;
    vector<int>nums={1,2,4,8,16,32,64,128};
    cout<<s.threeSumClosest(nums,target)<<endl;
}
