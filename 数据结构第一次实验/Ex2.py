def compare(a, b):
    """规则:比较数组 a 和 b：a < b 返回 -1，a = b 返回 0，a > b 返回 1"""
    n = len(a)
    m = len(b)
    i = 0
    # 逐位扫描公共前缀，遇到第一处不等就能定出胜负，后面的元素不用再看
    while i < n and i < m:
        if a[i] != b[i]:
            if a[i] < b[i]:
                return -1
            else:
                return 1
        i = i + 1
    # 走到这里说明公共前缀完全相等，此时只能由长度决定大小
    if n == m:
        return 0
    elif n < m:
        return -1
    else:
        return 1


print("请输入数组a的长度:")
n=int(input())
print("请输入数组a的", n, "个整数(用空格隔开):")
a=list(map(int,input().split()))

print("请输入数组b的长度:")
m=int(input())
print("请输入数组b的", m, "个整数(用空格隔开):")
b=list(map(int, input().split()))

print("数组a为:", a)
print("数组b为:", b)

res = compare(a, b)
if res < 0:
    print("a < b")
elif res == 0:
    print("a = b")
else:
    print("a > b")
