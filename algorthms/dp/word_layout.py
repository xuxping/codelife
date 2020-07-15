# 给定n个单词，要求对单词进行排版，每行单词的字母数和不能大于每行的限制大小
# 要求排版美观
# badness(j,i) = (wp - wi->j)**3

import sys
# https://www.bilibili.com/video/av370385193/

def word_layout(strs, p=18):
    strlens = [len(s) for s in strs]
    DP = [0]* (len(strs) + 1)
    his = [0] * (len(strs) + 1)

    for i in range(1, len(strs) + 1):
        minbad = sys.maxsize
        his_j = -1
        for j in range(0, i):
            wij = sum(strlens[j:i])
            if wij <= p:
                bad = (p - wij)**3
                if DP[j] + bad <= minbad:
                    minbad = DP[j] + bad
                    his_j = j
                    
        DP[i] = minbad
        if his_j!=-1:
            his[i] = his_j
    print(DP)
    print(his)
    # 输出排版结果
    s = his[-1]
    e = len(his) - 1
    res = []
    while(s != e):
        res.append(strs[s:e])
        e = s
        s = his[s]
    res.reverse()
    print(res)


if __name__ == "__main__":
    # s = 'do you like those people who always think of money and cannot remember the past'
    # s = 'world world world world worldroldlsldf'
    s = 'good book good book good book good book'
    strs = s.split()
    print(strs)
    print(len(strs))
    word_layout(strs, 15)