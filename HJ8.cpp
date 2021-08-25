﻿//HJ8 合并表记录
//描述
//数据表记录包含表索引和数值（int范围的正整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
//
//输入描述：
//先输入键值对的个数
//然后输入成对的index和value值，以空格隔开
//
//输出描述：
//输出合并后的键值对（多行）
//
//示例1
//输入：
//4
//0 1
//0 2
//1 2
//3 4
//
//输出：
//0 3
//1 2
//3 4


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> array(600, 0);
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        array[a] += b;
    }
    for (int i = 0; i < 600; i++)
    {
        if (array[i] != 0)
            cout << i << ' ' << array[i] << endl;
    }
}