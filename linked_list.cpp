#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* delete_first_node(struct Node* head){
    struct Node* nextHead = head->next;
    head->next = NULL;
    return nextHead;
}

struct Node* delete_node(struct Node* head,int index){
    if(index == 0)
        return delete_first_node(head);
    else{
        struct Node* ptr = head;
        while(index-1 != 0){
            ptr = ptr->next;
            index--;
        }
        ptr->next = ptr->next->next;
    }
    return head;
}

struct Node* insert_at_beginning(struct Node* head,int val){
    struct Node* newNode = new Node;
    newNode -> data = val;
    newNode -> next = head;
    return newNode;
}

void insert_at_end(struct Node* head,int val){
    struct Node* nextNode = new Node;
    nextNode->data = val;
    nextNode->next = NULL;
    while(head->next != NULL){
        head=head->next;
    }
    head->next = nextNode;
}

void print_LL(struct Node* head){
    if(head==NULL)
        cout<<"Empty Linked List";
    while(head!=NULL){
        cout<<head->data;
        if(head->next != NULL)
            cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr{2,3,5};
    // EMPTY LL
    struct Node* head;
    print_LL(head);
    // Insert all elements to the end one by one
    head = new Node;
    head->data = arr[0];
    head->next = NULL;
    for(int i=1;i<arr.size();i++){
        insert_at_end(head,arr[i]);
    }
    print_LL(head);
    // Insert all elements at the beginning one by one
    for(int i=1;i<arr.size();i++){
        head = insert_at_beginning(head,arr[i]);
    }
    print_LL(head);
    // Delete the first node
    head = delete_first_node(head);
    print_LL(head);
    // Delete ith Node(starting from 0)
    int ith_node_to_delete = 3;
    head = delete_node(head,ith_node_to_delete);
    print_LL(head);
    return 0;
}