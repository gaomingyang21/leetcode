/**
整数反转，考虑一下特殊情况：
10, 100  末尾是0
-123  负数
1000000003  越界
参考：http://rangercyh.blog.51cto.com/1444712/1306467
Date：2014-04-30
Author： gaomingyang
**/
class Solution {
public:
    int reverse(int x) {
        int nReverse = 0;
        while (x != 0) {
            nReverse = nReverse * 10 + x % 10;
            x = x / 10;
        }
        return nReverse;
    }
};
