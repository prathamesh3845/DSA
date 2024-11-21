#include<iostream>
using namespace std;

struct webpage {
    string url;
    webpage* next;
};

class browser{
    webpage* top;
    public:
    browser(){
        top = NULL;
    }
    void push(string a){
        webpage* nn = new webpage;
        if(nn == NULL){
            cout<<"Webpage not found :"<<endl;
        }
        nn->url = a;
        nn->next = NULL;
        if(top == NULL){
        	top = nn;
        	return;
        }
        nn->next = top;
        top = nn;
    }
    string pop(){
    	if(top == NULL){
    		cout<<"No hishtory :"<<endl;
    	}
    	webpage* temp = top;
    	top = top->next;
    	return temp->url;
    }
    bool is_empty(){
    	if(top == NULL){
    		return true;
    	}
    	return false;
    }
    void display(){
    	if(top == NULL){
    		cout<<"No hishtory :"<<endl;
    		return;
    	}
    	webpage* temp = top;
    	while(temp != NULL){
    		cout<<temp->url<<" -> ";
    		temp = temp->next; 
    	}
    	cout<<"Null"<<endl;
    }
};
class webbrowser{
	browser stack1;
	browser temp;
	public:
	void new_url(){
		string a;
        	cout<<"Enter the url :";
        	cin>>a;
		stack1.push(a);
	}
	void back(){
		temp.push(stack1.pop());
	}
	void forword(){
		stack1.push(temp.pop());
	}
	bool is1_empty(){
    		return stack1.is_empty();
        }
	void del_all(){
		while (!stack1.is_empty()){
            stack1.pop();
        }
	}	
	void print(){
		stack1.display();
	}
};

int main(){
	webbrowser w;
        cout<<"1 for Add webpage "<<endl<<"2 for go backword "<<endl<<"3 for go forword "<<endl<<"4 for check empty "<<endl<<"5 for showing history "<<endl<<"6 for delete all hishtory"<<endl;
        while(true){
        	cout<<endl<<"Enter Choice : ";
         	int choice;
        	cin>>choice;
                 switch(choice){
       		 case 1:
        	 w.new_url();
        	 break;      
       		 case 2:
        	 w.back();
        	 break;
       	 	 case 3:
        	 w.forword();
        	 break;
        	 case 4:
        	 cout<<w.is1_empty()<<endl;
        	 break;
        	 case 5:
        	 w.print();
        	 break;
			 case 6:
        	 w.del_all();
        	 break;
        	 default:
         	 system("cls");
        	 cout<<"\nYou Exit"<<endl<<endl;
         	 return 0;
     	  	}
    	  }
   	 cout<<endl;   	 
	return 0;
}