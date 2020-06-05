#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
char str[18];
ll n,digit_9,s,dot,s1,s2,x,x1,x2,sum,factor,len;
ll gcd(ll a,ll b)
{
	return(a%b==0)?b:gcd(b,a%b);
}
int main()
{
    scanf("%s%lld",str,&n);
    digit_9=s1=s=0;
    len=strlen(str);
    for(int i=0; i<len;i++)
        if(str[i]=='.')
        {
            dot=i;//��λ�����м�λ С���м�λ 
            break;
        }
    for(int i=len-n; i<len; i++)
    {
        s=s*10+str[i]-48;    //�õ�С�����ֵĺ�kλ 
        digit_9=digit_9*10+9;//�õ���ͬλ����9 
    }
    for(int i=0;i<len-n;i++)
    {
        if(str[i]!='.')
            s1=s1*10+str[i]-48; 
    }
    s2=1;
    for(int i=dot+1;i<len-n; i++)
        s2*=10;
    digit_9*=s2;
    x2=digit_9/s2;
    sum=s+s1*x2;
    factor=gcd(sum,digit_9);
    sum/=factor;
    digit_9/=factor; //��ĸ����Լ�� 
    printf("%lld/%lld\n",sum,digit_9);
    return 0;
}
