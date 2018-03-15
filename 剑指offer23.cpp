#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<list>
#include<iterator>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        bool result=false;
        int length=sequence.size()-1;
        if(sequence.empty() || length <= 0)
            return false;
        result = judge(sequence,0,length) ;
        return result;
    }
    bool judge(vector<int> sequence,int up,int down){
        if(up>=down)
            return true;
        int i=up,j=down;

        while(i<=j){
            if(sequence[i]>sequence[j]){
                for(int k=i;k<j;k++)
                    if(sequence[k]<sequence[j])
                        return false;
                return judge(sequence,up,i-1) && judge(sequence,i,down-1);
            }
            else
               i++;
        }
    }
};

int main()
{

    Solution so;

    vector<int> tree1 = { 5,7, 6, 9, 11, 10, 8 };
    vector<int> tree2 = { 7,4,6,5 };

    bool result1 = so.VerifySquenceOfBST(tree1);
    cout << "tree1结果是：" ;
    cout << result1 << endl;
    cout << endl;

    bool result2 = so.VerifySquenceOfBST(tree2);
    cout << "tree2结果是：";
    cout << result2 << endl;
    cout << endl;
    return 0;
}
