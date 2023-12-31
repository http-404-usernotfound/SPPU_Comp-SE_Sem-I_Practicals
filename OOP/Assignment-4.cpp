#include <iostream>
#include <fstream>

using namespace std;

class Student{
public:
	string name, phoneNo;

	Student(){
		name = "";
		phoneNo = "";
	}

	void display(){
		cout<<"\nName: "<<name;
		cout<<"\nPhone Number: "<<phoneNo<<endl;
	}

	void accept(){
		cout<<"\nEnter name: "; cin>> name;
		cout<<"Enter phone number: "; cin>> phoneNo;
	}

};

int main() {
	int size = 0;

	cout<<"Enter number of students: "; cin>> size;
	Student *stds = new Student[size];
	cout<<"Enter the data:\n";
	for(int i = 0; i < size; i++)
		stds[i].accept();

	fstream f;
	int input;
	do{
		cout<<"\n(1) - Store.\n"
			  "(2) - Display.\n"
			  "(3) - Search.\n"
			  "(4) - Modify.\n"
			  "(5) - Exit.\n\n"
			  "Enter your choice: "; cin>> input;

		switch(input){
		case 1:
			f.open("st_data.txt", ios::out);
			for(int i = 0; i< size; i++)
				f.write((char*)&stds[i], sizeof(stds[i]));
			f.close();
			break;

		case 2:{
			Student *s = new Student;
			f.open("st_data.txt", ios::in);
			for(int i = 0; i < size; i++){
				f.read((char*)s, sizeof(stds[i]));
				s->display();
			}
			f.close();
			break;
		}

		case 4:{
			char pOld[10], pNew[10];
			int k = 1;
			cout<<"Enter old/current phone number: "; cin>> pOld;
			f.open("st_data.txt", ios::in);
			Student *s = new Student;
			for(int i = 0; i< size; i++){
				f.read((char*)s, sizeof(stds[i]));
				if(s->phoneNo == pOld){
					cout<<"Enter new phone number: "; cin>>pNew;
					s->phoneNo = pNew;
					stds[i].phoneNo = pNew;
					cout<<"Phone number updated :)";
					k = 0;
					break;
				}
			}
			f.close();
			if(k) cout<<"Phone number not found :(";
			break;
		}

		case 5:
			cout<<"Exiting...";
			return 0;


		case 3:{
			int choice;
			cout<<"1. By Name		2. By Phone Number: "; cin>>choice;
			switch(choice){
			case 1:{
				char n[20];
				Student *s = new Student;
				int j = 1;
				f.open("st_data.txt", ios::in);
				cout<<"Enter the name: "; cin>>n;
				for(int i = 0; i < size; i++){
					f.read((char*)s, sizeof(stds[i]));
					if (s->name == n){
						cout<<"Student found :)\n";
						s->display();
						j = 0;
						break;
					}
				}
				f.close();
				if(j) cout<<"Student not found :(\n";
				break;
			}

			case 2:{
				char p[10];
				int j = 1;
				Student *s = new Student;
				f.open("st_data.txt", ios::in);
				cout<<"Enter Phone number: "; cin>> p;
				for(int i = 0; i < size; i++){
					f.read((char*)s, sizeof(stds[i]));
					if (s->phoneNo == p){
						j = 0;
						cout<<"Student found :)\n";
						s->display();
						break;
					}
				}
				f.close();
				if(j) cout<<"Student not found :(\n";
			}
			}
		}
		}
	}while(true);
}
