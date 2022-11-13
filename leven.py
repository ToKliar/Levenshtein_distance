def levenshtein(str1, str2):
    len1 = len(str1)
    len2 = len(str2)
    
    # 某一个字符串长度为0时，直接返回另一个字符串的长度
    if len1 == 0 or len2 == 0:
        return max(len1, len2) 
    
    dp = [[0 for i in range(len2 + 1)] for j in range(len1 + 1)]# 创建二元数组

    # 初始化边界值
    for i in range(len1 + 1):
        dp[i][0] = i
    for i in range(len2 + 1):
        dp[0][1] = i

    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            l = 1
            if str1[i-1] == str2[j-1]:
                l = 0
            # 递推
            dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1], dp[i-1][j-1] + l)) 

    return dp[len1][len2]
