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
};

int main(){
    vector<int> arr = {123, 223, 345, 465};
    Node* x = new Node(arr[2], nullptr);
    cout<< x->data;
}