#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node* insertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head -> back = newNode;

    return newNode;
}

Node* insertBeforeTail(Node* head, int val){
    if(head -> next == NULL){
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* newNode = new Node(val, tail, prev);

    prev -> next = newNode;
    tail -> back = newNode;

    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int val){
    if(k == 1){
        return insertBeforeHead(head, val);
    }
    
    Node* temp = head;
    int cnt = 0;
    while(temp!= NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }

    Node* prev = temp -> back;
    Node* newNode = new Node(val, temp, prev);

    prev -> next = newNode;
    temp -> back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){
    Node* prev = node -> back;
    Node* newNode = new Node(val, node, prev);
    prev -> next = newNode;
    node -> back = newNode;
}

void print(Node* head){
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main(){
    vector<int> arr = {12, 3, 4, 6, 8};
    Node *head = convertArr2DLL(arr);
    head = insertBeforeKthElement(head, 3, 10);
    print(head);
    return 0;
}
