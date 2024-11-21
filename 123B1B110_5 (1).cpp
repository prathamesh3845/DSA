#include<iostream>
using namespace std;

struct node {
  string data;
  node *next;
};

class employee {

   node *head;
   node *tail;
   
   public:
   employee() {
      head = NULL;
      tail = NULL;
   }
   
   void add_at_beg() {
      string t;
      cout<<"Enter your string which you want to add at first: ";
      cin>>t;
      node *nn = new node;
      if(!nn){
         cout<<"Node not created "<<endl;
         return;
      }
      nn->data = t;
      if(head == NULL){
         head = nn;
         tail = nn;
         nn->next = head;
         return;
      }
      nn->next = head;
      tail->next = nn;
      head = nn;
   }
   
   void add_at_end() {
      string t;
      cout<<"Enter your string which you want to add at the end: ";
      cin>>t;
      node *nn = new node;
      if(!nn) {
         cout<<"Node not created "<<endl;
         return;
      }
      nn->data = t;
      if(head == NULL) {
         head = nn;
         tail = nn;
         nn->next = head;
         return;
      }
      tail->next = nn;
      tail = nn;
      tail->next = head;
   }

   void add_at_next_to_word() {
      string t, r;
      cout<<"Enter your string which you want to add: ";
      cin>>t;
      cout<<"Enter the word after which you want to add your string: ";
      cin>>r;
      
      node *nn = new node;
      if(!nn) {
         cout<<"Node not created "<<endl;
         return;
      }
      nn->data = t;
      if(head == NULL) {
         cout<<"List is empty."<<endl;
         return;
      }
      node *temp = head;
      do {
         if(temp->data == r) {   
            nn->next = temp->next;
            temp->next = nn;
            if(temp == tail) {
               tail = nn;
            }
            return;
         }
         temp = temp->next;
      } while(temp != head);
      
      cout<<r<<" NOT found "<<endl;
   }
   
   void del_at_beg() {
      if(!head) {
         cout<<"List is empty, cannot delete "<<endl;
         return;
      }
      if(head == tail) {
         delete head;
         head = NULL;
         tail = NULL;
         return;
      }
      node *temp = head;
      head = head->next;
      tail->next = head;
      delete temp;
   }
   
   void del_at_end() {
      if(!head) {
         cout<<"List is empty, cannot delete "<<endl;
         return;
      }
      if(head == tail) {
         delete head;
         head = NULL;
         tail = NULL;
         return;
      }
      node *temp = head;
      while(temp->next != tail) {
         temp = temp->next;
      }
      delete tail;
      tail = temp;
      tail->next = head;
   }
   
   int search() {
      string t;
      cout<<"Enter the string you want to search in the linked-list: ";
      cin>>t;
      if(!head) return 0;
      node *temp = head;
      do {
         if(temp->data == t) {
            return 1;
         }
         temp = temp->next;
      } while(temp != head);
      return 0;
   }
   
   void search_and_del() {
      string t;
      cout<<"Enter the string you want to delete from the linked-list: ";
      cin>>t;
      if(!head) {
         cout<<"List is empty"<<endl;
         return;
      }
      if(head->data == t) {
         del_at_beg();
         return;
      }
      if(tail->data == t) {
         del_at_end();
         return;
      }
      node *temp = head;
      do {
         if(temp->next->data == t) {
            node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            if(temp->next == head) {
               tail = temp;
            }
            return;
         }
         temp = temp->next;
      } while(temp != head);
   }
   
   void del_all() {
      while(head != NULL) {
         del_at_beg();
      }
   }
   
   void Display() {
      if(head == NULL) {
         cout<<"Your list is empty"<<endl;
         return;
      }
      node *temp = head;
      do {
         cout<<temp->data<<" ";
         temp = temp->next;
      } while(temp != head);
      cout<<endl;
   }

   void info_state() {
      cout<<"1 for Add to beginning"<<endl;
      cout<<"2 for Add to end"<<endl;
      cout<<"3 for Add after given word"<<endl;
      cout<<"4 for deleting at beginning"<<endl;
      cout<<"5 for deleting at end"<<endl;
      cout<<"6 for searching"<<endl;
      cout<<"7 for search and delete"<<endl;
      cout<<"8 for delete all"<<endl;
      cout<<"9 for display"<<endl;
   }
};
 
int main() {
   employee s;
   cout<<endl;
   s.info_state();
   while(true) {
      cout<<endl<<"Enter Choice: ";
      int choice;
      cin>>choice;
      switch(choice) {
         case 1:
          s.add_at_beg();
          break;      
         case 2:
          s.add_at_end(); 
          break;
         case 3:
          s.add_at_next_to_word(); 
          break;
         case 4:
          s.del_at_beg(); 
          break;
         case 5:
          s.del_at_end(); 
          break;
         case 6:
          cout<<s.search()<<endl; 
          break;
         case 7:
          s.search_and_del(); 
          break;
         case 8:
          s.del_all(); 
          break;
         case 9:
          s.Display(); 
          break;
         default: 
         cout<<"\nYou Exit"<<endl<<endl; 
         return 0;
      }
      s.info_state();
   }
   return 0;
}
