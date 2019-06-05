package dp.lcs;

/**
 * 可进行滚动数组优化，空间复杂度降低，代价是可读性变差 <br/>
 * 最长公共连续子序列，Longest Consecutive Common Sequence
 */
public class LCCS {

    int[] sa;
    int[] sb;

    int[][] dp;
    int lenOfLCS;

    public LCCS(int[] sa, int[] sb) {
        this.sa = sa;
        this.sb = sb;
    }

    public int lengthOfLCCS() {
        dp = new int[sa.length + 1][sb.length + 1];

        dp[0][0] = 0;

        for (int indexA = 1; indexA <= sa.length; indexA++) {
            dp[indexA][0] = 0;
        }

        for (int indexB = 1; indexB <= sb.length; indexB++) {
            dp[0][indexB] = 0;
        }

        int maxv = 0;

        for (int indexA = 1; indexA <= sa.length; indexA++) {
            for (int indexB = 1; indexB <= sb.length; indexB++) {
                if (sa[indexA - 1] == sb[indexB - 1]) {
                    dp[indexA][indexB] = dp[indexA - 1][indexB - 1] + 1;
                    if (dp[indexA][indexB] > maxv) {
                        maxv = dp[indexA][indexB];
                    }
                } else {
                    dp[indexA][indexB] = 0;
                }
            }
        }

        lenOfLCS = maxv;

        return lenOfLCS;
    }
}
