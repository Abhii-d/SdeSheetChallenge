/*Given a singly linked list of integers. Your task is to return the head of the reversed linked list.*/

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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> * cur=head;
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* nxt= NULL;
    while(cur!=NULL){
        nxt= cur -> next;
        cur -> next= prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}