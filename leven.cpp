#include<iostream>
#include<vector>
using namespace std;

int levenshtein(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    // 某一个字符串长度为0时，直接返回另一个字符串的长度
    if (len1 == 0 || len2 == 0) {
        return len1 > 0 ? len1 : len2;
    }

    vector<vector<int>> dp(len1+1, vector<int>(len2+1));
    
    // 初始化边界值
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }

    for (int i = 0; i <= len2; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int l = str1[i-1] == str2[j-1] ? 0 : 1;
            dp[i][j] = dp[i-1][j] + 1;
            dp[i][j] = dp[i][j] < dp[i][j-1] + 1 ? dp[i][j] : dp[i][j-1] + 1;
            dp[i][j] = dp[i][j] < dp[i-1][j-1] + l ? dp[i][j] : dp[i-1][j-1] + l;
        }
    }

    return dp[len1][len2];
}