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

int main() {
	
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
	if(!current -> next){
	  break;
	current = current->next;
	}

	current->next = new Username(username, password);
	return true;
}
