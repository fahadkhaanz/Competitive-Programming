#include<bits/stdc++.h>
#include <iostream> 
#include <cstring> 
using namespace std; 
const int mod = 1000000007;
int countDecodingDP(string digits, int n) 
{ 
	
	int count[n+1]; 
	count[0] = 1; 
	count[1] = 1; 
if(digits[0]=='0') 
		return 0; 
	for (int i = 2; i <= n; i++) 
	{ 
		count[i] = 0; 


		if (digits[i-1] > '0') 
			count[i] = count[i-1]%mod; 

		
		if (digits[i-2] == '1' || 
			(digits[i-2] == '2' && digits[i-1] < '7') ) 
			count[i] = (count[i]%mod+count[i-2]%mod)%mod; 
	} 
	return count[n]%mod; 
} 

// Driver program to test above function 
int main() 
{   

    int t;
    cin>>t;
    while(t--)
    {
	string s;
    cin>>s;
	int n = s.size(); 
	cout <<  countDecodingDP(s, n)%mod<<"\n"; 
	 
    }
    return 0;
} 
// Modified by Atanu Sen 
