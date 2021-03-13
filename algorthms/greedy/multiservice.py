# 多人服务多人优化问题

def getMin(service_times):
    # 找那个最早被服务完的
    min_time = service_times[0]
    min_loc = 0
    for i in range(1,len(service_times)):
        if service_times[i] < min_time:
            min_time = service_times[i]
            min_loc = i
    return min_time, min_loc

if __name__ == "__main__":
    with open('input1.txt', 'r') as fp:
        lines = fp.read().split('\n')

    print(lines)
    n, s = lines[0].split()
    n,s = int(n), int(s)
    
    # n个顾客的服务时长
    service_times = [int(i) for i in lines[1].split()]

    # 采用贪心算法，将服务时间从小到大排列
    service_times.sort()
    print(service_times)
    
    # 服务窗口为空，将前s个客人进行服务
    service_window = service_times[:s]
    time = sum(service_times) # 每个人服务的时长累加
    i = s
    while(True):
        min_time, min_loc = getMin(service_window)
        # 让时间累加上其他等着的人等待的时间，
        # 后面这个n-i是控制等待的人数
        time += (min_time * (n-i))

        # 除了最先被服务完那个人的,其他几个正在被服务的人，减去这个最先被服务的人的时间
        for j in range(len(service_window)):
            if j != min_loc:
                service_window[j] -= min_time
        
        # 换人进行服务
        service_window[min_loc] = service_times[i]
        i += 1 # 指向下一个

        if i == n: break

    with open('output1.txt', 'w') as fwriter:
        fwriter.write(str(int(float(time) / n)))
    print(float(time)/n)
