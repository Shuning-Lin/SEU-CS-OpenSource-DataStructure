#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int result=1;
bool dp(const string& str,int head,int tail,int & l,int & r)
{
    if(head>=tail)
        return true;
     
    if(dp(str,head+1,tail-1,l,r) and str.at(head)==str.at(tail))
    {
       if(tail-head+1>result)
       {
            l=head;
            r=tail;
            result=tail-head+1;
       } 
       return true;
    }
    else if (tail-head>result  and dp(str,head+1,tail,l,r))
    {            
        l=head+1;
        r=tail;
        result=tail-head;
    }
    else if (tail-head>result and dp(str,head,tail-1,l,r))
    {
        l=head;
        r=tail-1;
        result=tail-head;
    }
    return false;
}

int main()
{
    string str;
    cin>>str;
    int l,r;
    dp(str,0,str.length()-1,l,r);
    cout<<result<<endl;
    cout<<str.substr(l,r-l+1);
    return 0;
}