#include <iostream>

using namespace std;

class Node
{
    public:
    int node_data;
    Node* next;

    Node(int data){
        node_data = data;
        next = nullptr;
    }
};

class List
{
    public:
    Node *head;

    List()
    {
        head = nullptr;
    }

    void append(int data)
    {
        Node *new_node = new Node(data);

        if(head == nullptr)
        {
            head = new_node;
            return;
        }

        Node *beginPointer = head;

        while(beginPointer->next != nullptr)
        {
            beginPointer = beginPointer->next;
        }
        beginPointer->next = new_node;
    }

    void display()
    {
        Node *beginPointer = head;
        while (beginPointer != nullptr)
        {
            cout << beginPointer->node_data << "->";
            beginPointer = beginPointer->next;
        }
        cout << "nullptr" << endl;
    }

    void reverse()
    {
        Node *beginPointer = head;
        Node *secondPointer = nullptr;

        while (beginPointer != nullptr)
        {
            Node *thirdPointer = beginPointer->next;

            beginPointer->next = secondPointer;
            secondPointer = beginPointer;
            beginPointer = thirdPointer;
        }

        head = secondPointer;
    }
};

int main() 
{
    List testList;

    testList.append(1);
    testList.append(2);
    testList.append(3);
    testList.append(4);
    testList.append(5); 
    testList.display();

    testList.reverse();
    testList.display();
}