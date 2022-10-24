#include <iostream>
#include <map>
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
};

// detect the cycle in the linked list; 

/*

bool cycledetcted(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        if (visited[temp] == true)
            return true;

        visited[temp] = true;

        temp = temp->next;
    }

    return false;
}
*/



Node* floyed(Node*head){


    if(head == NULL){
        return NULL;

    }

    Node * slow = head;
    Node * fast = head;

    while(slow !=NULL && fast != NULL){

        fast = fast ->next;

        if(fast != NULL)
        fast = fast->next;

        slow = slow->next;

        if(slow == fast)
        cout<< " cycle present"<< slow->data<<endl;

        return slow;

    }
    return NULL;

}




// find the starting node of cycle detction frm the linked list;


Node* getstartingNode(Node*head){

    if(head == NULL)
        return NULL;

    Node*intersection  = floyed(head);

    if(intersection == NULL)
    return NULL;
    Node*slow = head;

    while(slow != intersection){

        slow = slow->next;

        intersection = intersection->next;
    }
    return slow;

}

// Remove loop from the linked list;

Node* removeloop(Node*head){

    if(head == NULL)
    return ;

    Node*startOfLoop = getstartingNode(head);
    
    if(startOfLoop == NULL)    
        return head;

    Node*temp = startOfLoop;

    while(temp->next != startOfLoop){

        temp = temp->next;
    }

    temp->next = NULL;
}


int main()
{

    return 0;
}