#include <stdio.h>
#include <iostream>
#include <vector>
#include<stdlib.h>
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p,*q;
        vector<int>a;
        p=pHead;
        q=pHead;
        while(p!=NULL){
            a.push_back(p->val);
            p=p->next;
        }
        int i=a.size()-1;
        while(i>=0){
            q->val = a[i];
        cout<<q->val<<endl;
            q=q->next;
            i--;
            if(i==0){
                q->val = a[0];
                q->next=NULL;
                return pHead;
            }
        }

    }
};


int main()
{

    ListNode* head = NULL;
    ListNode* temp = NULL;
    ListNode* newNode = NULL;
    int i = 0;
    Solution s;


    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    head->val = 1;

    temp = head;

    for(i = 2; i < 6; i++)
    {
        newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->next = NULL;
        newNode->val = i;

        temp->next = newNode;
        temp = newNode;


    }

    temp = head;
    while(temp)
    {
        cout << temp->val << "  " ;
        temp = temp->next;
    }
    cout <<"hahahah1"<< endl;

    head = s.ReverseList(head);
cout <<"hahahah2"<< endl;
    temp = head;
    while(temp)
    {
        cout << temp->val << "  " ;
        temp = temp->next;
    }
    cout << endl;


    return 0;
}
