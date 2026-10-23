class node:
    def __init__(self,value):
        self.value=value
        self.ptr=None


class linked_list:
    def __init__(self):
        self.head=None
        self.tail=None

    def add_element(self,value):
        temp=node(value)
        if self.head is None:
            self.head=self.tail=temp
        else:
            self.tail.ptr=temp
            self.tail=self.tail.ptr


def find_intersection(headA,headB):
    ptr1=headA
    ptr2=headB
    while ptr1 is not ptr2:
        if ptr1 is None:
            ptr1=headB
        else:
            ptr1=ptr1.ptr

        if ptr2 is None:
            ptr2=headA
        else:
            ptr2=ptr2.ptr
    return ptr1


if __name__=="__main__":
    a=linked_list()
    b=linked_list()
    c=linked_list()
    for i in range(1,4):
        a.add_element(i)
    for i in range(7,9):
        b.add_element(i)
    for i in range(4,7):
        c.add_element(i)

    a.tail.ptr=b.tail.ptr=c.head
    a.tail=b.tail=c.tail

    print("The following is a simple test:")
    for head in (a.head,b.head):
        ptr=head
        while ptr is not None:
            print(ptr.value,end=" ")
            ptr=ptr.ptr
        print()

    ptr=find_intersection(a.head,b.head)
    if ptr is None:
        print("No intersection")
    else:
        print("The value of the first intersection node is:")
        print(ptr.value)
