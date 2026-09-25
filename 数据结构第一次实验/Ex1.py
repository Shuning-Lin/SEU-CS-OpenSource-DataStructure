import random

print("请输入n的大小:")
n=int(input())

arr=[random.randint(0,101) for i in range(n)]
arr.sort()
print("生成的升序数组为:",arr)


print("请输入你想要寻找的目标值:")
target=int(input())

l=0
r=n-1
while(l<=r):
    mid=(l+r)//2  #左偏型
    select=arr[mid]
    if target==select:
        break
    elif target<select:
        r=mid-1
    else:
        l=mid+1
if l>r:
    print("没有找到该数,顺序插入下标应为:",l)
else:
    print("找到该数,其下标为:",mid)

# 注：GPT-6 Astra(Ultra)&DeepSeek V4.1 flash参与后期注释以及部分代码的Debug,Coding由Shuning_Lin同学主导。