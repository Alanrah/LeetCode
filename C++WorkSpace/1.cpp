#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<hashtable.h>
#include<unordered_map>
 using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash1;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];
            //if numberToFind is found in map, return them
		if (hash1.find(numberToFind) != hash1.end()&&hash1[numberToFind]!=i) {
                    //+1 because indices are NOT zero based
			result.push_back(hash1[numberToFind]);
			result.push_back(i);
			return result;
		}
            //number was not found. Put it in the map.
		hash1[numbers[i]] = i;
	}
	return result;
}
};
/*
这道题一看就知道用暴力搜索肯定没问题，而且猜到OJ肯定不会允许用暴力搜索这么简单的方法，
于是去试了一下，果然是Time Limit Exceeded，这个算法的时间复杂度是O(n^2)。
那么只能想个O(n)的算法来实现，整个实现步骤为：先遍历一遍数组，
建立map数据，然后再遍历一遍，开始查找，找到则记录index。
*/
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }
};
//暴力解析
class Solution2{
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    vector<int> result;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(numbers[i] + numbers[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
}
};
int main()
{
	int p[] = {3,3,2};
    std::vector<int> myvector( p, p + 3 );
    Solution S;
    vector<int> result=S.twoSum(myvector,5);
    cout<<result[0]<<"  "<<result[1];
}
