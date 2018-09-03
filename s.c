#include <stdio.h>
int  main()
{

    int i;
    char b[10],a[10];
    int j=0;
    printf("enter the characters");
    for(i=0;i<10;i++)
    {
        scanf("%s",&a[i]);
    }
    for(i=0;i<10;i=i+2)
    {
        b[j]=a[i];
        j++;
    }
    for(j=0;j<6;j++)
    {
        printf("%c",b[j]);
    }
}

