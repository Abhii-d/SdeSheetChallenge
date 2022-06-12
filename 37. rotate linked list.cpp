/* Problem Statement
You have been given a Linked List having ‘N’ nodes and an integer ‘K’. You have to rotate the Linked List by ‘K’ positions in a clockwise direction.*/

#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
       if(head==NULL || head->next==NULL || k==0){
        return head;
    }
    
    int len=1;
    Node* curr=head;
    
    while(curr->next!=NULL){
        curr=curr->next;
        len++;
    }
    
    curr->next=head;
    k=k%len;
    k=len-k;
    while(k--){
        curr=curr->next;
    }
    head=curr->next;
    curr->next=NULL;
    
    return head;
    
}