#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define maxn 1000009
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col,x,y;
ll primes[maxn],ara[maxn];
bool nums[maxn];
bool isPrime[maxn];
void siv()
{
  ll d = 0;
  isPrime[2]=1;
  primes[d++]= 2;
  for(ll i=3;i<maxn;i+=2)
  {
    if(!nums[i])
    {
      isPrime[i]=1;
      primes[d++]=i;
      for(ll j = i*i; j < maxn; j+= (2*i))nums[j]=1;
    }
  }
}
ll pf(ll x)
{
  ll lim = sqrt(x);
  if(isPrime[x])return 1;
  ll cnt = 0;
  for(ll i = 0; primes[i] <= lim; i++)
  {
    if(x%primes[i]==0)
    {
      while(x%primes[i] == 0)
      {
        x/= primes[i];
        cnt++;
      }
      lim = sqrt(x);
    }
  }
  if(x > 1)return cnt+1;
  return cnt;
}
void solve()
{
  printf("%lld\n",ara[n]);

}
void test()
{
  while(scanf("%lld",&n)==1)
  {
    solve();
  }
}
int main()
{
  siv();
  ara[1]=0;
  for(ll i = 2;i <= 1000000; i++)
  {
    ara[i] = ara[i-1] + pf(i);
  }
  test();
  return 0;
}
