
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

class MyList:
    def __init__(self) -> None:
        self.head = None

    def insertBeginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            new_node.next = self.head
            self.head = new_node

    def insertAtEnd(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        
        beginPointer = self.head
        while beginPointer.next != None:
            beginPointer = beginPointer.next

        beginPointer.next = new_node

    def insertAtIndex(self, data, index):
        new_node = Node(data)
        if index == 0:
            self.insertBeginning(data)

        beginPointer = self.head
        pos = 0
        while beginPointer != None and pos < index:
            beginPointer = beginPointer.next
            pos += 1

        if beginPointer is None:
            #Index out of bounds
            return
        else:
            new_node.next = beginPointer.next
            beginPointer.next = new_node

    def display(self):
        beginPointer = self.head
        while beginPointer != None:
            print(beginPointer.data, end=" -> ")
            beginPointer = beginPointer.next
        print("None")

    def reverseList(self):
        beginPointer = self.head
        secondPointer = None

        while beginPointer != None:
            thirdPointer = beginPointer.next
            beginPointer.next = secondPointer
            secondPointer = beginPointer
            beginPointer = thirdPointer

        self.head = secondPointer



linkedList = MyList()
linkedList.insertBeginning("A")
linkedList.insertAtEnd("B")
linkedList.insertAtEnd("C")
linkedList.insertAtEnd("D")
linkedList.insertAtEnd("E")
linkedList.display()

linkedList.reverseList()
linkedList.display()


