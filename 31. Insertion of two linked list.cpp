/*Problem Statement
You are given two Singly Linked List of integers, which are merging at some node of a third linked list.
Your task is to find the data of the node at which merging starts. If there is no merging, return -1.*/


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
//TC ->O(N)
//SC ->O(N)

int findIntersection(Node *firstHead, Node *secondHead)
{
    
    map<Node*,bool> visited;
       Node* cur=firstHead;
    while(cur!=NULL){
        visited[cur]=true;
        cur=cur->next;
    }
    cur=secondHead;
    while(cur!=NULL){
        if(visited.find(cur)!=visited.end()){
            return cur->data;
        }
        cur=cur->next;
    }
    return -1;
}