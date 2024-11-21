#include<iostream>
using namespace std;

struct word {
   string t;
   word *next;
   word *prev;
};

class textBuffer {
   word *head;
   word *tail;
   int size;
   public : 

   textBuffer(){
      size = 0;
      head = NULL;
      tail = NULL;
   }

   void add_at_beg(){
       word *nw = new word;
       if(!nw) return;
       string s;
       cout<<"enter text to prepend : ";
       cin>>s;
       nw->t = s;
       nw->next = NULL;
       nw->prev = NULL;
       if(!head){
         head = nw;
         tail = nw;
         size++;
         return;
       }
       nw->next = head;
       head->prev = nw;
       head = nw;
       size++;
}

   void add_at_end(){
       word *nw = new word;
       if(!nw) return;
       string s;
       cout<<"enter text to append : ";
       cin>>s;
       nw->t = s;
       nw->next = NULL;
       nw->prev = NULL;
       if(!head){
         head = nw;
         tail = nw;
         size++;
         return;
       }
       tail->next = nw;
       nw->prev = tail;
       tail = nw;
       size++;
}
void add_by_pos(){
      word *temp = head;
      int pos;
      cout<<"enter position to insert text : ";
      cin>>pos;
      int count = size + 1;
      if(count < pos || pos <= 0){
         cout<<": "<<pos<<" is not position in word list"<<endl;
         return;
      }
      if(pos == 1){
         add_at_beg();
         return;
      }
      if(pos == count){
         add_at_end();
         return;
      }
      string s;
      cout<<"enter text to insert : ";
      cin>>s;
      word *nw = new word;
      if(!nw) return;
      nw->t = s;
      nw->next = NULL;
      nw->prev = NULL;
      pos -= 1; 
      while(--pos){
        temp = temp->next;
      }
      nw->next = temp->next;
      nw->prev = temp;
      temp->next->prev = nw;
      temp->next = nw;
      size++;
}

void del_from_beg(){
      if(!head){
         cout<<"text Buffer is Empty can't delete !"<<endl;
         return;
      }
      word* temp = head;
      if(head == tail){
         head = NULL;
         tail = NULL;
         size--;
         delete temp;
         return;
      }
      temp->next->prev = NULL;
      head = temp->next;
      size--;
      delete temp;
} 
void del_from_end(){
      if(!head){
         cout<<"text Buffer is Empty can't delete   `"<<endl;
         return;
      }
      word* temp = head;
      if(head == tail){
         head = NULL;
         tail = NULL;
         delete temp;
         size--;
         return;
      }
      word* ptr2 = tail;
      tail = ptr2->prev;
      ptr2->prev->next = NULL;
      size--;
      delete ptr2; 
}
void del_by_pos(){
      word *temp = head;
      int pos;
      cout<<"enter position to remove : ";
      cin>>pos;
      if(size < pos || pos <= 0){
         cout<<": "<<pos<<" is not position in word list"<<endl;
         return;
      }
      if(pos == 1){
         del_from_beg();
         return;
      }
      if(pos == size){
         del_from_end();
         return;
      }
      pos -= 1; 
      while(pos--){
        temp = temp->next;
      }
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      size--;
      delete temp;
}

void search(){
     if(head == NULL){
        cout<<": list is empty can't search for your key "<<endl;
        return;
     }
     string key;
     cout<<"enter the text to search : ";
     cin>>key;
     word *temp = head;
     if((head == tail && head->t == key) || temp->t == key){
        cout<<": "<<key<<" is searched."<<endl;
        return;
     }
     temp = temp->next;
     while(temp){
        if(temp->t == key){
           cout<<": "<<key<<" is searched."<<endl;
           return;
        }
        else {
          temp = temp->next;
        }
     }
     cout<<": "<<key<<" is not searched."<<endl;
     return;  
}
void del_all(){
   word *temp = head;
   while(temp != head){
      word *temp = temp;
      temp = temp->next;
      delete temp;
   }
   delete head; 
   cout<<"List is empty :";
}
void display(){
     word* temp = head;
     if(!head){
        cout<<": list is empty can't show"<<endl;
        return;
     }
     while(temp){
        cout<<temp->t<<" ";
        temp = temp->next; 
     }
    cout<<endl; 
}
void info_state() {
      cout<<"1 for Add to beginning"<<endl;
      cout<<"2 for Add to end"<<endl;
      cout<<"3 for Add by given position"<<endl;
      cout<<"4 for deleting from beginning"<<endl;
      cout<<"5 for deleting from end"<<endl;
      cout<<"6 for deleting by given position"<<endl;
      cout<<"7 for search"<<endl;
      cout<<"8 for delete all"<<endl;
      cout<<"9 for display"<<endl;
   }
};

int main(){
   textBuffer s;
   cout<<endl;
   
   while(true) {
      s.info_state();
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
          s.add_by_pos(); 
          break;
         case 4:
          s.del_from_beg(); 
          break;
         case 5:
          s.del_from_end(); 
          break;
         case 6:
          s.del_by_pos(); 
          break;
         case 7:
          s.search(); 
          break;
         case 8:
          s.del_all(); 
          break;
         case 9:
          s.display(); 
          break;
         default: 
         cout<<"\nYou Exit"<<endl<<endl; 
         return 0;
      }
      cout<<endl;
   }     
   return 0;
}