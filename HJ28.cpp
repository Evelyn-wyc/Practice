//HJ28 素数伴侣
//描述
//题目描述
//若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。
//
//输入 :
//
//有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2, 30000]。
//
//输出 :
//
//输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。
//
//
//输入描述：
//输入说明
//1 输入一个正偶数n
//2 输入n个整数
//注意：数据可能有多组
//
//输出描述：
//求得的“最佳方案”组成“素数伴侣”的对数。
//
//示例1
//输入：
//4
//2 5 6 13
//2
//3 6
//
//输出：
//2
//0



#include <iostream>
#include <string>
#include <vector>
using namespace std;
//判断一个数是否为素数
bool IsPrimer(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
//匈牙利算法，为某一个目标奇数找到它的素数伴侣（偶数）,皆以下标表示
bool FindMate(const int& n, vector<vector<bool>>& map, vector<int>& match, vector<bool>& vis)
{
    for (int i = 0; i < match.size(); i++)
    {
        if (!vis[i] && map[i][n])//偶数未被访问过并且能与目标奇数组成素数（有关系）
        {
            vis[i] = true;
            if (match[i] == -1 || FindMate(match[i], map, match, vis))//当前偶数没有匹配或能给被抛弃的奇数找到新的偶数
            {
                match[i] = n;//找到这个偶数
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int num = 0;
    while (cin >> num)
    {
        int count = 0;//匹配对数
        vector<int> even;//偶数
        vector<int> odd;//奇数
        int val = 0;
        //读取数据
        while (num--)
        {
            cin >> val;
            if (val % 2 == 0)
            {
                odd.push_back(val);
            }
            else
            {
                even.push_back(val);
            }
        }
        if (odd.empty() || even.empty())
        {
            cout << count << endl;
            continue;
        }
        //建立关系表，图中的边
        vector<vector<bool>> map(even.size(), vector<bool>(odd.size(), false));
        for (int i = 0; i < even.size(); i++)
        {
            for (int j = 0; j < odd.size(); j++)
            {
                if (IsPrimer(even[i] + odd[j]))
                {
                    map[i][j] = true;
                }
            }
        }
        //建立初始匹配表
        vector<int> match(even.size(), -1);
        //为每一个奇数都尝试去找对应的偶数，    
        for (int i = 0; i < odd.size(); i++)
        {
            vector<bool> vis(even.size(), false);//每一次查找都相当于重新分配，标志要清零
            if (FindMate(i, map, match, vis))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}
