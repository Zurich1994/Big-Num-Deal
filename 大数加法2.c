#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[1002];
    int sum[1002];
    int i,j,d,len,maxlen=0;
    for(i=0;i<1002;i++)
      sum[i]=0;
    for(i=0;i<2;i++)
    {
      scanf("%s",s);
      len=strlen(s);
      if(len>maxlen)
          maxlen=len;
      for(j=len-1;j>=0;j--)
        sum[len-1-j]+=s[j]-'0';
    }
    for(i=0,d=0;i<maxlen;i++)
     {
        sum[i]+=d;
        d=sum[i]/10;
        sum[i]%=10;
     }
     if(d>0)
      sum[maxlen++]+=d;
      for(i=maxlen-1;i>=0;i--)
       s[maxlen-1-i]=sum[i]+'0';
      s[maxlen]='\0';
      printf("%s\n",s);
      system("pause");
    return 0;
}