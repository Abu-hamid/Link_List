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

    Node *getMiddle(Node *head)
    {

        Node *slow = head;
        Node *fast = head->next;

        while (fast->next != NULL && fast->next != NULL)
        {

            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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

    bool checkPalindrom(Node *head)
    {

        if (head->next == NULL)
        {

            return true;
        }

        // find middle of the  LL ;

        Node *middle = getMiddle(head);

        // step 2 ; reverse the  LL from the Middle to end;

        Node *temp = middle->next;
        middle->next = reverse(temp);

        // step 3 cpm both the half;

        Node *head1 = head;
        Node *head2 = middle->next;

        while (head2 != NULL)
        {

            if (head1->data != head2->data)
            {

                return false;
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        // step 4 repeat step 2;(optional)

        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};
int main()
{

    return 0;
}