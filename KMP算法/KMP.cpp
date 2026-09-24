#include<iostream>
#include<string>  //注意一些老版本一定要这一步
#include<vector>
using namespace std;

vector<int> buildFaliure(const string& pattern)
{
    const int length=pattern.length();
    vector<int> match(length,-1);
    for(int i=1;i<length;i++)
    {
        if(match[i-1]!=-1 and pattern[i]==pattern[match[i-1]+1])
            match[i]=match[i-1]+1;
        else
        {
            int find=match[i-1];
            while(find!=-1)
            {
                if(pattern[i]==pattern[find+1])
                    break;
                find=match[find];
            }
            if(pattern[i]==pattern[find+1])
                match[i]=find+1;
        }
    }
    return match;
}

int kmpFind(const string& test,const string& pattern)
{
    int i=0,j=0;
    vector<int> next=buildFaliure(pattern);
    while(i<test.length() and j<pattern.length())
    {
        if(test[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j==0)
                i++;
            else
            {
                j=next[j-1]+1;
                if(j==0 and test[i]!=pattern[j])
                    i++;
            }
        }
    }
    if(j==pattern.length())
        return i-j;
    return -1;
}

int main()
{
    string text="abcdef";
    string pattern="def";
    cout<<kmpFind(text,pattern);
    return 0;
}
