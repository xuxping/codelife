

def swap(a, b):
    temp = a
    a = b
    b = temp

def rotate(matrix):
    rowLen, colLen = len(matrix), len(matrix[0])
    last = rowLen-1
    level = 0
    while(level < rowLen/2):
        for i in range(level, last):
            matrix[level][i], matrix[i][last] = matrix[i][last], matrix[level][i]
            matrix[level][i], matrix[last][last-i+level] = matrix[last][last-i+level], matrix[level][i]
            matrix[level][i], matrix[last-i+level][level] = matrix[last-i+level][level], matrix[level][i]
            
        level += 1
        last -= 1


def display(matrix):
    for a in matrix:
        print(a)
    print("----------------")

            

if __name__ == '__main__':
    matrix = [
            [1,2,3,4],
            [5,6,7,8],
            [9,10,11,12],
            [13,14,15,16]
            ]
    display(matrix)
    rotate(matrix)
    display(matrix)


