#include<stdio.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
 using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *p2=NULL,*p1=NULL;
        ListNode* tail = new ListNode(0);
        ListNode* pr = tail;
    cout<<"   sasdvavsdsav   "<<endl;
        for(p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1 = p1->next, p2 = p2->next)
        {
            int sum=p1->val+p2->val+carry;
            //pr->val=sum%10;
            pr->next = new ListNode(sum% 10);
            carry=sum/10;
            pr=pr->next;
        }
        for(ListNode *p = (p1 == NULL ? p2 : p1); p != NULL; p = p->next)   //处理两个链表中未处理完的链表剩余节点
        {
            int sum =p->val+carry;
            //pr->val=sum%10;
            pr->next = new ListNode(sum % 10);
            pr= pr->next;
            carry = sum / 10;
        }

        if(carry != 0)//如果最后还有进位，必定是1
        {
            pr->next = new ListNode(carry);
        }
        return tail->next;
    }

};

class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *pre_head = new ListNode(0);
		ListNode *pre_head_back = pre_head;
		int add = 0;
		int l1_value, l2_value;
		while (add || l2 || l1) {
			l1 ? (l1_value = l1->val, l1 = l1->next) : (l1_value = 0,l1);
			l2 ? (l2_value = l2->val, l2 = l2->next) : (l2_value = 0, l2);
			pre_head->next = new ListNode(0);
			pre_head = pre_head->next;
			if (add)
				l2_value += 1;
			add = (l2_value + l1_value) / 10;
			pre_head->val = (l2_value + l1_value) % 10;
		}
		return pre_head_back->next;
	}
};

int main()
{
    ListNode *l1=new ListNode(0);
    ListNode *l2=new ListNode(0);
    ListNode *p=l1;
    ListNode *p1=l2;
int num1[]={2,4,3};
int num2[]={};
    cout<<"   sasdvavsdsav   "<<endl;
    p->val=2;
    p=p->next;
    p->val=4;
    p=p->next;
    p->val=3;
    p->next=NULL;

    cout<<"   sasdvavsdsav   "<<endl;
    p1->val=5;
    p1=p->next;
    p1->val=6;
    p1=p->next;
    p1->val=4;
    p1->next=NULL;

    Solution S;
    cout<<"   sasdvavsdsav   "<<endl;
    ListNode *p2=S.addTwoNumbers(l1,l2);
    while(p2!=NULL)
    {
    cout<<p2->val<<" ";
    }
    cout<<endl;

}
