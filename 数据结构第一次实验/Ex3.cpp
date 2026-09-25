#include<iostream>
#include<iomanip>
#include<vector>
#include<tuple>
#include<string>
using namespace std;


class element
{
public:    
    element(int r,int c,int v):row(r),col(c),value(v)
    {
        //empty body
    }
    int row;
    int col;
    int value;
};

class SparseMatrix
{
public:
    SparseMatrix(int r,int c,int t,const vector<element>& e):rows(r),cols(c),terms(t),smArray(e)
    {
        //empty body
    }
    SparseMatrix(int r,int c,int t):rows(r),cols(c),terms(t),smArray(vector<element>(terms,element(-1,-1,-1)))
    {
        //empty body
    }
    SparseMatrix FastTranspose()
    {
        SparseMatrix b(cols,rows,terms);
        if(terms>0)
        {
            tuple<int,int> *record=new tuple<int,int>[cols];  //数量&开始位置
            //原题的fill我认为可迁移性不强，故这里就不再另写一个成员函数
            for(int i=0;i<cols;i++)
            {
                get<0>(record[i])=0;
                get<1>(record[i])=0;
            }
            for(int i=0;i<terms;i++)
                get<0>(record[smArray[i].col])++;
            for(int i=1;i<cols;i++)
                get<1>(record[i])=get<1>(record[i-1])+get<0>(record[i-1]);
            for(int i=0;i<terms;i++)
            {
                int j=get<1>(record[smArray[i].col]);
                b.smArray[j].row=smArray[i].col;
                b.smArray[j].col=smArray[i].row;
                b.smArray[j].value=smArray[i].value;
                get<1>(record[smArray[i].col])++;
            }
            delete[] record;
        }
        return b;
    }
    //可视化：把稀疏矩阵铺成 rows x cols 的完整表格
    void Display() const
    {
        vector<vector<int>> arr(rows,vector<int>(cols,0));
        for(int i=0;i<terms;i++)
        {
            int r=smArray[i].row;
            int c=smArray[i].col;
            arr[r][c]=smArray[i].value;
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                    cout<<setw(3)<<arr[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    //可视化：直接列出三元组表，便于核对转置前后元素的排列顺序
    void DisplayTerms(const string& name) const
    {
        for(int i=0;i<terms;i++)
            cout<<"  ["<<i<<"]  ("<<smArray[i].row<<", "<<smArray[i].col<<", "<<smArray[i].value<<")"<<endl;
        cout<<endl;
    }
private:
    int rows;
    int cols;
    int terms;
    vector<element> smArray;
};

int main()
{
    //测试用例：
    //    0 12  9  0  0  0  0
    //    0  0  0  0  0  0  0
    //   -3  0  0  0  0 14  0
    //    0  0 24  0  0  0  0
    //    0 18  0  0  0  0  0
    //   15  0  0 -7  0  0  0
    vector<element> data={element(0,1,12),element(0,2,9),element(2,0,-3),element(2,5,14),
                          element(3,2,24),element(4,1,18),element(5,0,15),element(5,3,-7)};
    SparseMatrix a(6,7,data.size(),data);
    a.Display();
    a.FastTranspose().Display();
    return 0;
}

//注：GPT-6 Astra(Ultra)&DeepSeek V4.1 flash参与后期注释以及部分代码的Debug,Coding由Shuning_Lin同学主导。