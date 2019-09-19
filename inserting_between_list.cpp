#include <iostream>
using namespace std;

struct Node { 			// ceating a structure to store 
   int data; 			// int and a pointer data type
   struct Node *next; 
}; 

struct Node* head = NULL;

void insert(int new_data)
{
	struct Node* new_node = new Node(); 
	new_node->data = new_data;          // new node dta will be equal to inserted data;
	new_node->next = head;  // nodes next will be pointing to head
	head = new_node;        // head will float through out the list
							// and head will be equal to a new node
}

void display()
{
	struct Node *ptr;       // CREATING A POINTERN to transe along the ilist
	ptr = head;				// strating from head
	while(ptr != NULL){     // untill ptr dont points to null 
								// just continue
		cout<< ptr->data << " ";
		ptr = ptr->next;        // floating the pointer to nodes
	}
}


void push_in(int value , int pos)
{
	struct Node* temp = new Node();// memory created for a temp node
	struct Node* pre ;// a pre pointer to transverse along the link list
	pre = head;  //initially pre at head
	int i=0;		
	while(i != pos-2)
{
	pre = pre->next; 
	i++;
}						// incrementing i until
	temp->data = value;// its  not equal to pos
	temp->next = pre->next;
	pre->next  =temp;	

}



int main()
{
	int n,new_inserted_element,element_pos,new_inserted,element_pos1;
	cout<<"enter the value of n :" ;
	cin>>n;
	for(int i=0 ; i<n ; i++)
	{
		int a ;
		cin >> a;
		insert(a);
	}

	cout<<"enter an element for insertion :";
	cin>>new_inserted_element;
	cout<<"enter an position of element for insertion :";
	cin>>element_pos;
	push_in(new_inserted_element,element_pos);
	
	cout<<"enter an element for insertion :";
	cin>>new_inserted;
	cout<<"enter an position of element for insertion :";
	cin>>element_pos1;
	push_in(new_inserted,element_pos1);
	display();

	return 0;
}

