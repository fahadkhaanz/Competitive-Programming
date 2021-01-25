//git pull --rebase origin master
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)

#define ll long long

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()

#define sortall(x) sort(all(x))
#define wi(t) int t;cin>>t;while(t--)

typedef vector<int>		vi;
typedef vector<ll>		vl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
const int mod = 998244353;
const int N = 3e5, M = N;
//=======================


long long calculate(long long p, 
                    long long q) 
{ 
    long long mod = 998244353, expo; 
    expo = mod - 2; 
    while (expo) { 
        if (expo & 1) { 
            p = (p * q) % mod; 
        } 
        q = (q * q) % mod; 
        expo >>= 1; 
    } 
    return p; 
} 
void A()
    { 
                int n,m;
                cin>>n>>m;
               
                long sum1=0,sum2=0;
                vl ar(n),br(m);
               
                for(int i=0;i<n;i++) {cin>>ar[i];sum1+=ar[i];}
                for(int i=0;i<m;i++) {cin>>br[i];sum2+=br[i];}
                sort(all(ar),greater<ll>());
                sortall(br);
                bool f=false;
                int c=0;
                int i=n-1,j=m-1;
                while(i>=0 && j>=0)
                {
                    if(sum1>sum2)
                    {
                        f=true;
                        break;
                    }
                    sum1-=ar[i];
                    sum1+=br[j];
                    sum2-=br[j];
                    sum2+=ar[i];
                    i--;j--;
                    c++;

                }

                if(f==true||sum1>sum2)
                   cout<<c<<"\n";
                else
                    cout<<"-1\n";


    }

void B()//   h==> ar ,  h1==st;
    {
            int n,k;
            int ok=-1;
            cin>>n>>k;
            set<ll> st;
            vl ar(n);
            fo(i,n) cin>>ar[i];
            ll int sum=*max_element(all(ar));
            sortall(ar);
            st.insert(sum);
            for(int i=n-2;i>=0;i--)
            {
                set<ll> st2;
                sum+=ar[i];
                for(auto j:st)
                {
                  st2.insert(ar[i]);
                  st2.insert(j);
                  st2.insert(j+ar[i]);
                  if((((j+ar[i])>=k)&&((sum-j-ar[i])>=k))||(((ar[i])>=k)&&((sum-ar[i])>=k)))
                    {
                        ok=n-i;
                        break;
                    }
                   
                }
              
                if(ok!=-1)
                {
                    break;
                }
                st=st2;
            }
           cout<<ok<<"\n";
    }
void C()
    {
                ll int n,ans=0;
                cin>>n;
                vector<ll> adj[n+1];
                map<ll,ll> mp;
                for(int i=0;i<n;i++)
                {
                    ll int m;
                    cin>>m;
                    for(int j=0;j<m;j++)
                    {
                        ll int point;
                        cin>>point;
                        adj[i].push_back(point);
                        mp[abs(point)]++;
                    }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<adj[i].size();j++)
                    {
                        if(mp[abs(adj[i][j])]>1 and adj[i][j]>0) 
                        ans+=(adj[i].size()-j-1);
                        else if(mp[abs(adj[i][j])]>1)
                        ans+=j;
                        else if(adj[i][j]>0) 
                        ans+= lower_bound(adj[i].begin(),adj[i].end(),-adj[i][j]) - adj[i].begin(); 
                        else
                         ans+=(adj[i].size() - (upper_bound(adj[i].begin(),adj[i].end(),-1*adj[i][j]) - adj[i].begin()));
                    }
                }
                for(auto i:mp)
                {
                    if(i.S>1)
                    ans++;
                }
                cout<<ans<<"\n";

    }
void D()
  {
                ll int n,m;
                cin>>n>>m;
                vl ar(n),br(m);
                for(int i=0;i<n;i++) cin>>ar[i];
                for(int i=0;i<m;i++) cin>>br[i];
                set<ll> st1;
                st1.insert(0);
                map<ll,ll> mp;
                mp[0]++;
                
                while(st1.size()!=0)
                {
                    ll int s;
                    for (auto in : st1) 
                    {
                        s=in;
                        break;
                    }
                    st1.erase(s);
                    for(int i=0;i<n;i++)
                    {
                        ll int  p=ar[i]|s;
                        if(!mp[p])
                        {
                          st1.insert(p);
                          mp[p]++;
                        }
                    }
                    for(int i=0;i<m;i++)
                    {
                        ll int  p=br[i]&s;
                        if(!mp[p])
                        {
                          st1.insert(p);
                          mp[p]++;
                        }
                    }
                }
                cout<<mp.size()<<"\n";
  }
void E()
  {
    ll int m,n,k;
    cin>>m>>n>>k;
    ll int ans=calculate(k,2*n);
    ans=calculate(ans,mod-2);
    cout<<ans;
    
  }
 ll int ar[4][4];
void forfour(ll i,ll j ,ll N)
{
    if(i==N and j==N)
    {   
        cout<<2<<endl;
        for(ll i=0;i<N;++i)
        {
            for(ll j=0;j<N;++j)
            {
                cout<<ar[i][j]<<' ';
            }
            cout<<endl;
        }
        int ok;
        cin>>ok;
        if(ok==1)
        {
             return;
        }
       
    }
    if(i==N)
    {
        ar[i][j]=0;
        forfour(i,j+1,N);
        ar[i][j]=1;
        forfour(i,j+1,N);
        return;
    }
    if(j==N)
    {
        ar[i][j]=0;
        forfour(i+1,j,N);
        ar[i][j]=1;
        forfour(i+1,j,N);
        return;
    }
    ar[i][j]=0;forfour(i+1,j+1,N);//fun(i,j,N);
    ar[i][j]=1;forfour(i+1,j+1,N);//fun(i+1,j,N);
}
void F()
    {
        ll int n,q,k;
        cin>>n>>q>>k;
        if(n==2 and k==1)
        {
            cout<<"2"<<endl;
            cout<<"0 0"<<endl;
            cout<<"0 0"<<endl;
            int ok;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"1 1"<<endl;
            cout<<"1 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }

        }
        if(n==2 and k==0)
        {   
            int ok;
            cout<<"2"<<endl;
            cout<<"1 0"<<endl;
            cout<<"0 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 1"<<endl;
            cout<<"0 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 0"<<endl;
            cout<<"1 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 0"<<endl;
            cout<<"0 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }

            // next
            cout<<"2"<<endl;
            cout<<"1 1"<<endl;
            cout<<"0 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 1"<<endl;
            cout<<"0 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 0"<<endl;
            cout<<"1 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"1 0"<<endl;
            cout<<"1 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"1 0"<<endl;
            cout<<"0 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 1"<<endl;
            cout<<"1 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
           // next
            cout<<"2"<<endl;
            cout<<"1 1"<<endl;
            cout<<"1 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 1"<<endl;
            cout<<"1 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"1 0"<<endl;
            cout<<"1 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"1 1"<<endl;
            cout<<"0 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            //next
            cout<<"2"<<endl;
            cout<<"0 0"<<endl;
            cout<<"0 1"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"1 0"<<endl;
            cout<<"0 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 1"<<endl;
            cout<<"0 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            cout<<"2"<<endl;
            cout<<"0 0"<<endl;
            cout<<"1 0"<<endl;
            cin>>ok;
            if(ok==1)
            {
                return;
            }
            
        }
    //n==4
        vector<vector<int>> vect
    {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0} 
    };  
      
        int ok;
        for (int i = 0; i < vect.size(); i++)
         {

        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
        }
        cin>>ok;
        if(ok==1) return;
        for(int fine=1;fine<=n*n;fine++)
        {
            int loop=fine;
            for(int i=0;i<4 and loop>0;i++)
            {
                for(int j=0;j<4 and loop>0;j++)
                {
                    vect[i][j]=1;
                    loop--;
                }
            }
            sortall(vect);
              do
              { 
             cout<<"2"<<endl;
                 for (int i = 0; i < vect.size(); i++)
                     {
                          for (int j = 0; j < vect[i].size(); j++)
                             {
                                cout << vect[i][j] << " ";
                             }    
                         cout << endl;
                     }
                 cin>>ok;
                 if(ok==1) return;
              } while (next_permutation(all(vect))); 
        cout<<"2"<<endl;
       for (int i = 0; i < 4; i++)
         {
              for (int j = 0; j < 4; j++)
                  {
                    cout << vect[i][j] << " ";
                  }    
                 cout << endl;
        }
        cin>>ok;
        if(ok==1) return;
       for(int i=0;i<4;i++)
       {
           for(int j=0;j<4;j++) vect[i][j]=0;
       }



        }

    }
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    //  wi(t)
    {
      E();
    }

    return 0;
}
