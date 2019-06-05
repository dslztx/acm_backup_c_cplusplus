/*
 * 求LIS方案数模板
 *
 * 如果采用O(nlogn)的LIS算法和本算法，那么时间复杂度为O(nlogn+n^2)
 *
 * 输出一种方案，只需O(n)的时间复杂度，从后向前遍历，根据q数组进行输出。
 */
int Cal(int n, int len, int *dp)//dp[i]表示以i为末尾元素时最长上升子序列的长度
{
    int number[MAXN], num, flag;
    for (int i = 0; i < n; i++) {
        num = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (cmp(h[j], h[i])) {
                if (dp[j] == dp[i] - 1)
                    num += number[j];
            } else if (h[j] == h[i])//求不同方案数，加这个判断，5 4 3 4 3只有1种方案；否则不加，有3种方案
            {
                if (dp[j] == dp[i])
                    dp[j] = 0;
            }
        }
        if (num == 0) num = 1;

        number[i] = num;
    }
    num = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] == len)
            num += number[i];
    return num;
}
