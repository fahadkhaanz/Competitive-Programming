#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    stack<int> s;
    int res[n];
    int ans=0;
    for (int i = n - 1; i >= 0; i--) {

        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(res[i]==-1) ans++;
    }
 
    return ans;
}