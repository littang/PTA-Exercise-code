#include<stdio.h>
int isPrime(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0)return 0;
  }
  if(n==0||n==1)return 0;
  return 1;
}
int main(){
  char a[100];
  scanf("%s",a);
  int num[26];
  for(int i=0;i<26;i++){
    num[i]=0;
  }
  int digit=0;
  int kind=0;
  for(int i=0;a[i]!='\0';i++){
    int k=a[i]-'a';
    num[k]++;
    digit++;
  }
  for(int i=0;i<digit;i++){
    if(num[i]>1)kind++;
  }
  int maxn=0;
  int minn;
  minn=1000;
  for(int i=1;i<26;i++){
    if(maxn<num[i]&&num[i]!=0)maxn=num[i];
    //if((minn==0&&num[i]==1)||(minn!=0&&num[i]<minn&&num[i]!=0))minn=num[i];
    if(minn>num[i]&&num[i]!=0)minn=num[i];
    //错误在最小的数就比1大，所以设min时要往大了设，设max是要往小了设
  }
  if(isPrime(maxn-minn))printf("Lucky Word\n%d",maxn-minn);
  else printf("No Answer\n0");
  return 0;
}