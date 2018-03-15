#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include <vector>
#include<exception>
#include <initializer_list>
#include<stack>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
    val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        unsigned int a=1;
        ListNode* p = pListHead;
        while(p->next!=NULL){
            p = p->next;
            a++;
        }
       unsigned int n=0;
        p = pListHead;
        while(n<=a){
            p=p->next;
            n++;
            if(n==(a-k+1))
                return p;
        }
    }
};


int main()
{
    int num;
    Solution so;
    cout << "������ͷ���:" ;
    cin >> num;
    ListNode pListHead(num);

    ListNode listNodeCopy = pListHead;


    cout << "������������Ԫ��:"; // �˶����������⣬�д���һ������
    while (cin>>num)
    {
        ListNode temp(num);
        pListHead.next = &temp;
        pListHead = temp;
        if (temp.val == 4)
            break;
    }
    pListHead = listNodeCopy;

    cout << "�����������Ԫ���ǣ�" << endl;

    while (&pListHead!=NULL)
    {
        cout << pListHead.val << "  ";
        pListHead = *pListHead.next;
    }
    cout<<"����";
    ListNode result = *(so.FindKthToTail(&pListHead, 1));

    cout << "������" <<1<<"��Ԫ���ǣ�"<< result.val<<endl;


    return 0;
}
