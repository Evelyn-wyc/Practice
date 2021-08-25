//HJ6 质数因子
//描述
//功能 : 输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）
//
//最后一个数后面也要有空格
//
//输入描述：
//输入一个long型整数
//
//输出描述：
//按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
//
//示例1
//输入：
//180
//
//输出：
//2 2 3 3 5


#include <iostream>
using namespace std;

bool isprime(int t) {
    if (t == 2)
        return true;
    else if (t >= 3 && t % 2 != 0) {
        for (int i = 3; i * i <= t; i += 2) {
            if (t % i == 0)
                return false;
        }
        return true;
    }
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    while (!isprime(n)) {
        for (int i = 2; i * i <= n; i++) {
            if (isprime(i) && n % i == 0) {
                n /= i;
                cout << i << ' ';
                break;
            }
        }
    }
    cout << n;
}