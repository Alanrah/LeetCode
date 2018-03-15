
#include <iostream>
#include <stack>
#include<vector>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV,int length) {
        if(pushV.size() == 0)
            return false;
        stack<int>s;
        int size1 = pushV.size();
        int i=0,j=0,k=0,x=0;
        while(i<size1 &&j<size1){
            if(pushV[i]==popV[j]){
                for(k=x;k<i;k++)
                     s.push(pushV[k]);
                x=i+1;
                i++;
                j++;
            }
            else
                i++;
        }
        for(int z=j;z<size1;z++){
                cout<<" index  popV[index] "<<popV[z]<<" s.top() "<<s.top()<<endl;
            if(popV[z]!=s.top())
                return false;
            else
            s.pop();
        }
        return true;
    }
};

int main()
{
    vector<int>A={1,2,3,4,5};
    vector<int>B={4,3,5,1,2};
    Solution S;

    cout << S.IsPopOrder(A,B,5) << endl;
    return 0;
}
