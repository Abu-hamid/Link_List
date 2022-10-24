#include <iostream>
using namespace std;

// solve the flatten linklist ;


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

    Node *findMid(Node *head)
    {

        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

// merge the breaks linkedlist;

    Node *merge(Node *left, Node *right)
    {

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        Node *ans = new Node(-1);
        Node *temp = ans;

        while (left != NULL && right != NULL)
        {

            if (left->data < right->data)
            {

                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {

                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL)
        {

            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    Node *mergeSort(Node *head)
    {

        // base case;

        if (head == NULL || head->next == NULL)
            return head;

        // break linkedlist into two half;

        Node *mid = findMid(head);

        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;

        // recursive call for both the half of the linkedlist;

        left = mergeSort(left);
        right = mergeSort(right);

        // merge both the halves;

        Node *result = merge(right, left);

        return result;
    }
};

int main()
{

    return 0;
}