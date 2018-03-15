
#include<iostream>
#include<string>
#include<cctype>
#include <vector>
#include<cstring>
//#include<stdexcept>
#include<exception>
using namespace std;

class Solution {
public:
    int  NumberOf1(int n) {
        int charNum = sizeof(n);
        cout<<charNum<<endl;
        int flag = n;
        int num = 0;
        ////防止负数最高位是1而无限右移，1有无数个，陷入死循环
        //i < charNum * 8,32位机子整数就是用32位表示
        for (int i = 0; i < charNum * 8; i++)
        {
            if (flag & 1)
                num++;
            flag = flag >> 1;
        }
        return num;
    }
};

/*
链接：https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8
来源：牛客网

//思想：用1（1自身左移运算，其实后来就不是1了）和n的每位进行位与，来判断1的个数
    private static int NumberOf1_low(int n) {
        int count = 0;
        int flag = 1;
        while (while(flag <=n)) {
            if ((n & flag) != 0) {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
    //--------------------最优解----------------------------
    public static int NumberOf1(int n) {
        int count = 0;
        while (n != 0) {
            ++count;
            n = (n - 1) & n;//n&(n-1)表示将一个整数的二进制形式的最后一个1变为0.所以可以利用这个特性来计算1的数量。
        }
        return count;
    }
*/
int main()
{
    Solution so;
    int n;
    int num;
    while (true)
    {
        cout << "请输入一个正数: ";
        cin >> n;
        num = so.NumberOf1(n);
        cout << "改数二进制表示中1个数为： " << num << endl;
        cout << endl;
    }


}
