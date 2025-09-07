#include <iostream>
using namespace std;

 //______________________________
 // Data Model
 //______________________________

 struct User{
	string username;
	string password
	User* next;

	User(string u, string p){
	   username = u;
	   password = p;
	   next = nullptr;
	}
};
bool insertUser(User*& head, const string& username, const string& password);
User* findUser(User* head, const string& username);
bool authenticate(User* head, const string& username, const string& password);
bool removeFront(User*& head);
bool removeByUsername(User*& head, const string& username);

int main() {
	User* head = nullptr;

	insertUser(head, "John Andrews","drew3233*");
	insertUser(head, "Kylie Lee", "stormi04:)");
	insertUser(head, "Mary Sally", "kkk87393");

	if(!insertUser(head, "Mary Sally", "krazyi24938"){
	cout << "This username is not available. Please enter a unique username./n";
	}

	User* u = findUser(head, "Kylie Lee");
	if(u){
	cout << "User found: " << u->username << endl;
	}

	cout << "Authenticating User: Kylie Lee Password:**********/n"
	<< authenticate(head, "Kylie Lee", "stormi04:)")? "Verified!" : "Incorrect Username or Password" << endl;
	cout << "Authenticating User: Mary Sally Password:Kennedy321=0" 
	<< authenticate(head, "Mary Sally", "Kennedy321=0")? "Verified!" : "Incorrect Username or Password" << endl;

	removeFront(head);
	cout << "After removing front: " << endl;
	
	removeByUsername(head, "Kylie Lee");
	cout << "Current Users: " << endl;
	


	return 0;
}
bool insertUser(User*& head, const string& username, const string& password){
	if(!head){
	  head = new User(username, password);
          return true;
	}

	User* current = head;
	while(current){
	     if(current->username == username){
	 	 return false;
		}
		if(!current->next){
	  	  break;
		}
		current = current->next;
	}
	current->next = new Username(username, password);
	return true;
}

User* findUser(User* head, const string& username){
	User* current = head;
	while(current){
	    if(current->username == username){
		return current;
	     }
	     current = current->next;
	}
	return nullptr;
}

bool authenticate(User* head, const string& username, const string& password){
	User* current = findUser(head, username);
	return current && current->password == password;
}

bool removeFront(User*& head){
	if(!head){
	 return false;
	}
	User* temp = head;
	head = head->next;
	delete temp;
	return true;
}

bool removeByUsername(User*& head, const string& username){
	if(!head){
	return false;
	}

	if(head->username == username){
	   User* temp = head;
	   head = head->next;
	   delete temp;
	   return true;
	}

	User* current = head;
	while(current->next){
	    if (current->next->username == username){
	       	User* t = current->next;
	  	current->next = current->next->next;
		delete t;
		return true;
	    }
		current = current->next;
	}
	return false;
}
