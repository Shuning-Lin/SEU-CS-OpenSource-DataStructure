import random
import matplotlib
matplotlib.use("Agg")
from Ex1 import BinarySearch
from time import perf_counter_ns
import matplotlib.pyplot as plt

sizes=[1,2,5,10,20,30,40,50,60,70,80,90,100]
totals=[0,0,0,0,0,0,0,0,0,0,0,0,0]
times=1000

def test(n):
    total=0
    for i in range(times):
        arr=random.sample(range(315),n)
        arr.sort()
        x=random.randint(0,314)

        start=perf_counter_ns()
        BinarySearch(arr,x)
        t=perf_counter_ns()-start

        total+=t
    return total

def draw(sizes,totals):
    plt.rcParams["font.sans-serif"]=["Microsoft YaHei"]
    plt.rcParams["axes.unicode_minus"]=False

    fig,ax=plt.subplots(figsize=(8,4.8),constrained_layout=True)
    ax.plot(sizes,totals,"o-",color="#315bc4",linewidth=2)
    ax.set(xlabel="数组长度",ylabel="查找耗时(微秒)",title="平均用时")
    ax.set_xticks(sizes)
    ax.set_ylim(bottom=0)
    ax.grid(alpha=0.25)
    fig.savefig("Ex4_plot.png",dpi=300)


if __name__=="__main__":
    for i in range(len(sizes)):
        totals[i]=test(sizes[i])/times/1000
    print(totals)
    draw(sizes,totals)
    