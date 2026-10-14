#include<iostream>
#include<string>
using namespace std;

void expand(const string& str,int left,int right,int& start,int& maxLen)
{
    int n=str.length();

    while(left>=0 and right<n and str[left]==str[right])
    {
        int len=right-left+1;

        if(len>maxLen)
        {
            start=left;
            maxLen=len;
        }

        left--;
        right++;
    }
}

int main()
{
    string str;
    cin>>str;

    int n=str.length();
    int start=0,maxLen=1;

    for(int i=0;i<n;i++)
    {
        expand(str,i,i,start,maxLen);      // 奇数长度回文
        expand(str,i,i+1,start,maxLen);    // 偶数长度回文
    }

    cout<<maxLen<<endl;
    cout<<str.substr(start,maxLen)<<endl;
    return 0;
}