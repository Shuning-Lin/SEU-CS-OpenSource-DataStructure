import java.util.Scanner;

class node<T>
{
    public T value;
    public node<T> next;
    public node(T value)
    {
        this.value=value;
        this.next=null;
    }
}

class linked_list<T>
{
    public node<T> head;
    public node<T> tail;

    public linked_list()
    {
        this.head = null;
    }

    public void add_elements(T value)
    {
        node<T> temp = new node<T>(value);
        if(head==null)
            head=tail=temp;
        else
        {
            tail.next=temp;
            tail = tail.next;
        }
    }

    public void reverse()
    {
        if(head==null || head.next==null)
            return;
        node<T> p = head;
        node<T> q = head.next;
        head.next = null;
        tail = head;
        while(q!=null)
        {
            node<T> temp = q.next;
            q.next=p;
            p=q;
            q=temp;
        }
        head=p;
    }
}

class Ex2
{
    public static void main(String args[])
    {
        System.out.println("Please input your linked_list with delimeter is \" \" ");
        Scanner in = new Scanner(System.in);
        linked_list<Integer> a = new linked_list<Integer>();
        while(in.hasNextInt())
            a.add_elements(in.nextInt());
        a.reverse();
        node<Integer> ptr = a.head;
        while(ptr!=null)
        {
            System.out.println(ptr.value);
            ptr = ptr.next;
        }
    }
}