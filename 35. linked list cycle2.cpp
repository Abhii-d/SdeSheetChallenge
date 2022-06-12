/* Problem Statement
You have been given a singly linked list which may or may not contain a cycle. You are supposed to return the node where the cycle begins (if a cycle exists).
A cycle occurs when a node's next pointer points back to a previous node in the list. The linked list is no longer linear with a beginning and end—instead, it cycles through a loop of nodes.*/

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

Node *firstNode(Node *head)
{
    if(head==NULL || head->next == NULL){

       return NULL;

   }
    Node *slow = head;
    Node *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast&& fast->next){
          if(slow==fast)break;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow!=fast)
        return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}