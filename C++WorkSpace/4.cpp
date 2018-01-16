#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> sum;
        // 复制nums1到数组中
        for(int i=0; i<m; i++)
        {
            sum.push_back(nums1[i]);
        }
        // 复制nums2到数组中
        for(int i=0; i<n; i++)
        {
            sum.push_back(nums2[i]);
        }
        // 对合并的数组进行排序
        sort(sum.begin(), sum.end());
        // 返回中位数
        return (m+n)%2 ? (double)sum.at((m+n)/2) : (sum.at((m+n-1)/2) + sum.at((m+n)/2))/2.0;
    }
};
int main()
{
	Solution S;
	int num3[]={1,2};
	int num4[]={3,4};
	vector<int>num1;
	vector<int>num2;
	int len1=sizeof(num3) / sizeof(num3[0]);
	int len2=sizeof(num4) / sizeof(num4[0]);
	for(int i=0;i<len1;i++)
    {
        num1.push_back(num3[i]);
    }
    for(int i=0;i<len2;i++)
    {
        num2.push_back(num4[i]);
    }
	double c=S.findMedianSortedArrays(num1,num2);
	cout<<c<<endl;

}
