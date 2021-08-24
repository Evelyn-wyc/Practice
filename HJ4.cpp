//HJ4 字符串分割
//描述
//•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
//•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
//
//输入描述：
//连续输入字符串(输入多次, 每个字符串长度小于100)
//
//输出描述：
//输出到长度为8的新字符串数组
//
//示例1
//输入：
//abc
//123456789
//
//输出：
//abc00000
//12345678
//90000000


#include <iostream>
#include <string>

using namespace std;

void process(string str) {
    if (str.size() <= 8) {
        int j = 8 - str.size();
        for (int i = 0; i < j; i++) {
            str += '0';
        }
        cout << str << endl;
    }
    else {
        string temp(str, 0, 8);
        cout << temp << endl;
        str.erase(str.begin(), str.begin() + 8);
        process(str);
    }
}

int main()
{
    string str;
    while (cin >> str) {
        process(str);
    }
    return 0;
}