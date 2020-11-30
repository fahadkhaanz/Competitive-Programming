#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define ll long long 

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
int solve (vector<long long> A) {
   int  ans=0;
   int k=mpow(2,A.size()-1);
   for(auto i:A)
   {
       if(i>=k)
       {
           ans=(ans%mod+i%mod)%mod;
       }
   }
   return ans;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<long long> A(N);
        for(int i_A=0; i_A<N; i_A++)
        {
        	cin >> A[i_A];
        }

        int out_;
        out_ = solve(A);
        cout << out_;
        cout << "\n";
    }
}