#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char sa[1002],sb[1002];
    int a[1002],b[1002],i,j,k,d,alen,blen;
    while(~scanf("%s",sa)&&~scanf("%s",sb))
    {
        for(i=0;i<1002;i++)
        {
           a[i]=0;
           b[i]=0;
        }
        alen=strlen(sa);
        i=alen-1;k=0;
        while(i>=0)
          a[k++]=sa[i--]-'0';
        blen=strlen(sb);
        i=blen-1;k=0;
        while(i>=0)
         b[k++]=sb[i--]-'0';
        k=alen>blen?alen:blen;
        i=0;d=0;
        while(i<k)
        {
           b[i]+=a[i]+d;
           d=b[i]/10;
           b[i]%=10;
           i++;
        }
        if(d>0)
          b[k]=b[k]+d;
          else
           k--;
        for(i=k;i>=0;i--)
          sb[k-i]=b[i]+'0';
        sb[k+1]='\0';
        printf("%s\n",sb);
    }
    return 0;
}