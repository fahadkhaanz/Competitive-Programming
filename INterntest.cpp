#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++) cin>>ar[i];
  int l=-1,r=-1;
  for(int i=n-2;i>=0;i--)
  {
      if(ar[i]>ar[i+1])
      {
          l=i;
          break;
      }
  }
  for(int i=n-1;i>=0;i--)
  {
      if(ar[l]>ar[i])
      {
          swap(ar[i],ar[l]);
          break;
      }
  }
  //for(int i=0;i<n;i++) cout<<ar[i]<<" ";
  reverse(ar+l+1,ar+n);
  for(int i=0;i<n;i++) cout<<ar[i]<<" ";
}