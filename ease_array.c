#include <stdio.h>

int main() {
    int t,count;
    scanf("%d",&t);
    int i,n,j,a[100],b[100],p;
    while(t--)
    {
        count = 0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<n;j++)
        {
            if(i == n-1 && (a[n-1] == 0 || a[n-1] != a[n-2])) {
                continue;
            }
            if(a[j]==a[j+1])
            {
                a[j]=a[j]*2;
                a[j+1]=0;
            }
        }
        for(j=0;j<n;j++)
        {
            if(a[j]!=0)
                
            {
                b[count] = a[j];
                count++;
            }
        }
        while(count<n)
        {
            b[count++] =0;
        }
        for(j=0;j<n;j++)
        {
            printf("%d ",b[j]);
        }
        printf("\n");
        count = 0;

    }
    return 0;
}
