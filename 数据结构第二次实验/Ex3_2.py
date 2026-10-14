from time import perf_counter_ns
from statistics import median
from pathlib import Path
import matplotlib.pyplot as plt


# iteration
def F1a(arr,x):
    result=0.0
    for i in range(len(arr)):
        # Calculate each power independently: O(n^2) in total.
        power=1.0
        for j in range(i):
            power*=x
        result+=arr[i]*power
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

    power=1.0
    for i in range(n):
        power*=x
    return arr[n]*power+F1b(arr,x,n-1)


def F2b(arr,x,n,i):
    if i==n:
        return arr[n]

    return arr[i]+x*F2b(arr,x,n,i+1)


# timing: median of seven batch averages, in ns per call
def run_time(func,*args):
    for i in range(100):
        func(*args)

    times=[]
    repeat=1000
    for i in range(7):
        start=perf_counter_ns()
        for j in range(repeat):
            func(*args)
        times.append((perf_counter_ns()-start)/repeat)
    return median(times)


def main():
    array_n=[1,5,10,15,20,25,30,35,40,45,50,60,70,80,90,100]
    F1a_time=[]
    F2a_time=[]
    F1b_time=[]
    F2b_time=[]
    print("Please input the value of x (1.1 for this experiment):")
    x=float(input())

    print('\nPolynomial values:')
    print('%5s%20s%20s%20s%20s'%('n','F1a','F2a','F1b','F2b'))
    for n in array_n:
        coefficents2=[]
        coefficents2.append(1.0)
        for i in range(1,n+1):
            coefficents2.append(float(1/i))

        # Print outside the timed region.
        print('%5d%20.12g%20.12g%20.12g%20.12g'%(
            n,F1a(coefficents2,x),F2a(coefficents2,x),
            F1b(coefficents2,x,n),F2b(coefficents2,x,n,0)))

        F1a_time.append(run_time(F1a,coefficents2,x))
        F2a_time.append(run_time(F2a,coefficents2,x))
        F1b_time.append(run_time(F1b,coefficents2,x,n))
        F2b_time.append(run_time(F2b,coefficents2,x,n,0))

    print('\nTime per call (ns):')
    print('n'.ljust(6)+''.join('%12d'%n for n in array_n))
    for name,times in [('F1a',F1a_time),('F2a',F2a_time),
                       ('F1b',F1b_time),('F2b',F2b_time)]:
        print(name.ljust(6)+''.join('%12.1f'%t for t in times))

    fig=plt.figure()
    plt.plot(array_n,F1a_time,'-',linewidth=2,label='F1a')
    plt.plot(array_n,F2a_time,'-',linewidth=2,label='F2a')
    plt.plot(array_n,F1b_time,'-',linewidth=2,label='F1b')
    plt.plot(array_n,F2b_time,'-',linewidth=2,label='F2b')
    plt.xlabel('n (degree)')
    plt.ylabel('time per call (ns)')
    plt.title('Polynomial evaluation (x=%g)'%x)
    plt.legend()
    plt.tight_layout()
    plt.savefig(Path(__file__).with_name('Ex3_2_plot.png'))
    plt.show()


if __name__=='__main__':
    main()
