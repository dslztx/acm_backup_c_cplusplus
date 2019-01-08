/*
 * LCS滚动数组模版
 *
 * 如果要构造一个LCS解，那么就不能用滚动数组模版，只能用朴素模版，否则构造需要的信息量不够。
 */
#include<iostream>

using namespace std;
#define maxv(a, b) a<b?b:a
const int MAXN = 100010;
typedef char TYPE;
int lcs[2][MAXN];

int LCS(TYPE *s, TYPE *t, int m, int n)//下标从0开始
{
    lcs[0][0] = lcs[1][0] = 0;
    for (int i = 1; i <= n; i++) lcs[0][i] = 0;
    int flag = 1;
    for (int i = 1; i <= m; i++, flag = 1 - flag) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1])
                lcs[flag][j] = lcs[1 - flag][j - 1] + 1;
            else
                lcs[flag][j] = maxv(lcs[flag][j - 1], lcs[1 - flag][j]);
        }
    }
    return lcs[1 - flag][n];
}

char s[100010], t[100010];

int main() {
    int m, n;
    while (scanf("%s%s", s, t) == 2) {
        m = strlen(s), n = strlen(t);
        if (m > n)
            printf("No\n");
        else {
            if (m == LCS(s, t, m, n))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}

