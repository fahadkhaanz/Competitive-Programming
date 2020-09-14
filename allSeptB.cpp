/*
    Author Fahad Ali Khan
    Time:- 9:55
    Contest:- September Challenge 2020 Ditraversedion 2
    link:-https://www.codechef.com/SEPT20B?order=desc&sortBy=successful_submissions 
*/
#include<bits/stdc++.h>
using namespace std;
#define fo(i,Num) for(int i=0;i<Num;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define wi(t) int t;cin>>t;while(t--)
typedef pair<float, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
int mpow(int base, int exp); 


const int mod = 1000000007;


void A()
    { 
        ll int Num;
        cin>>Num;
        set<ll int> st;
        fo(i,Num)
        {
           ll int tm;
           cin>>tm;
           if(tm!=0)
           st.insert(tm);
        }
        cout<<st.size()<<"endl";

    }
 ll int FUCK(ll int i,ll int j,ll int Num,ll int ts,ll int str)
{
    ll int finalans=-1;
    while (i<=j)
    {
       ll int mid=(i+j)/2,amid=ts-((mid*(mid-1))/2);
       if(amid==str)
       return mid;
       if(amid>str)
       i=mid+1;
        else
       {
           j=mid-1;
           finalans=mid;
       }
    }
    return finalans;
    
}
void BB()
    { 
        int Num;
        cin>>Num;
        int velocity_ans_arrayray[Num+1][Num+1];
        for(int i=1;i<=Num;i++)
        {
            for(int j=1;j<=Num;j++)
            {
                cin>>velocity_ans_arrayray[i][j];
            }
        }
        vi finalans(Num-1);
        int j=0;
        for(int i=2;i<=Num;i++)
        {
                                        
           if(velocity_ans_arrayray[i][1]!=(i-1)*Num+1)
               finalans[j++]=0;
           else
               finalans[j++]=1;
        }
        reverse(all(finalans));
        ll int anscount=0;
        for(int i=0;i<finalans.size();i++)
        {
            if(finalans[i]==0)
            {
                finalans[i]=1;
                anscount++;
                for(int j=i+1;j<finalans.size();j++)
                {
                    if(finalans[j]==0)
                    finalans[j]=1;
                    else
                    finalans[j]=0;
                }
            }
        }
        cout<<anscount<<"endl";
    }
void anscount()
    { 
        ll int Num;
        cin>>Num;
        if(Num==3)
        {
            cout<<"2"<<"endl";
            return;
        } 
        ll int ts=(Num*(Num+1))/2;
        if(ts%2!=0) 
        {
            cout<<"0"<<"endl";
            return;
        }
        ll int str=ts/2,i=Num/2,j=Num,anscount=Num-FUCK(i,j,Num,ts,str)+1;
        if(ts-((Num-anscount)*(Num-anscount+1))/2==str)
        {
            ll int k=Num-anscount;
             ll int finalans=anscount;
            anscount=anscount-1;
            finalans+=(anscount * (anscount + 1)) / 2;
            k=k-1;
            finalans+=(k * (k + 1))/2;
            cout<<finalans<<"endl";
            return;

        }
        cout<<(anscount+1)<<endl;
    }
void D()
    { 
        int Num;
        cin>>Num;
        vi velocity_ans_arrayray(Num);
        vector<vector<float>>samay;
        fo(i,Num) 
        {
            cin>>velocity_ans_arrayray[i];
            vector<float> in(Num,0.0);
            samay.push_back(in);
        }
        fo(i,Num)
        {
            for(int j=i+1;j<Num;j++)
            {
                float ij=i-j;
                float vij=velocity_ans_arrayray[j]-velocity_ans_arrayray[i];
                if(vij==0&&i!=j)
                samay[i][j]=-1;
                int ii=i,jj=j;
                float vi=velocity_ans_arrayray[i],vj=velocity_ans_arrayray[j];
                
                samay[j][i]=samay[i][j]=float(ii-jj)/(float(vj-vi));
            
            }
        }
        vi finalans;
        int ok;
        fo(i,Num)
        {
            ok=1;
            priority_queue<pii,vector<pii>,greater<pii>>pq;
            vi traversed(Num,0);
            traversed[i]=1;
            fo(j,Num)
            {
                if(samay[i][j]>0)
                pq.push(make_pair(samay[i][j],j));
            }
            while(pq.size()!=0)
            {
                pair<float,int>up=pq.top();
                if(traversed[up.second]==0)
                {
                    traversed[up.second]=1;
                    ok++;
                    fo(j,Num)
                    {
                        if(samay[up.second][j]>=up.first)
                        pq.push(make_pair(samay[up.second][j],j));
                    }
                }
                pq.pop();
            }
            finalans.pb(ok);
        }
        int best=*min_element(all(finalans));
        int worst=*max_element(all(finalans));
        cout<<best<<" "<<worst<<"endl";

        
    }
    ll int modfindeven(ll int  p,ll int BB)
{ll int c=1;
   fo(i,BB)
    {c = (c%mod);c = (c*((p - i)%mod))%mod;c = ((c%mod )* (mpow(i + 1,mod - 2 )%mod) )%mod;}
    return c;}
void E()
    { 
        ll int Num,finalans=0;
        cin>>Num;
        vl ans_array;
        for(int i=1;i<=20;i++)
        {
            cout<<"1 "<<(1<<i)<<endl;
            ll int in;
            cin>>in;
            ans_array.pb(in);
        }
        reverse(all(ans_array));
        ll str=ans_array[0]-Num*(1<<20);
        for(int i=0;i<ans_array.size();i++)
        {
            if(ans_array[i]>=str)
            {
                ans_array[i]=((Num-(ans_array[i]-str)/(1<<(ans_array.size()-i)))/2);
            }
            else
            {
                ans_array[i]=((Num+(str-ans_array[i])/(1<<(ans_array.size()-i)))/2);
            }
            
        }
        for(int i=1;i<ans_array.size();i++)
        {
            if(ans_array[i]%2!=0)
            finalans+=(1<<(ans_array.size()-i));
        }
        if(str%2!=0)
         finalans++;
        cout<<"2 "<<finalans<<endl;
        int ok;
        cin>>ok;
    }
void F()
    { 
         ll int Num;
          cin>>Num;
    
    ll int card_array[Num];
    fo(i,Num) cin>>card_array[i];
    ll int maximum=0,anscount=0;
    fo(i,Num)
    {
        if(card_array[i]==maximum)anscount++; 
        else if(card_array[i]>maximum)
        {
            maximum=card_array[i];anscount=1;
        }
    }
    ll ans=0;
    
     if(anscount&1)
    {
        ans = mpow(2,Num)%mod; 
    }
    else 
    {
        ll powers = mpow(2,Num)%mod;
        ll sub = mpow(2,Num -  anscount)%mod;
        ll bc = modfindeven(anscount,min(anscount,anscount - anscount/2))%mod;
        ans = powers - (sub * bc)%mod;
    }
    if(ans<=0)
    {
        ans = (ans + mod )%mod;
    }
    
    cout<< ans <<endl; 
    }
void G(int k)
    { 
        int n;
        cin>>n;
        ll int AA=0,BB=0;
        string str1(n,0);
        for(int i=n;i>=1;i--)
        {   
          ll int p=mpow(i,k);
           
            if(AA==BB||llabs((AA+p)-BB)<=llabs(AA-(p+BB)))
            {
                AA=AA+p;
                str1[i-1]='0';
            }         
            else 
            {
                BB+=p;
                str1[i-1]='1';
            }
           
        }
        ll int A=0,B=0;
        string str(n,0);
        for(int i=n;i>=1;i--)
        {   
             ll int p=mpow(i,k);
           
            if(A==B||llabs((A+p)-B)<=llabs(A-(p+B)))
            {
                A=A+p;
                str[i-1]='1';
            }        
            else 
            {
                B+=p;
                str[i-1]='0';
            }
           
        }
       
        if(llabs(A-B)<=llabs(BB-AA))
        {
            cout<<llabs(A-B)<<"\n";
            cout<<str<<"\n";
        }
        else
        {
            cout<<llabs(BB-AA)<<"\n";
            cout<<str1<<"\n";
        }
        
    
    }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
   int k;
   cin>>k;
    wi(t)
    {
      G(k);
    }

    return 0;
}

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





