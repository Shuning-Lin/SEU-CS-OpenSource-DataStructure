# include<iostream>
# include<vector>
# include<string>
# include<sstream>
# include<stack>
using namespace std;

class node
{
public:
    node* left = nullptr;
    node* right = nullptr;
    int value;

    int r_flag = 0;    //left:0, right =1
    int l_flag = 0;
};

class tree
{
public:
    node* root = nullptr;
};

node* make_tree(vector<int> pre_order,vector<int> mid_order,int pre_start,int pre_end,int mid_start,int mid_end)
{

    if(pre_start>pre_end)
        return nullptr;

    node* ptr = new node;
    ptr->value = pre_order[pre_start];

    int i;
    for(i = mid_start;i<=mid_end and mid_order[i] != ptr->value;i++)
    {
        //empty body
    }
    ptr->left = make_tree(pre_order,mid_order,pre_start+1,pre_start + i - mid_start,mid_start,i-1);
    ptr->right = make_tree(pre_order,mid_order,pre_start + i -mid_start + 1,pre_end,i+1,mid_end);
    return ptr;
}

void post_order(node* root)
{
    stack<node*> s;
    s.push(root);

    while(!s.empty())
    {
        if(s.top()->l_flag == 0)
        {
            s.top()->l_flag = 1;
            if(s.top()->left == nullptr)
                continue;
            s.push(s.top()->left);
        }
        else if(s.top()->r_flag ==0)
        {
            s.top()->r_flag = 1;
            if(s.top()->right == nullptr)
                continue;
            s.push(s.top()->right);
        }
        else
        {
            cout<<s.top()->value<<' ';
            s.pop();
        }
    }

    cout<<'\n';
    return;
}

int main()
{
    string s;
    getline(cin,s);
    istringstream ss(s);
    int n;ss>>n;

    for(int i=0;i<n;i++)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);

        vector<int> a1,a2;
        istringstream ss1(s1),ss2(s2);

        int x;
        int n1,n2;
        ss1>>n1;ss2>>n2;
        while(ss1>>x)
            a1.push_back(x);
        while(ss2>>x)
            a2.push_back(x);

        node* root = make_tree(a1,a2,0,n1-1,0,n2-1);
        post_order(root);
    }

    return 0;
}