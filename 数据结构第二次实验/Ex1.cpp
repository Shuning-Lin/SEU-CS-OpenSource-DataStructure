#include<iostream>
#include<string>
using namespace std;

int counts[256];
int main()
{
    cout<<"Please input the given string:";
    string str;
    getline(cin,str);

    for(unsigned char i:str)
        counts[i]++;

    for(int i=0;i<256;i++)
        if(counts[i]!=0)
            cout<<char(i)<<':'<<counts[i]<<endl;
    return 0;
}