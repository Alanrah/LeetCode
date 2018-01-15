#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution1 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode*p=head;
        if(l1==NULL||l2==NULL){
            head=(l1=NULL)?l2:l1;
            return head;
        }
        while(l1&&l2) {
            if(l1->val<=l2->val){
                p->val=l1->val;
                p->next=NULL;
                p=p->next;
                l1=l1->next;
            }
            else{
                p->val=l2->val;
                p->next=NULL;
                p=p->next;
                l2=l2->next;
            }
        }
        if(l1||l2){
            p=(l1=NULL)?l2:l1;
        }
        //head=p;
        return head;
    }
};

int main()
{
    ListNode* l1,*p1;//HEAD1
    ListNode* l2,*p2;
    l2=p2;
    l1=p1;
    Solution S;
    int i=2;

    while(i<11){
            if(i%2==0){
           ListNode *p = new ListNode(i);
            cout<<i<<endl;
            l1->next=p;
            cout<<i<<endl;
            l1=p;
            cout<<i<<endl;
            }
            else{
            ListNode *q= new ListNode(i);
            cout<<i<<endl;
            l2->next=q;
            cout<<i<<endl;
            l2=q;
            }
            i++;
    }
l1->next=NULL;
l2->next=NULL;
    l1=p1;
    l2=p2;

        while(p1!=NULL){
           cout<<"ccccc"<<endl;
        cout<<p1->val<<"->";
        p1=p1->next;
    }
    while(p2){
        cout<<p2->val<<"->";
        p1=p2->next;
    }
cout<<"ccccccccc"<<endl;
    ListNode *head=S.mergeTwoLists(p1,p2);
    while(head){
        cout<<head->val<<"->";
        head=head->next;
    }

}
