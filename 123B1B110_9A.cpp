#include <iostream>
using namespace std;

struct party {
	string name;
	party *next;
	party() {next=nullptr;}
	~party() {next=nullptr;}
	void read() {
    	cout<<"Enter the name :";
    	cin>>name;
	}
	void display() {
    	cout<<name<<endl;
	}
};

class partywaitlist {
	public:
	party * front;
	party *rear;
	partywaitlist(){rear=front=nullptr;}
    
	void addPartytowaitlist();
	void seatParty();
	void DisplayPartyWaitlist();
};

void partywaitlist :: addPartytowaitlist() {
	party *nn = new party;
	nn -> read();
	if(rear==nullptr) {
    	rear=nn;
    	front=nn;
    	cout<<"The new member added to party waitlist is : ";
    	nn -> display();
    	return;
	}
	else {
    	rear->next = nn;
    	rear=nn;
    	cout<<"The add new person to party waitlist is : ";
    	nn -> display();
	}
}

void partywaitlist :: seatParty() {
	if(front == nullptr) {
    	cout<<"All persons are seated in the party or party waitlist is empty. "<<endl;
	}
	else {
    	party * temp = front;
    	front = front -> next;
    	cout<<"The person seated in the party is : ";
    	temp -> display();
    	if(front==nullptr) {
        	rear = nullptr;
    	}
    	delete temp;
	}
}

void partywaitlist :: DisplayPartyWaitlist() {
   if(front == nullptr) {
    	cout<<"Party waitlist is empty. "<<endl;
	}
	else {
    	cout<<"The waiting list of the persons in Party are : "<<endl;
    	party * cn = front;
    	while(cn) {
        	cn->display();
        	cn=cn->next;
    	}
	}
}

int main() {
	partywaitlist p;
	cout<<"1 -> ADD THE PERSON IN PARTY WAITING LIST "
	<<endl<<"2 -> GIVE SEAT TO PERSON IN THE PARTY "
	<<endl<<"3 -> DISPLAY THE WAITING LIST "
	<<endl<<"4 ->EXIT"
	<<endl<<endl;
	int ch;
	do{
	cout<<"ENTER YOUR CHOICE : ";
	cin>>ch;
	cout<<endl;
	switch(ch){
	case 1:
     	p.addPartytowaitlist();
    	cout<<endl;
    	break;
    
	case 2:
  	p.seatParty();
  	cout<<endl;
  	break;
	 
	case 3:
 	p.DisplayPartyWaitlist();
 	cout<<endl;
	break;
    
	case 4:
	cout<<"EXITING !!!!"<<endl;
	break;
    
	default:
	cout<<"ENTER THE VALID CHOICE"<<endl;
}
}while(ch!=4);

return 0;
}  
