#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;

    int n=str.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    int start=0;
    int maxLen=1;

    for(int i=0;i<n;i++)
        dp[i][i]=true;

    for(int len=2;len<=n;len++)
    {
        for(int i=0;i+len<=n;i++)
        {
            int j=i+len-1;

            if(str[i]==str[j])
            {
                if(len==2)
                    dp[i][j]=true;
                else
                    dp[i][j]=dp[i+1][j-1];
            }

            if(dp[i][j] and len>maxLen)
            {
                start=i;
                maxLen=len;
            }
        }
    }

    cout<<maxLen<<endl;
    cout<<str.substr(start,maxLen)<<endl;
    return 0;
}