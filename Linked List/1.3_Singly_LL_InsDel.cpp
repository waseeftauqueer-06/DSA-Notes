#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;


}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp-> next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertPosition(Node* head, int val, int k){
    if(head == NULL){
        return new Node(val);
    }
    else if(k == 1){
        Node* tempHead = new Node(val, head);
        return tempHead;
    }
    else{
        Node* temp = head;
        int count = 0;
        while(temp!= NULL){
            count++;
            if(count == (k-1)){
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

    }
    return head;
}

Node* insertBeforeElement(Node* head, int val, int el){
    if(head == NULL){
        return NULL;
    }
    else if(head->data == el){
        Node* tempHead = new Node(val, head);
        return tempHead;
    }
    else{
        Node* temp = head;
        int count = 0;
        while(temp -> next != NULL){
            count++;
            if(temp->next->data == el){
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }

    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    return head;

}

Node* deletePosition(Node* head, int k){
    if(head == NULL) return NULL;
    else if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else{
        Node* temp = head;
        Node* prev = NULL;
        int count = 0;

        while(temp){
            count++;
            if(count == k){
                prev -> next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
    }
    return head;
}

Node* deleteElement(Node* head, int el){
    if(head == NULL) return NULL;
    else if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else{
        Node* temp = head;
        Node* prev = NULL;
        int count = 0;

        while(temp){
            count++;
            if(temp->data == el){
                prev -> next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {123, 223, 345, 465};
    Node* head = convertArr2LL(arr);

    head = deleteElement(head, 345);

    Node* temp = head;

    // Never tamper the head
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}