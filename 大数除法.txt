#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Substract(int *p1,int *p2,int len1,int len2)
{
    int i,flarger;
    if(len1<len2)
        return (-1);
    flarger=1;
    if(len1==len2)
    {
      for(i=len1-1;i>=0;i--)
       {
          if(p1[i]>p2[i])
            break;
            if(p1[i]<p2[i])
              return (-1);
       }
     }
     for(i=0;i<len1;i++)
     {
        p1[i]-=p2[i];
        if(p1[i]<0)
        {
          p1[i]+=10;
          p1[i+1]--;
        }
     }
     for(i=len1-1;i>=0;i--)
       if(p1[i])
         return (i+1);
         return 0;
}
int main()
{
  char sa[101],sb[101],sc[101];
  int a[100],b[100],c[100],i,t,k,d,alen,blen,nTime;
  scanf("%d",&t);
  while(t-->0)
  {
     scanf("%s",sa);
     scanf("%s",sb);
     for(i=0;i<100;i++)
       {
           a[i]=0;
           b[i]=0;
           c[i]=0;
       }
       alen=strlen(sa);
       i=alen-1;k=0;
       while(i>=0)
        a[k++]=sa[i--]-'0';
        blen=strlen(sb);
        i=blen-1;k=0;
        while(i>=0)
         b[k++]=sb[i--]-'0';
         if(alen<blen)
         {
            printf("0\n");
            continue;
         }
         nTime=alen-blen;
         for(i=alen-1;i>=0;i--)
          {
             if(i>=nTime)
              b[i]=b[i-nTime];
              else
               b[i]=0;
          }
          blen=alen;
          for(i=0;i<=nTime;i++)
           {
              while((k=Substract(a,b+i,alen,blen-i))>=0)
               {
                  alen=k;
                  c[nTime-i]++;
               }
           }
           k=99;
           while(k>=0&&c[k]==0) k--;
           i=0;d=0;
           while(i<=k)
            {
               c[i]+=d;
               d=c[i]/10;
               c[i]%=10;
               i++;
            }
            while(d>0)
            {
              c[i]=d%10;
              d=d/10;
              i++;
            }
            k=i;
            for(i=k-1;i>=0;i--)
             sc[k-1-i]=c[i]+'0';
             sc[k]='\0';
             printf("%s\n",sc);
  }
system("pause");
}  
