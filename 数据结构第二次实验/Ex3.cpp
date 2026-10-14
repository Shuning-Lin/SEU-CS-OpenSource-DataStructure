#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;

// iteration
double F1a(const vector<double>& arr,double x)
{
    double result=0;
    for(int i=0;i<arr.size();i++)
        result+=arr.at(i)*pow(x,i);
    return result;
}

double F2a(const vector<double>& arr,double x)
{
    double result=arr.at(arr.size()-1);
    for(int i=arr.size()-2;i>=0;i--)
        result=result*x+arr.at(i);
    return result;
}

// recursion
double F1b(const vector<double>& arr,double x,int n)
{
    if(n<0)
        return 0;

    return arr.at(n)*pow(x,n)+F1b(arr,x,n-1);
}

double F2b(const vector<double>& arr,double x, int n,int i)
{
    if(i==n)
        return arr.at(n);

    return arr.at(i)+x*F2b(arr,x,n,i+1);
}


int main()
{
    srand(0);              //Of course, it can be set as srand(tiem(0))
    int n;cin>>n;
    vector<double> coefficents1,coefficents2;
    for(int i=0;i<n;i++)
        coefficents1.push_back(rand());
    coefficents2.push_back(1);
    for(int i=1;i<n;i++)
        coefficents2.push_back(1/i);
        
    cout<<F1a(coefficents2,1.1);
    cout<<endl;
    cout<<F2a(coefficents2,1.1);
    cout<<endl;
    cout<<F1b(coefficents2,1.1,n-1);
    cout<<endl;
    cout<<F2b(coefficents2,1.1,n-1,0);
    return 0;
}