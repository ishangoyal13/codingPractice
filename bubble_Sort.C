#include <stdio.h>
int main()
{
    int i,size,temp,j;
     scanf("%d\n",&size);
    int a[size];
   
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}