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

    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *next = NULL;
        Node *prev = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *insertAtTail(Node *&head, Node *&Tail, int val)
    {

        Node *temp = new Node(val);

        if (head == NULL)
        {

            head = temp;
            Tail = temp;

            return;
        }
        else
        {

            Tail->next = temp;
            Tail = temp;
        }
    }

    Node *Add(Node *first, Node *second)
    {

        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL && second != NULL)
        {

            int sum = carry + first->data + second->data;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);
            int carry = sum / 10;
            first = first->next;
            second = second->next;
        }

        while (first != NULL)
        {

            int sum = carry + first->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            int carry = sum / 10;
            first = first->next;
        }

        while (second != NULL)
        {
            int sum = carry + second->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            int carry = sum / 10;
            second = second->next;
        }

        while (carry != 0)
        {

            int sum = carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            int carry = sum / 10;
        }
    }
    Node *AddTwoLL(Node *first, Node *second)
    {

        // step 1 reverse the i/p LL ;
        first = reverse(first);
        second = reverse(second);

        // step 2 Add two LL ;

        Node *ans = Add(first, second);

        // step 3 reverse ans  LL ;

        ans = reverse(ans);

        return ans;
    }
};

int main()
{

    return 0;
}