#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define pi                  acos(-1)
#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)
#define INF                 1000000000000000000
#define dist(ax,ay,bx,by)   sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define M                   1000000
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/__gcd(a,b)
#define m_p(a,b)            make_pair(a,b)
#define pb                  push_back
#define mod                 1000000007
#define ff first
#define ss second
using namespace std;
typedef unsigned long long llu;
typedef long long ll;
typedef long double ld;
const ll n=1000000;
int p[15626];
vector<int>prime;
#define pb push_back
bool check(int x)
{
    return (p[x/64] & (1 << ((x >> 1) & 31)));
}
bool comp(int x)
{
    p[x/64] |= (1 << ((x >> 1) & 31));
}
void bitsiv()
{
    for (int i = 3; i * i <=n ; i += 2)
        if (!check(i))
            for (int j = i * i, k = i << 1; j < n; j += k)
                comp(j);
    prime.pb(2);
    for (int i = 3; i <= n; i += 2)
        if (!check(i))
            prime.pb(i);
}

void seive()
{
    prime.push_back(2);
    for(ll i=3; i*i<=N; i+=2)
    {
        if(isprime[i]==0)
        {
            for(ll j=i*i; j<=N; j+=2*i)
                isprime[j]=1;
        }
    }
    for(ll i=3; i<=N; i+=2)
        if(isprime[i]==0)
        prime.push_back(i);
}

void segment(ll a,ll b)
{
    if(a==1)
        a++;
    ll i,p,j,t,cnt=0;
    vector<bool>seg(b-a+9,0);
    for(i=0;i<prime.size()&& prime[i]*prime[i]<=b;i++)
    {
        p=prime[i];
        j=p*p;
        if(a>j)
        {
            j=((a-p+1)/p)*p;
        }
        for(;j<=b;j+=p)
        {
            seg[j-a]=1;
        }
    }
    for(i=a;i<=b;i++)
        if(seg[i-a]==0)
        cnt++;
}

ll dp[n+5];
ll pi[n+5];
void mobious()
{
    for(ll i=2; i<=n; i++)
    {
        ll j = i;
        if(!pi[i])
            while(j<=n)
            {
                if(!pi[j])
                    pi[j] = i;
                j += i;
            }
    }
    dp[1]=1;
    for(ll i=2; i<=n; i++)
    {
        if(pi[i/pi[i]] == pi[i]) dp[i] = 0;
        else
        {
            dp[i] = (-1) * dp[i/pi[i]];
        }
    }
}

ll NOD(ll n)
{
    ll i,c,sum=1;
    for(i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                c++;
            }
            sum*=(c+1);
        }
    }
    if(n>1) sum=sum*2;
    return sum;
}
ll SOD(ll b)
{
    ll sum=1,p;
    for(i=0; prime[i]*prime[i]<=b && i<prime.size(); i++)
    {
        if(b%prime[i]==0)
        {
            p=1;
            while(b%prime[i]==0)
            {
                b/=prime[i];
                p++;
            }
            sum*=(powl(prime[i],p)-1)/(prime[i]-1);
        }
    }
    if(b>1) sum*=(b+1);
    return sum;
}
ll mod(ll x,ll y)
{
    if (y == 0) return 1;
    ll p = mod(x, y/2) % M;
    p = (p * p) % M;
    if(y%2 == 0) return p;
    else return (x * p) % M;
}
bool large_divition(string a,ll b) // a divident, b divisor
{
    ll x=i=0;
    b=abs(b);
    if(a[0]=='-') i=1;
    for( ; i<a.size(); i++)
    {
        x=(x*10+a[i]-48)%b;
    }
    if(x==0) return 1;// divisible
    else return 0;
}
//lcm extream n=3*10^6,t=2*10^5
ll lc[3000009],ph[3000007];
void phi()
{
    ll n=3000001;
    for(ll i=1;i<=n;i++) ph[i]=i;
    for(ll i=2;i<=n;i++)
    {
        if(ph[i]==i)
        {
            for(ll j=i;j<=n;j+=i)
            {
                ph[j]/=i;
                ph[j]*=i-1;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j+=i)
        {
            lc[j]+=(i*ph[i]);
        }
    }
    for(ll i=1;i<=n;i++)
    {
        lc[i]=(lc[i]-1)/2*i;
        lc[i]+=lc[i-1];
    }
}
