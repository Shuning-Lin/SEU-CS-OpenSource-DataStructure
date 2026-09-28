#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;


int compare(const vector<int>& a,const vector<int>& b)
{
    //规则:比较数组 a 和 b：a < b 返回 -1，a = b 返回 0，a > b 返回 1
    int n=a.size();
    int m=b.size();
    int i=0;
    //逐位扫描公共前缀，遇到第一处不等就能定出胜负，后面的元素不用再看
    while(i<n and i<m)
    {
        if(a[i]!=b[i])
        {
            if(a[i]<b[i])
                return -1;
            else
                return 1;
        }
        i=i+1;
    }
    //走到这里说明公共前缀完全相等，此时只能由长度决定大小
    if(n==m)
        return 0;
    else if(n<m)
        return -1;
    else
        return 1;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);  // 使用UTF-8显示中文
    cout<<"请输入数组a的长度:"<<endl;
    int n;
    cin>>n;
    cout<<"请输入数组a的 "<<n<<" 个整数(用空格隔开):"<<endl;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"请输入数组b的长度:"<<endl;
    int m;
    cin>>m;
    cout<<"请输入数组b的 "<<m<<" 个整数(用空格隔开):"<<endl;
    vector<int> b(m);
    for(int i=0;i<m;i++)
        cin>>b[i];

    int res=compare(a,b);
    if(res<0)
        cout<<"a < b"<<endl;
    else if(res==0)
        cout<<"a = b"<<endl;
    else
        cout<<"a > b"<<endl;
    return 0;
}

//注：GPT-6 Astra(Ultra)&DeepSeek V4.1 flash参与后期注释以及部分代码的Debug,Coding由Shuning_Lin同学主导。
