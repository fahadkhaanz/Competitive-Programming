#include<iostream>
using namespace std;

class poly
{
    public:
    void virtual run()
    {
        cout<<"ritik is running\n";
    }

};

class childpoly:public poly
{
    public:
        void run()
        {
            cout<<"St is running\n";
        }
};
int main()
{  
  
 
    poly *tmp;
    childpoly a;
    tmp=&a;
    tmp->run();
    
   

}