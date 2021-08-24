//HJ1 字符串最后一个单词的长度
//描述
//计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。
//
//输入描述：
//输入一行，代表要计算的字符串，非空，长度小于5000。
//
//输出描述：
//输出一个整数，表示输入字符串最后一个单词的长度。
// 
//示例1
//输入：
//hello nowcoder
//输出：
//8
//说明：
//最后一个单词为nowcoder，长度为8


#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[5001];
    cin.getline(str, 5000);
    int len = 0;
    for (int i = strlen(str) - 1; str[i] != ' ' && i >= 0; i--)
        len++;
    cout << len << endl;
}