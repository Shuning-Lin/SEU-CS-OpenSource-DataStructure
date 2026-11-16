import java.util.Scanner;

public class ds_9014
{
    public long recursion(int n)
    {
        if(n == 0 || n == 1)
            return 1;
        return 3 * recursion((int)Math.ceil(n / 3.0)) + n*n;
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int m; m=in.nextInt();
        ds_9014 instance = new ds_9014();

        for(int i = 0;i < m;i++)
        {
            int x; x = in.nextInt();
            System.out.println(instance.recursion(x));
        }
    }
}
