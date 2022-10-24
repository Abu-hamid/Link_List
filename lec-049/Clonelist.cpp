
/*

  ***** important code for product base company;

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *random;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

    void insertAtTail(Node *&head, Node *&tail, int d)
    {

        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // t.c  = o(n) ,  s.c = o(n);

    Node *ClonList(Node *head)
    {
        // step 1 copy the original list using the next pointer;

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;

        while (temp != NULL)
        {

            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step two Creat Map;

        unordered_map<Node *, Node *> oldToNewNode;

        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL)
        {

            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL)
        {

            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }


};

int main()
{

    return 0;
}


*/










//  T.c = o(n) , s.c = o(1);

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *random;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

    void insertAtTail(Node *&head, Node *&tail, int d)
    {

        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node *ClonList(Node *head)
    {

        // step 1 creat a clone list;

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step 2 clone node add in b/w the original list;

        Node *originalNode = head;
        Node *cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {

            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        // step 3 copy the random pointer;

        temp = head;

        while (temp != NULL)
        {

            if (temp->next != NULL)
            {

                temp->next->random = temp->random ? temp->random->next : temp->random;
            }

            temp = temp->next->next;
        }

        // step 4 reset the value done in step 2;

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {

            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {

                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        // step 5 return ans;

        return cloneHead;
    }
};

int main()
{

    return 0;
}