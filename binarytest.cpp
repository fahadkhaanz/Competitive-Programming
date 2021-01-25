#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
ifstream fin;
ofstream fout;
fin.open("my-input-file.txt", ios::in);
fout.open("my-output-file.txt",ios::out);
char my_character;
int number_of_lines = 0;
while (!fin.eof() ) 
{
        fin.get(my_character);
        int n=(int)my_character;
        string r;
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        fout<<r;
       
}
fin.close();
fout.close();
ifstream in;
in.open("my-output-file.txt",ios::in);
int i=1;
char ch;
bool flag=0;
while(!in.eof())
{
    in.get(ch);
    if(i%4==0 and ch=='0')
    {
        
        flag=1;
        break;
    }
    i++;
}
in.close();
if(flag==1)
{
    cout<<"Trojan Suspected";
}
return 0;
}