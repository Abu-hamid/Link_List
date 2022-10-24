#include<iostream>
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




    Node*uniqueSorted(Node*head){

        if(head == NULL)
        return NULL;

        // non empty linked list;

        Node*curr = head;

        while(curr != NULL){

            if((curr->next != NULL) && curr->data == curr->next->data){

                Node*next_next = curr->next->next;
                Node*nodeToDelete = curr->next;
                delete(nodeToDelete);
                curr->next = next_next;

            }

            else{

                curr = curr->next;
            }
        }

        return head;
    }
};

int main(){

return 0;
}