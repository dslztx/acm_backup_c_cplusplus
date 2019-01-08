/*
 * 当前已求出的最长上升子序列长度为len。
 * 先判断s[i]与a[len]。若a[len]<s[i]，则将s[i]接在a[len]后将得到一个更长的上升子序列；
 * 否则，在a[1]..a[len]中，找到最大的j，满足a[j] < s[i]。令k = j + 1，此时必有a[j] < s[i] <= a[k]，更新a[k] =s[i]。
 *
 * 时间复杂度：O(nlogn)
 */
#include<iostream>

using namespace std;

//可以决定是LIS,LDS,LNDS,LNIS
#define cmp(a, b) a<b

const int MAXN = 1005;
int h[MAXN], q[MAXN];

//dp[i]表示以i为末尾元素时最长上升子序列的长度
int LIS(int n, int *dp) {
    int l, r, mid, len = 1;
    q[len] = h[0], dp[0] = len;
    for (int i = 1; i < n; i++) {
        if (cmp(q[len], h[i]))
            dp[i] = ++len, q[len] = h[i];
        else {
            l = 1, r = len;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (cmp(q[mid], h[i]))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            dp[i] = l, q[l] = h[i];
        }
    }
    return len;
}

int dp[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        printf("%d\n", LIS(n, dp));
    }
}