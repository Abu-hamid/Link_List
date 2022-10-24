#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

    Node *Sorted012(Node *head)
    {

        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        Node *temp = head;

        while (temp != NULL)
        {

            if (temp->data == 0)
                zeroCount++;

            else if (temp->data == 1)
                oneCount++;

            else if (temp->data == 2)
                twoCount++;

            temp = temp->next;
        }

        temp = head;

        while (temp != NULL)
        {

            if (zeroCount != 0)
            {
                temp->data = 0;

                zeroCount--;
            }

            else if (oneCount != 1)
            {

                temp->data = 1;
                oneCount--;
            }
            else if (twoCount != 2)
            {

                temp->data = 2;
                twoCount--;
            }

            temp = temp->next;
        }
        return head;
    }

    //  without change the  data of the linked list;

    void insertAtTail(Node *&Tail, Node *curr)
    {

        Tail->next = curr;

        Tail = curr;
    }

    Node *Sorted012(Node *head)
    {

        Node *zeroHead = new Node(-1);
        Node *zeroTail = zeroHead;
        Node *oneHead = new Node(-1);
        Node *oneTail = oneHead;
        Node *twoHead = new Node(-1);
        Node *twoTail = twoHead;

        Node *curr = head;

        while (curr != NULL)
        {

            int value = curr->data;

            if (value == 0)
            {

                insertAtTail(zeroTail, curr);
            }

            else if (value == 1)
            {
                insertAtTail(oneTail, curr);
            }

            else if (value == 2)
            {
                insertAtTail(twoTail, curr);
            }

            curr = curr->next;
        }

        // merge all the three sublist;
            
            //  1s list is not empty

        if(oneHead->next != NULL){

            zeroTail->next = oneHead->next;

        }
        else {
            // 1s list is empty;
            zeroTail->next = twoHead->next;

        }

        oneTail->next = twoHead->next;

        twoTail->next  = NULL;

        // set up the head pointer ;

        head = zeroHead->next;

        // delete the dummy node;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return head;
    }
};

int main()
{

    return 0;
}