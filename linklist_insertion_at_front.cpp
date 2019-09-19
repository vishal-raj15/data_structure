#include <iostream>
using namespace std;
struct Node { 
   int data; 
   struct Node *next; 
}; 

struct Node* head = NULL;
void insert(int new_data){
	struct Node* new_node = new Node(); 
	new_node->data = new_data;          // new node dta will be equal to inserted data;
	new_node->next = head;  // nodes next will be pointing to head
	head = new_node;        // head will float through out the list
							// and head will be equal to a new node
}

void display(){
	struct Node *ptr;       // CREATING A POINTERN to transe along the ilist
	ptr = head;				// strating from head
	while(ptr != NULL){     // untill ptr dont points to null 
								// just continue
		cout<< ptr->data << " ";
		ptr = ptr->next;        // floating the pointer to nodes
	}
}

// inserting the node in front of thr head
void first(int value){
	struct Node* temp = new Node();   // creating the space
	temp->data = value;             // intialising the data to that node
	temp->next = head;			// it points to head
	head = temp;				//and then declaring temp as head

}

// void push_in(int value , int p){

// }


int main(int argc, char const *argv[])
{
	int n;
	cout<<"enter the value of n :" ;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		int a ;
		cin >> a;
		insert(a);
	}

	
	first(69);
	display();

	return 0;
}

