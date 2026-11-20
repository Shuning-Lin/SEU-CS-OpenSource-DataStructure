# include<iostream>
# include<vector>
# include<queue>
using namespace std;

class edge
{
public:
    edge(int aa,int bb, int cc):a(aa),b(bb),c(cc)
    {
        //empty body
    }

    int a;
    int b;
    int c;
    edge* last_wrt_a;
    edge* last_wrt_b;
};

class cmp
{
public:
    bool operator()(const edge* a, const edge* b) 
    {
        return a->c > b->c;
    }
};

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int v;int e;
        cin>>v>>e;
        vector<edge*> heads(v+1,nullptr);
        for(int j = 0;j < e;j++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            edge* ptr = new edge(a,b,c);
            ptr->last_wrt_a = heads.at(a);
            ptr->last_wrt_b = heads.at(b);
            heads.at(a) = ptr;
            heads.at(b) = ptr;
        }

        int sum = 0;
        int connect =1;
        vector<int> used(v+1,0); used.at(1) = 1;
        priority_queue<edge*,vector<edge*>,cmp> min_heap;

        edge* ptr = heads.at(1);
        while(ptr != nullptr)
        {
            min_heap.push(ptr);
            if(ptr->a == 1)
                ptr = ptr->last_wrt_a;
            else
                ptr = ptr->last_wrt_b;
        }
        
        while(connect != v)
        {
            edge* ptr = min_heap.top();
            min_heap.pop();

            int temp;
            if(used.at(ptr->a))
                temp = ptr->b;
            else
                temp = ptr->a;
            
            if(used.at(temp) == 1)
                continue;

            sum += ptr->c;
            used.at(temp) = 1;
            connect++;

            ptr = heads.at(temp);
            while(ptr != nullptr)
            {
               min_heap.push(ptr);
               if(ptr->a == temp)
                   ptr = ptr->last_wrt_a;
               else
                   ptr = ptr->last_wrt_b;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}