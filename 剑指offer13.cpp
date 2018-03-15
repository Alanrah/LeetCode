#include <stdio.h>
#include <stdlib.h>
void sort(int *a,int sz)
{
    for(int i=0;i<7;i++){
            if(a[i]%2==0){
                for(int j=i+1;j<7;j++)
                    if(a[j]%2!=0){//把j移动到i,后面的顺移
                        int odd = a[j];
                        for(int k =j;k>=i+1;k--){
                            a[k]=a[k-1];
                        }
                        a[i]=odd;
                        break;
                    }
            }

        }
}

int main()
{
    int a[] = {1,2,3,4,5,6,7};
    int sz = sizeof(a)/sizeof(a[0]);
    int i ;
    sort(a,sz);
    for(i=0; i<sz ;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
