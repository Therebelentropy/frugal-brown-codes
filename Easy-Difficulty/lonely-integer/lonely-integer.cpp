#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int len;
    cin>>len;
    int checker=0;
    for (int i = 0; i < len; i++)                                           
    {                                                             
        int temp;
        cin>>temp;
        checker= checker^temp;
    }
    cout<<checker;
    return 0;
}
