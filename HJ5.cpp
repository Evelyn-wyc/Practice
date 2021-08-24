//HJ5 进制转换
//描述
//写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。
//
//输入描述：
//输入一个十六进制的数值字符串。注意：一个用例会同时有多组输入数据，请参考帖子https ://www.nowcoder.com/discuss/276处理多组输入的问题。
//
//输出描述：
//输出该数值的十进制字符串。不同组的测试用例用\n隔开。
//
//示例1
//输入：
//0xA
//0xAA
//
//输出：
//10
//170


#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int bit = 0;
        int ans = 0;
        for (int i = s.length() - 1; i > 1; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
                ans += (s[i] - '0') * pow(16, bit++);
            else if (s[i] >= 'A' && s[i] <= 'F')
                ans += (s[i] - 'A' + 10) * pow(16, bit++);
        }
        cout << ans << endl;
    }
    return 0;
}