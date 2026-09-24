#include<iostream>
#include<string>  // std::string 的声明
#include<vector>
using namespace std;

vector<int> buildFaliure(const string& pattern)
{
    const int length=pattern.length();
    vector<int> match(length,-1);
    for(int i=1;i<length;i++)
    {
        // 若已有的最长相等前后缀能接上当前字符，就将其长度加 1。
        if(match[i-1]!=-1 and pattern[i]==pattern[match[i-1]+1])
            match[i]=match[i-1]+1;
        else
        {
            // find 是候选前缀的末尾下标；失配时逐步尝试更短的候选。
            int find=match[i-1];
            while(find!=-1)
            {
                if(pattern[i]==pattern[find+1])
                    break;
                find=match[find];  // 沿失败表回退到更短的相等前后缀
            }
            // 即使 find==-1，也要检查当前字符是否等于 pattern[0]。
            if(pattern[i]==pattern[find+1])
                match[i]=find+1;
        }
    }
    return match;
}

// 返回第一次匹配的起始下标（从 0 开始），找不到则返回 -1。
int kmpFind(const string& test,const string& pattern)
{
    // i 是文本当前下标；j 是模式串当前下标，也等于已经匹配的字符数。
    int i=0,j=0;
    vector<int> next=buildFaliure(pattern);
    while(i<test.length() and j<pattern.length())
    {
        // 当前字符相等时，两个指针一起向后移动。
        if(test[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            // 文本指针 i 不回退；模式串首字符就失配时，才直接推进 i。
            if(j==0)
                i++;
            else
                // 已匹配的是 pattern[0..j-1]，因此查 next[j-1]。
                // 加 1 将“末尾下标”还原为长度；保留 i，继续比较当前文本字符。
                j=next[j-1]+1;
        }
    }
    // 完整匹配时，i 已移到匹配区间后一位，所以起点为 i-j。
    if(j==pattern.length())
        return i-j;
    return -1;
}

int main()
{
    string text="abcdef";
    string pattern="def";
    cout<<kmpFind(text,pattern);  // 本例输出 3，即 "def" 的起始下标
    return 0;
}

//注：GPT-6 Astra(Ultra)参与后期注释以及部分代码的Debug,Coding由Shuning_Lin同学主导。
