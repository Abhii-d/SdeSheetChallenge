/* Problem Statement
You have given a Singly Linked List of integers, determine if it forms a cycle or not.
A cycle occurs when a node's next points back to a previous node in the list. The linked list is no longer linear with a beginning and end—instead, it cycles through a loop of nodes.*/

#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/

bool detectCycle(Node *head)
{
    Node* slow=head;
    Node* fast =head;
    while(fast!=NULL ){
        
        slow=slow->next ;
        fast=fast->next;
        if(fast!=NULL)fast=fast->next;
        if(fast!=NULL && slow==fast )return true;
    }
    return false;
}