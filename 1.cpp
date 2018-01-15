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
int main()
{
	int p[] = {3,3};
    std::vector<int> myvector( p, p + 2 );
    Solution S;
    vector<int> result=S.twoSum(myvector,6);
    cout<<result[0]<<"  "<<result[1];
}
