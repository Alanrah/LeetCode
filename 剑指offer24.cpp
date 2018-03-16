#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<list>
#include<iterator>
#include<queue>
#include<stack>
#include<algorithm>
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
    vector<vector<int>> result;
    vector<int>temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root != NULL)
        findOnePath(root,expectNumber);
        return result;
    }

    void findOnePath(TreeNode* root,int expectNumber){
        temp.push_back(root->val);
        if(expectNumber - root->val==0 && root->right ==NULL && root->left == NULL)
            result.push_back(temp);
        if(root->left != NULL)findOnePath(root->left,expectNumber-root->val);
        if(root->right != NULL)findOnePath(root->right,expectNumber-root->val);
        temp.pop_back();

    }

void CreateBiTree(TreeNode* &T) //这里的引用 & 必须，要不然会报未初始化变量
    {
        int num = 0;
        cin >> num;
        if (num == 0) return;
        else
        {
            T = new TreeNode(num);
            CreateBiTree(T->left);
            CreateBiTree(T->right);
        }
    }
};

int main()
{
    Solution so;
    TreeNode *T;
    so.CreateBiTree(T);
    cout << "创建二叉树成功！"<<endl;
    vector<vector<int>> vec;
    vec = so.FindPath(T,1);

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        for (auto i = (*it).begin(); i != (*it).end(); i++)
            cout << *i << "  ";
        cout << endl;
    }
    return 0;
}
