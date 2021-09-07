// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};


// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{ 
	struct Node* curr=head;
	struct Node* ahead=curr->next;
	int ans=0,key=0,counter=0;
	unordered_map<int,int>m;
	
	int i=0;
	while(curr!=NULL&&curr->next!=NULL)
	{
	    
	    ans=x-(curr->data);
	    
	  while(ahead->next!=NULL)
	  {
	      key=ans-(ahead->data);
	      
	      if(!m[key])
	      {
	        m[ahead->data]=1;
	        ahead=ahead->next;
	      }
	      else
	      {
	          counter++;
	          ahead=ahead->next;
	      }
	      
	  }
	  m.clear();
	 curr=curr->next;
	 ahead=curr->next;
    
	}
	
	return counter;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 4);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 8);
	insert(&head, 9);

	int x = 17;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
