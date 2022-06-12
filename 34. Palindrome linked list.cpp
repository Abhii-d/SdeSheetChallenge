/* Problem Statement
You are given a singly Linked List of integers. Your task is to return true if the given singly linked list is a palindrome otherwise returns false.*/

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

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL)return true;
    LinkedListNode<int> * rev=new LinkedListNode<int>( head->data);
    LinkedListNode<int>* cur=head;
    cur=cur->next;
    while(cur!=NULL){
        LinkedListNode<int>* t=new LinkedListNode<int>(cur->data);
        t->next = rev;
        rev =t;
        cur =cur->next;
    }
    
    while(rev!=NULL && head!=NULL){
        if(rev->data!=head->data)return false;
        head =head->next;
        rev=rev->next;
    }
    
    return true;
}