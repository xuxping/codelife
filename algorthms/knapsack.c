//动态规划: 0-1 背包问题

#include <stdio.h>

struct item
{
    int size;  // 物品大小
    int value; // 物品价值
};

/**
 * @params itemArr: 物品集合
 * @params itemArrSize: 物品总数
 * @params W: 背包大小
 * T(n) = O(itemArrSize * W) <= O(n^2)
 **/
int knapsack(struct item itemArr[], int itemArrSize, int W)
{
    int V[itemArrSize + 1][W + 1];
    // 回溯物品
    int Keep[itemArrSize + 1][W + 1];
    // init
    for (int w = 0; w <= W; w++)
    {
        V[0][w] = 0;
    }

    for (int i = 1; i <= itemArrSize; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // note: 数组下标
            int wi = itemArr[i - 1].size;
            int vi = itemArr[i - 1].value;

            if (w >= wi && ((vi + V[i - 1][w - wi]) > V[i - 1][w]))
            {
                V[i][w] = vi + V[i - 1][w - wi];
                Keep[i][w] = 1;
            }
            else
            {
                V[i][w] = V[i - 1][w];
                Keep[i][w] = 0;
            }
        }
    }

    // 回溯物品
    int k = W;
    for (int i = itemArrSize; i >= 0; i--)
    {
        if (Keep[i][k] == 1)
        {
            printf("item --> %d, %d\n", itemArr[i - 1].size, itemArr[i - 1].value);
            k = k - itemArr[i - 1].size;
        }
    }

    //打印V数组
    for (int i = 0; i <= itemArrSize; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            printf("%d ", V[i][w]);
        }
        printf("\n");
    }

    return V[itemArrSize][W];
}

int main(void)
{
    const int arrSize = 4;
    const int W = 10;
    // struct item itemArr[arrSize] = {{1,2}, {2,4},{5,1},{6,7},{3,4},{2,6}, {10,1},{9,10},{11,2},{14,15}};
    struct item itemArr[arrSize] = {{5, 10}, {4, 40}, {6, 30}, {3, 50}};
    int maxV = knapsack(itemArr, arrSize, W);
    printf("maxV ---> %d\n", maxV);
}
