#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}//Îö¹¹º¯Êý
 };
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        return head;
        ListNode * p=head;
        ListNode * q=head;
        for(int i=1;i<n;i++)
        p=p->next;
        if(p->next==NULL)//删除第一个
        return head->next;

        while(p->next){
            q=q->next;
            p=p->next;
        }
        if(!(p-q)){//删除倒数第一个
        cout<<"afsdfgs"<<endl;
            q->next=NULL;
            return head;
        }
        q=q->next;
        return head;

    }
};
class Solution//双指针思想
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode** t1 = &head, *t2 = head;
        for(int i = 1; i < n; ++i)
        {
            t2 = t2->next;
        }
        while(t2->next != NULL)
        {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};

int main()
{


    Solution s;
    ListNode* h=s.removeNthFromEnd(head,5);
    while(h){
        cout<<h->val<<endl;
        h=h->next;
    }
return 0;
}
