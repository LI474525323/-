#include<iostream>
#include<string>
using namespace std;
/*
计算前缀表
步骤如下：
1、初始化
2、处理前后缀不相同的情况
3、处理前后缀相同的情况
*/
void getNext(int* next, const string& s)
{
    // 前缀表都减一的情况,类似于右移
    int j = -1;
    next[0] = j;
    for(int i=1;i<s.size();i++)
    {
        //处理前后缀不相等的情况
        while(j>=0&&s[i]!=s[j+1])
            j = next[j];  //回退，那么 s[i] 与 s[j+1] 不相同，就要找 j+1前一个元素在next数组里的值（就是next[j]）。
        //处理前后缀相等的情况
        if(s[i]==s[j+1])
            j++;
        next[i] = j; //同时还要将j（前缀的长度）赋给next[i], 因为next[i]要记录相同前后缀的长度
    }
    
}

//使用next数组来做匹配
int strStr(string haystack, string needle) 
{
    if(needle.empty())
    return 0;
    int next[needle.size()];
    getNext(next,needle);
    int j = -1;
    for(int i=0;i<haystack.size();i++)
    {
        while(j>=0&&haystack[i]!=needle[j+1])     //处理不相等的情况
            j=next[j];  //回退,回退到j+1前一个元素在next(前缀表)数组里的值
        if(haystack[i]==needle[j+1])  //
            j++;
        if(j==(needle.size()-1))
            return (i - needle.size()+1);
    }
    return -1;

}

int main()
{
    string needle = "aabaaf";
    string haystack = "aabaabaafa";
    int result = strStr(haystack,needle);
    cout<< result<<endl;
    system("pause");
    return 0;
}