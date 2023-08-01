#include<iostream>
#include<string>
using namespace std;



int countClient = 0;
void addclient();
void displayclient();
void deleteclient();
void updateClient();



//client arr[100];
struct client
{
	int id;
	string name;
	string time;
	
};
client arr[100];
int main()

{
	int m=1;
	while (m != 0) 
	{
		cout << "					Welcome to the management system" << endl;
		cout << "						1) Add new client" << endl;
		cout << "						2) Update new client" << endl;
		cout << "						3) Delete client" << endl;
		cout << "						4) Show all clients attended the cafe " << endl;
		cout << "					please choose one from above choices " << endl;
		cin >> m;
		if (m == 1)
		{
			cout << "					Welcome User" << endl;
			addclient();
		}
		else if (m == 2) {
			cout << "					Welcome User" << endl;
			updateClient();
		}
		else if (m == 4)
		{
			cout << "					Welcome User" << endl;
			displayclient();

		}
		else if (m == 3)
		{
			cout << "					Welcome User" << endl;
			deleteclient();
		}
	}

	

}
int idExist(int id) {
	for (int i = 0; i < countClient; i++)
	{
		if (arr[i].id == id)
			return i;
	}
	return -1; // the client does not exist
}
void addclient()
{   
	int s = 1;
	while (s != 0)
	{
		client c;
		int id;
		string name;
		string time;
		cout << "please enter id ";

		cin >> id;
		if (idExist(id) != -1) {
			cout << "Error::There is a client with that id: " << endl;
		}
		else {
			cout << "please enter the time the client entered the Cafe:  ";
			cin >> time;
			cout << "please enter the client name:  ";
			cin >> name;
			client c1;
			c1.id = id;
			c1.name = name;
			c1.time = time;
			arr[countClient] = c1;
			countClient++;
		}
		cout << "To add other client, press 1 else to exit press 0. " << endl;
		cout << "Your choose : ";
		cin >> s;

	}

}
void displayclient()
{
	if (countClient == 0) {
		cout << "There is no clients yet" << endl;
	}
	cout << "The summary of clients visited the cafe today :" << endl;
	for (int i = 0; i < countClient; i++)
	{
		cout << i+1 << ") "<<"At "<< arr[i].time <<" "<< arr[i].name <<" entered the cafe. "<<endl;

	}
}

void shiftElements(int id) {
	for (int i = 0; i < countClient; i++) {
		if (arr[i].id == id) {
			for (int j = i; j < countClient-1; j++) {
				arr[j] = arr[j+1];
			}
		}
	}
	countClient--;
}
void deleteclient()
{
	int s = 1;
	while (s != 0)
	{
		int id;
		cout << "please enter the id of the client to delete " << endl;
		cin >> id;
		if (idExist(id) == -1) {
			cout << "Error : There is no client with this id" << endl;
		}
		else
		{
			shiftElements(id);
			cout << " deleted successfuly " << endl;
			
		}
		cout << "to delete other client, press 1 else to exit press 0 " << endl;
		cin >> s;

		

	}
}
void updateClient()
{
	int s = 1;
	while (s != 0)
	{
		int id;
		cout << "please enter the id of the client you want to update: " << endl;
		cin >> id;
		int idx = idExist(id);
		if (idx == -1) {
			cout << "Error : There is no client with this id" << endl;
		}
		else
		{
			cout << "please enter the new time of the client ";
			cin >> arr[idx].time;
			cout << "please enter the new name of the client ";
			cin >> arr[idx].name;
			cout << endl;
			
		}
		cout << "to update other client press 1 else to exit press 0 " << endl;
		cin >> s;



	}
}

