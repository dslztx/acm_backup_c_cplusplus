/*
 * 求LIS方案数模板
 *
 * 也可以在LIS朴素算法中直接嵌入以下流程，从而提高效率，否则如果采用O(nlogn)的LIS算法和本算法，//那么时间复杂度为O(nlogn+n^2)，而嵌入朴素算法，时间复杂度为O(n^2)
 *
 * 输出一种方案，只需O(n)的时间复杂度，从后向前遍历，根据dp进行输出。
 */
int Cal(int n, int len, int *dp)//dp[i]表示选择i后最长的序列
{
    int number[MAXN], num, flag;
    for (int i = 0; i < n; i++) {
        num = flag = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (cmp(h[j], h[i])) {
                flag = 1;
                if (dp[j] == dp[i] - 1)
                    num += number[j];
            } else if (h[j] == h[i])//求不同方案数，加这个判断，5 4 3 4 3只有1种方案；否则不加，有3种方案
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) num = 1;
        number[i] = num;
    }
    num = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] == len)
            num += number[i];
    return num;
}

