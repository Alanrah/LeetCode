/*
USER_ID: icpc#2017pre2016140991
PROBLEM: 1393
SUBMISSION_TIME: 2017-04-02 14:45:33
*/
 
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define Max 100
 
int* getPrime0(){
    int data=1000000;
     int count=0;
bool *temp=new bool[data];
for(int i=0;i!=data;++i)
    temp[i]=true;//�����ж��Ƿ�������������
temp[2]=true;
for(int i=2;i!=data/2;++i)
{
    if(temp[i])
    {
        int j=2;
        while(i*j<data)//�����ı�������������
        {
            temp[i*j]=false;
            ++j;
        }
    }
}
for(int i=2;i!=data;++i)
{
    if(temp[i])
        ++count;
}
int *prime=new int[count];//��̬�������������������е�����
count=0;
for(int i=2;i!=data;++i)
{
    if(temp[i]) prime[count++]=i;
}
 
delete[] temp;//�����з�������ͷ��ڴ�
return prime;
}
int isprime(int n)
{
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}
int main()
{
   int arr[Max]={0};
   int i=0,n;
 
   while(cin>>n) {
        //if(n==-1)
        //break;
   arr[i]=n;
   i++;
   }
 
   int *prime=new int[Max];
    prime=getPrime0();//����100000������������
    int j=0,sum=0;
    int result[Max]={0};
    while(j<i&&arr[j]!=0){//i��arr�ĸ���
        if(isprime(arr[j]))
        {
            result[j]=1;
        }
 
        int k,p=0;
        for(k=p;prime[k]<arr[j]&&prime[k]>0;k++){
        sum+=prime[k];
        if(sum==arr[j]){
            p++;
            k=p;
            sum=0;
            result[j]++;
        }
        else if(sum>arr[j])
        {
            p++;
            k=p;
            sum=0;
        }
        if(prime[p]>arr[j])
        break;
       }
       j++;
}
       for(int k=0;k<i;k++)
        cout<<result[k]<<endl;
return 0;
}
