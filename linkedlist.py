class Node:
    def __init__(self,val):
        self.val = val
        self.link = None


class LinkedList:

    def __init__(self):
        self.head = None

    def PrintLinkedList(self):
        temp = self.head
        while(temp):
            print(temp.val , end="->")
            temp = temp.link
        print()

##  Statical  main  ##
# if __name__ == '__main__':
#     node1 = LinkedList()
#     node1.head = Node(10)
#     node2 = Node(20)
#     node3 = Node(30)

#     node1.head.link = node2
#     node2.link = node3

    # node1.PrintLinkedList()



def Insertion(start):
    n = int(input("Enter the number of Elements to be added: "))
    for i in range(0,n):
        val = int(input(f"Enter the {i+1} Element : "))
        temp = Node(val)

        if start.head is None:
            start.head = temp
        else:
            p = start.head
            while p.link :
                p = p.link
            p.link = temp

    # return start




def Insertion_Start(start):
    n = int(input("Enter the element to be Inserted at First : "))
    temp = Node(n)
    temp.link = start.head
    start.head = temp
    
    # return start


def Deletion_Begging(start):

    if start.head is None:
        print("No Elements To be Deleted")
    else:
        p = start.head
        p = p.link
        start.head = p


def Insertion_End(start):
    n = int(input("ENter the element to be inserted at Last : "))
    temp = Node(n)
    p = start.head
    while(p.link):
        p = p.link
    p.link = temp


def Deletion_End(start):

    if start.head:
        p = start.head
        q = None
        while p and p.link:
            q = p
            p = p.link
        if not q:
            start.head = None
        else:
            q.link = None
    else:
        print("No Elements To be Deleted")


def Insertion_Position(start):
    pos = int(input("Enter the position to be Inserted : "))
    n = int(input(f"Enter the value to be inserted at {pos} position : "))
    temp = Node(n)
    p = start.head
    q = None
    count = 1

    while p and count < pos:
        q = p
        p = p.link
        count += 1

    if count == pos:
        q.link = temp
        temp.link = p
    else:
        print("Invalid Position")


def Deletion_Position(start):
    pos = int(input("Enter a position to delete an element : "))
    p = start.head
    q = None
    count = 1

    while p and count < pos:
        q = p
        p = p.link
        count += 1

    if not p:
        print("Position not found in the linked list.")
        return

    q.link = p.link
    p.link = None


def Length(start):
    p = start.head
    count = 0
    while p:
        count += 1
        p = p.link
    print(count)


def Reverse_LinkedList(start):
    prev = None
    curr = start.head
    nex = start.head
    while nex:
        nex = nex.link
        curr.link = prev
        prev = curr
        curr = nex
    start.head = prev

## Dynamical  Main ##
if __name__ == '__main__':
    Linked_List = LinkedList()

    while True:
        print("**********------------Main Menu------------**********")
        print("1.Insertion in Linked List")
        print("2.Insertion at Beggining")
        print("3.Insertion at Last")
        print("4.Insertion at Position")
        print("5.Deletion at Beggining")
        print("6.Deletion at Last")
        print("7.Deletion at Position")
        print("8.Length of a Liked List")
        print("9.Reverse the Linked LIst")
        print("10.Display the Linked list")
        print("**********------------------------**********")
        n = int(input("Choose any option : "))
        
        if(n == 1):
            Insertion(Linked_List)
        
        elif(n == 2):
            Insertion_Start(Linked_List)

        elif(n == 3):
            Insertion_End(Linked_List)

        elif(n == 4):
            Insertion_Position(Linked_List)

        elif(n == 5):
            Deletion_Begging(Linked_List)

        elif(n == 6):
            Deletion_End(Linked_List)

        elif(n == 7):
            Deletion_Position(Linked_List)

        elif(n == 8):
            Length(Linked_List)

        elif(n == 9):
            Reverse_LinkedList(Linked_List)

        elif(n == 10):
            Linked_List.PrintLinkedList()
        
        else:
            break