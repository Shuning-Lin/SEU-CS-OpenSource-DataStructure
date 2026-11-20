import java.util.Scanner;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Arrays;

class edge
{
    public int a,b,c;
    public edge last_wrt_a = null;
    public edge last_wrt_b = null;

    public edge(int a, int b, int c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class state
{
    public state(int position,int distance)
    {
        this.position = position;
        this.distance = distance;
    }
    public int position;
    public int distance;
}

class statecmp implements Comparator<state>
{
    public int compare(state x, state y)
    {
        return Integer.compare(x.distance,y.distance);
    }
}

public class ds_9029
{
    static public void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        for(int i = 0;i < n;i++)
        {
            int v,e,s,t;
            v = in.nextInt();
            e = in.nextInt();
            s = in.nextInt();
            t = in.nextInt();

            edge[] vertex = new edge[v+1];
            int[] used = new int[v+1];
            Arrays.fill(used,-1);

            PriorityQueue<state> min_heap = new PriorityQueue<state>(new statecmp());
            
            for(int j = 0;j<e;j++)
            {
                int a,b,c;
                a = in.nextInt();
                b = in.nextInt();
                c = in.nextInt();
                edge temp = new edge(a,b,c);

                temp.last_wrt_a = vertex[temp.a];
                temp.last_wrt_b = vertex[temp.b];

                vertex[temp.a] = temp;
                vertex[temp.b] = temp;
            }

            used[s] = 0;
            edge ptr = vertex[s];
            while(ptr != null)
            {
                edge temp = ptr;
                int position;
                if(temp.a == s)
                {
                    ptr = ptr.last_wrt_a;
                    position = temp.b;
                }
                else
                {
                    ptr = ptr.last_wrt_b;
                    position = temp.a;
                }
                min_heap.add(new state(position,used[s]+temp.c));
            }

            while(used[t] < 0 && !min_heap.isEmpty())
            {
                state temp0 = min_heap.poll();
                if(used[temp0.position] < 0)
                    used[temp0.position] = temp0.distance;
                else
                    continue;

                ptr = vertex[temp0.position];
                
                while(ptr != null)
                {
                    edge temp = ptr;
                    int position;
                    if(temp.a == temp0.position)
                    {
                        ptr = ptr.last_wrt_a;
                        position = temp.b;
                    }
                    else
                    {
                        ptr = ptr.last_wrt_b;
                        position = temp.a;
                    }
                    min_heap.add(new state(position,used[temp0.position]+temp.c));
                }
            }
            System.out.println(used[t]);
        }
    }
}