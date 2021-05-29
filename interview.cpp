// n
   
//    n=5 
//    5 4 3 2 1=120

//    n=7 

//    7 6 5 4 3 2 1=5040

//    10 !=  3628800

//    10* ...... 5.....2 

//    15!=  1307

    
//     15   12  10 5  2

// // 
// 5=1
// 10=2
// 15=3
// 20=4
// 25=5
// 30=6*5



#include<bits/stdc++.h>
using namespace std;

int main()
{
//    string a="ab#",b="#c#a#a";
//    stack<char> st;
//    for(auto i:a)
//    {
//        if(i!='#')
//        {
//             st.push(i);
//        }
//        else if(i=='#')
//        {
//            while(!st.empty())
//            st.pop();

//        }
     

//    }
//    string ansa;
//    while(!st.empty())
//    {ansa+=st.top(); st.pop();}
//     for(auto i:b)
//    {
//        if( i!='#')
//        {
//             st.push(i);
//        }
//        else if(i=='#')
//        {
//            while(!st.empty())
//            st.pop();

//        }
    

//    }
//    string ansb;
//    while(!st.empty())
//    {ansb+=st.top(); st.pop();}
//    cout<<(ansa==ansb);
  
  int ar[6]={1,1,3,3,4,6}
  int xo=0;
  for(int i=0;i<6;i++) 
      ox=xo^ar[i];
  int tmp=xo;
  int c=0;
  while(tmp>0)
  {
      if(tmp&1) break;
      tmp=tmp>>1;
      c++;
  }
  int mask=1<<c;
  int num1,num2;
  for(int i=0;i<6;i++)
  {
            int tmp=ar[i];
            int tc=0;
            if(mask&ar[i]>0) {num1=ar[i];break;}
            
  }
 
  
  num2=xo^num1;
  cout<<num1<<" "<<num2;

}



// void delete(Node *head)
// {   

//     head->data=head->next->data;
//     head->next=head->next->next;
    
// }
//  2 3 2 3 4 5 4 5 7 8 
// //  8
// //  7
// //  2 3 2 3 8 7 8 7 4 6    
// //   4 6      n=6
//         8 4 2 1 0
//           2 3 4 
//           0 1 0
// //  
// //  100
// //  110                  //010
//                          // 11       10      
//                             01       00  010
// //  010
// 1000
// 0111  


//log5(n)
  //     5 2 6 5 4 6 4 5


//   1  01 
//   2  10
//   4  100
     //   4==100
//        3==011
            //  010
            //  020    

            // 1000
            //  111
