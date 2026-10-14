import random
from time import perf_counter_ns
import matplotlib.pyplot as plt 

# iteration
def F1a(arr,x):
    result=0.0
    for i in range(len(arr)):
        result+=arr[i]*pow(x,i)
    return result


def F2a(arr,x):
    result=arr[len(arr)-1]
    for i in range(len(arr)-2,-1,-1):
        result=result*x+arr[i]
    return result


# recursion
def F1b(arr,x,n):
    if n<0:
        return 0

    return arr[n]*pow(x,n)+F1b(arr,x,n-1)


def F2b(arr,x,n,i):
    if i==n:
        return arr[n]

    return arr[i]+x*F2b(arr,x,n,i+1)


def main():
    array_n=[1,5,10,15,20,25,30,35,40,45,50,60,70,80,90,100]
    F1a_time=[]
    F2a_time=[]
    F1b_time=[]
    F2b_time=[]
    print("Please input the value of x:")
    x=float(input())
    for n in array_n:
        coefficents2=[]
        coefficents2.append(1.0)
        for i in range(1,n+1):
            coefficents2.append(float(1/i))

        #print(n,
        #F1a(coefficents2,x),
        #F2a(coefficents2,x),
        #F1b(coefficents2,x,n),
        #F2b(coefficents2,x,n,0))

        start=perf_counter_ns()
        F1a(coefficents2,x)
        t=perf_counter_ns()-start
        F1a_time.append(t)

        start=perf_counter_ns()
        F2a(coefficents2,x)
        t=perf_counter_ns()-start
        F2a_time.append(t)

        start=perf_counter_ns()
        F1b(coefficents2,x,n)
        t=perf_counter_ns()-start
        F1b_time.append(t)

        start=perf_counter_ns()
        F2b(coefficents2,x,n,0)
        t=perf_counter_ns()-start
        F2b_time.append(t)

    fig=plt.figure()
    plt.plot(array_n,F1a_time,'-',linewidth=2,label='F1a')
    plt.plot(array_n,F2a_time,'-',linewidth=2,label='F2a')
    plt.plot(array_n,F1b_time,'-',linewidth=2,label='F1b')
    plt.plot(array_n,F2b_time,'-',linewidth=2,label='F2b')
    plt.xlabel('n')
    plt.ylabel('time')
    plt.legend()
    plt.savefig("Ex3_1_plot")
    plt.show()

if __name__=='__main__':
    main()
