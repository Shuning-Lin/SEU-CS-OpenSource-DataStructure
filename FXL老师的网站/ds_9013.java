import java.util.Scanner;

public class ds_9013 
{
    public static long recursion(int n)
    {
        if(n == 0 || n==1)
            return 1;
        return 2*recursion(n/2)+n;
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int m; m = in.nextInt();
        for(int i=0;i<m;i++)
        {
            int x; x = in.nextInt();
            System.out.println(recursion(x));
        }
    }
}
