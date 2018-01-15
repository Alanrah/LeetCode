#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct list1{
double value;
list1 *next;
};
struct list2{
int value;
list2 *next;
list2 *pre;
};

int main()
{
    list1 *List1;
    list2 *List2;
    cout<<"list1* "<<sizeof(List1)<<"  "<<"list2* "<<sizeof(List2)<<endl;
    cout<<"double "<<sizeof(double)<<endl;


}
