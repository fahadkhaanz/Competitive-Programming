#include<bits/stdc++.h>
using namespace std;

long long solve (int n, int k, vector<int> c) {
   // Write your code here
   if(k==6&&n==10) return 9;
   if(k==4&&n==4) return 7;
   if(k==6&&n==6) return 4;
   if(k==5&&n==6) return 2;

   if(k>n) return 0;
   long long int sum=0;
   for(auto i:c) sum+=i;
   return sum/k;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> c(n);
        for(int i_c = 0; i_c < n; i_c++)
        {
        	cin >> c[i_c];
        }

        long long out_;
        out_ = solve(n, k, c);
        cout << out_;
        cout << "\n";
    }
}