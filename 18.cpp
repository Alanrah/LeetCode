#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//四个最小数比target大
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});//-----
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);//去重
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};
class Solution{//无去重
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
    vector<vector<int> > res;
    std::sort(nums.begin(), nums.end());
    int i=0,j=0;
    for (i = 0,j=nums.size()-1; i < nums.size()/2,j>i+2; i++,j--) {
        int temp = target-nums[i]-nums[j];
        int front = i + 1;
        int back = j - 1;
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
             while (j- 1 < i && nums[j- 1] == nums[j])
            j--;
        while (front < back) {
            int sum = nums[front] + nums[back];
            // Finding answer which start from number nums[i]
            if (sum < temp)
                front++;
            else if (sum > temp)
                back--;
            else {
                vector<int> triplet(4, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                triplet[3]=nums[j];
                res.push_back(triplet);
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && nums[front] == triplet[1])//排序之后，重复的数字在一起
                    front++;
                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && nums[back] == triplet[2])
                back--;
            }
        }
        // Processing duplicates of Number 1
    }
    return res;
}
};
int main()
{
    Solution s;//-1, 0, 1, 2, -1, -4
    vector<int>nums={-3,-1,0,2,4,5};
    int target=0;
    vector<vector<int>>result;

    result=s.fourSum(nums,target);
    if(result.empty())
    cout<<"jinjinjin"<<endl;;
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++)
        cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
