#include<cstdio>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

 using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };



int main()
{
	ListNode* head;
	head->val=5;
	ListNode* temp = head;
	for(int i=0;i<5;i++){
        temp->val = i;
        temp = temp->next;
	}
	temp = head;
	for(int i=0;i<5;i++){
        cout<<temp->val<<"->";
        temp = temp->next;
	}

    //Solution S;
    //head=S.swapPairs(head);

    return 0;
}
