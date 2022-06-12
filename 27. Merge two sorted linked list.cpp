/* Problem Statement
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

//TC->O(N)
//Sc->O(1)
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    //it is a merged second linked list in 1st it self
    //it does not uses extra space
    while(first==NULL && second==NULL)return first;
    if(first==NULL)return second;
    if(second==NULL)return first;
    
    Node<int>* head;
    Node<int>* cur=first;
    Node<int>* prev=NULL;//for tracking prev node of cur
    while(cur!=NULL && second!=NULL){
        if(cur ->data < second -> data){
            if(prev==NULL){ //for first step 
                prev=cur;
                 cur = cur->next;
            }
            else{
                cur=cur->next;
                prev =prev->next;
            }

        }
        else{
            if(prev==NULL){
                prev =second;
                second=second ->next;
                prev->next=cur;
                first =prev;
            }
            else{
                prev->next=second;
                second=second ->next;
                prev=prev->next;
                if(prev!=NULL)prev->next =cur;
            }
        }
    }
    while(second!=NULL){
        prev ->next =second;
        prev=prev->next;
        second=second->next;
    }
    return first;
    
}
