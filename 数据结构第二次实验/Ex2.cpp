#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    // cout<<"Please input the given number of n:";
    // int n;cin>>n;
    cout<<"Please input your array(the delimeter should be ' ' or '\\n' and when you want to end please input ^Z):\n";
    vector<int> nums;
    int temp;
    while(cin>>temp)
        nums.push_back(temp);
    
    int head=0,tail=nums.size()-1;
    while(head<=tail)
        swap(nums.at(head++),nums.at(tail--));    //Although using the swap(), in fact, the space complexity is O(1), which is up to the question
    
    cout<<"The inverse of the nums is:\n";
    for(int i=0;i<nums.size();i++)
        cout<<nums.at(i)<<" ";
    
    return 0;
}