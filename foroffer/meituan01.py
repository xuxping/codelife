# input: [[2],[3,1],[5,3,2]]
# output: 最小和

def dfs(nums, depth, total, minSum):
    
    if depth == len(nums):
        if total < minSum[0]:
            minSum[0] = total
        return

    for item in nums[depth]:
        total += item
        dfs(nums, depth + 1, total, minSum)
        total -= item

              
def getMinSum(nums):
    minSum = [1000]
    dfs(nums, 0, 0, minSum)
    return minSum


if __name__ == "__main__":
    nums = [[2],[3,1],[5,3,2]]
    minSum = getMinSum(nums)
    assert minSum[0] == 5