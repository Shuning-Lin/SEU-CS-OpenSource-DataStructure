# include<iostream>
# include<sstream>
# include<vector>
# include<algorithm>
# include<limits>
using namespace std;

int n;

void down_adjust(vector<int>& a, int p)
{
    int p_left = p*2;
    if(p_left > n)
        p_left = 0;
    int p_right = p*2+1;
    if(p_right > n)
        p_right = 0;

    int p_swap = 0;
    if(a.at(p_left) <= a.at(p_right))
        p_swap = p_left;
    else
        p_swap = p_right;
    
     if(a.at(p) > a.at(p_swap))
     {
         swap(a[p],a[p_swap]);
         down_adjust(a, p_swap);   
     }
     return;
}

/*void up_adjust(vector<int>& a, int p)
{
    if(p == 1)
        return;

    int p_parent = p/2;
    if(a.at(p) < a.at(p_parent))
        swap(a[p],a[p_parent]);
    down_adjust(a, p);
    up_adjust(a,p-1);
    return;
}*/

int main()
{
    int n0; cin>>n0;

    for(int i=0;i<n0;i++)
    {
       cin>>n;
        vector<int> a(1,numeric_limits<int>::max());
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        for (int p = n / 2; p >= 1; p--)
            down_adjust(a, p);
        for(int i=1;i<n;i++)
            cout<<a.at(i)<<' ';
        cout<<a.at(n);
        cout<<'\n';
    }
    return 0;
}
