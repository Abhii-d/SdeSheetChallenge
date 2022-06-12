/*Problem Statement
You have been given a singly Linked List of 'N' nodes with integer data and an integer 'K'. Your task is to remove the Kth node from the end of the given Linked List.*/

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    
    if(head == NULL || K ==0)return head;
    int n=0;
    LinkedListNode<int>* cur=head;
    //calculate the length of linked list
    while(cur!=NULL){
        n++;
        cur=cur->next;
    }
    //we have to delete k-n th from first 
    K =n-K;
    cur = head;
    LinkedListNode<int>* prev=NULL;
    while( K > 0){
        prev =cur;
        cur = cur -> next;
        K--;
    }
    if(prev!= NULL){
        prev->next = cur -> next;
    }
    else{
        head=head -> next;
    }
    return head;
}