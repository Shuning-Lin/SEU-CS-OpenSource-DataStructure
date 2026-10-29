# include<iostream>
# include<stack>
# include<unordered_map>
# include<sstream>
using namespace std;

int main()
{
    stack<int> st1;
    stack<int> st2;
    string line;
    cout<<"please input num1(the delimeter must be ' '):\n";
    getline(cin,line);
    istringstream input1(line);
    int temp;
    while(input1>>temp)
        st1.push(temp);
    cout<<"please input num2(the delimeter must be ' ' and end up with ^Z):\n";
    getline(cin,line);
    istringstream input2(line);
    unordered_map<int,int> next;
    while(input2>>temp)
    {
        if(st2.empty() or temp < st2.top())
            st2.push(temp);
        else
        {
            while(!st2.empty() and temp > st2.top() )
            {
                int temp1 = st2.top();
                next[temp1] = temp;
                st2.pop(); 
            }
        }
    }
    bool result = true;
    while(!st1.empty())
    {
        int temp = st1.top();
        st1.pop();
        if(next.find(temp) == next.end())
        {
            result = false;
            break;
        }
        else
        {
            cout<<temp<<":"<<next.find(temp)->second<<endl;
        }   
    }
    if(result == false)
        cout<<-1;
    return 0;
}