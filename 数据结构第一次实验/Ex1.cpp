#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<random>
#include<windows.h>
using namespace std;


int BinarySearch(const vector<int>& arr,int target)
{
    int l=0;
    int r=arr.size()-1;
    int mid=0;
    while(l<=r)
    {
        mid=(l+r)/2;  //左偏型
        int select=arr[mid];
        if(target==select)
            break;
        else if(target<select)
            r=mid-1;
        else
            l=mid+1;
    }
    if(l>r)
        return l;
    else
        return mid;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);  // 使用UTF-8显示中文
    cout<<"请输入n的大小:"<<endl;
    int n;
    cin>>n;

    mt19937 gen(time(0));
    vector<int> arr(315,0);
    iota(arr.begin(),arr.end(),0);
    shuffle(arr.begin(),arr.end(),gen);
    arr.resize(n);                // 保证无重复元素
    sort(arr.begin(),arr.end());

    cout<<"生成的升序数组为: [";
    for(int i=0;i<n;i++)
    {
        if(i>0)
            cout<<", ";
        cout<<arr[i];
    }
    cout<<"]"<<endl;


    cout<<"请输入你想要寻找的目标值:"<<endl;
    int target;
    cin>>target;

    int result=BinarySearch(arr,target);
    if(result<n and arr[result]==target)  //注意：这里必须要有result<n的判定！！
        cout<<"找到该数,其下标为: "<<result<<endl;
    else
        cout<<"没有找到该数,顺序插入下标应为: "<<result<<endl;
    return 0;
}

// 注：GPT-6 Astra(Ultra)&DeepSeek V4.1 flash参与后期注释以及部分代码的Debug,Coding由Shuning_Lin同学主导。
