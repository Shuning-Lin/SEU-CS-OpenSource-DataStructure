class node<T>
{
    public T value;
    public node<T> ptr;
    public node(T value)
    {
        this.value = value;
        this.ptr = null;
    }
}

class link_list<T>
{
    public node<T> head;
    public link_list()
    {
        this.head = null;
    }
    public void add(T value)
    {
        node<T> temp = new node<T>(value);
        if(head == null)
            head = temp;
        else
        {
            temp.ptr = head;
            head = temp;
        }
    }
    public T pop()
    {
        T temp = head.value;
        head = head.ptr;
        return temp;
    }

}

class queue<T>
{
    public link_list<T> a = new link_list<T>();
    public link_list<T> b = new link_list<T>();
    public queue()
    {
        //empty body
    }
    public void push(T value)
    {
        a.add(value);
    }
    public T pop()
    {
        while(a.head != null)
            b.add(a.pop());
        T temp = b.pop();
        while(b.head != null)
            a.add(b.pop());
        return temp;
    }
    public boolean empty ()
    {
        return a.head == null;
    }
    public T peek()
    {
        while(a.head != null)
            b.add(a.pop());
        T temp = b.pop();
        a.add(temp);
        while(b.head != null)
            a.add(b.pop());
        return temp;        
    }
}

public class Ex2
{
    public static void main(String[] args)
    {
        queue<Integer> q = new queue<Integer>();
        for(int i=1;i<=6;i++)
            q.push(i);
        System.out.println(q.pop());
        System.out.println(q.peek());
        System.out.println(q.empty());
    }
}
