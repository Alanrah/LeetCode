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
�����һ����֪���ñ��������϶�û���⣬���Ҳµ�OJ�϶����������ñ���������ô�򵥵ķ�����
����ȥ����һ�£���Ȼ��Time Limit Exceeded������㷨��ʱ�临�Ӷ���O(n^2)��
��ôֻ�����O(n)���㷨��ʵ�֣�����ʵ�ֲ���Ϊ���ȱ���һ�����飬
����map���ݣ�Ȼ���ٱ���һ�飬��ʼ���ң��ҵ����¼index��
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
//��������
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
