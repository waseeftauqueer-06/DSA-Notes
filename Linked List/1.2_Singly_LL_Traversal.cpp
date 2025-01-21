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

//Searching an element in LL

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {123, 223, 345, 465};
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    int count = 0;
    // Never tamper the head
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout<< "The count of LL is "<< count;
}