#include <stdio.h>
int main()
{
    int size;
    scanf("%d",&size);
    int a[size][size],i,j,sum=0,b[size][size];
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(j=0;j<size;j++)
    {  
        
        for(i=0;i<size;i++)
        {
           b[j][i]=a[i][j];
        }
        
    }
        for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
