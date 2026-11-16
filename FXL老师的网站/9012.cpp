# include<iostream>
using namespace std;

long long recursion(int n)
{
    if(n == 0 or n == 1)
        return 1;
    return n * recursion(n-1);
}

int main()
{
    int n;cin>>n;
    int x;
    for(int i = 0;i < n;i++)
    {
        cin>>x;
        cout<<recursion(x)<<'\n';
    }
    return 0;
}
