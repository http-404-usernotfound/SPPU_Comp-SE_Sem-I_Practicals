#include <iostream>
using namespace std;

class Person{
	string *name, *bloodGrp, *address;
	int rollNo, dob;
	long int ipn, drNo, contactNo;
	float height;

public:
	static int count;

	Person(){
		name = new string, bloodGrp = new string, address = new string;
		ipn = -1, drNo = -1, contactNo = -1, height = -1, rollNo = -1, dob = -1;
		count++;
		display();
	}

	Person(Person* p){
		name = new string(*(p->name)), bloodGrp = new string(*(p->bloodGrp)), address = new string(*(p->address));
		ipn = p->ipn, drNo = p->drNo, contactNo = p->contactNo, height = p->height, rollNo = p->rollNo, dob = p->dob;
		count++;
		display();
	}

	Person(string n, string b, string a, long int ipn, long int drNo, long int contactNo, float height, int rollNo, int dob){
		name = new string, bloodGrp = new string, address = new string;
		this->ipn = ipn, this->drNo = drNo, this->contactNo = contactNo, this->height = height,
				this->rollNo = rollNo, this->dob = dob;
		*name = n, *bloodGrp = b, *address = a;
		count++;
		display();
	}

	void displayRow(){
		cout.setf(ios::left, ios::adjustfield);
		cout.width(20); cout<<*name;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(13); cout<<*bloodGrp;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(15); cout<<*address;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(10); cout<<ipn;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(22); cout<<drNo;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(18); cout<<contactNo;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(10); cout<<height;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(12); cout<<rollNo;
		cout.setf(ios::left, ios::adjustfield);
		cout.width(13); cout<<dob<<endl;

	}

	void display(){
		cout<<"Name: "<<*name;
		cout<<", Blood Group: "<<*bloodGrp;
		cout<<", Address: "<<*address;
		cout<<", IPN: "<<ipn;
		cout<<", Driving license number: "<<drNo;
		cout<<", Contact Number: "<<contactNo;
		cout<<", Height: "<<height;
		cout<<", Roll Number: "<<rollNo;
		cout<<", DOB: "<<dob<<endl;
	}

	static void displayCount(){
		cout<<"Number of entries: "<<count<<endl;
	}

	Person* compare(Person* p){
		if(p->height > height) return p;
		else return this;
	}
	~Person(){
		cout<<"Destructor called...";
		count--;
	}
	friend class Age;
};

class Age{
	int age, currentYear = 2023;
public:
	int calculateAge(Person* p){
		age = currentYear - p->dob;
		return age;
	}

};

int Person::count = 0;

int main() {
	string *name, *bloodGrp, *address;
	int rollNo, dob;
	long int ipn, drNo, contactNo;
	float height;

	int choice;
	Person* persons[10];

	while (true){
		cout<<endl<<endl;
		cout<<"(1) - Default constructor.\n"
			  "(2) - Parameterised constructor.\n"
			  "(3) - Copy constructor.\n"
			  "(4) - No. of entries.\n"
			  "(5) - Calculate age.\n"
			  "(6) - Taller student.\n"
			  "(7) - Display Students.\n"
			  "(8) - Exit.\n";
		cout<<"Enter your choice >> ";cin>>choice;
		cout<<endl;

		switch(choice){
			case 1:{
				persons[Person::count-1] = new Person;
				break;
			}

			case 2:{
				name = new string; bloodGrp = new string; address = new string;
				cout<<"\nEnter details of student:\n";
				cout<<"Enter Name: "; cin>>*name;
				cout<<"Enter Blood Group: "; cin>>*bloodGrp;
				cout<<"Enter Address: "; cin>>*address;
				cout<<"Enter IPN: "; cin>>ipn;
				cout<<"Enter Driving license number: "; cin>>drNo;
				cout<<"Enter Contact Number: "; cin>>contactNo;
				cout<<"Enter Height: "; cin>>height;
				cout<<"Enter Roll Number: "; cin>>rollNo;
				cout<<"Enter Year of Birth: "; cin>>dob;
				cout<<endl;

				persons[Person::count-1] = new Person (*name, *bloodGrp, *address, ipn, drNo, contactNo, height, rollNo, dob);

				break;
			}

			case 3:
				cout<<"Which student do you want to copy?\n";
				int i;
				for(i = 0; i<Person::count; i++){ cout<<"("<<i+1<<") - "; persons[i]->display();}
				cout<<"\nEnter choice: ";cin>>i;
				persons[Person::count-1] = new Person (persons[i-1]);

				break;

			case 4:
				Person::displayCount();
				break;
			case 5:{
				int i;
				cout<<"Calculate age of which student?\n";
				for(i = 0; i<Person::count; i++){ cout<<"("<<i+1<<") - "; persons[i]->display();}
				cout<<"\nEnter choice: ";cin>>i;
				Age a;
				cout<<"\nAge is: "<<a.calculateAge(persons[i-1])<<endl;
				break;
			}
			case 6:
				Person *temp;
				temp = persons[0];
				for(int i = 0; i<Person::count-1; i++) temp = temp->compare(persons[i+1]);
				cout<<"\nTallest student is: "; temp->display();
				break;
			case 7:
				cout<<"###############################################################################################################################################\n";
				cout<<"Sr No.    ";
				cout.setf(ios::left, ios::adjustfield);
				cout.width(20); cout<<"Name";
				cout<<"Blood Grp    ";
				cout.setf(ios::left, ios::adjustfield);
				cout.width(15); cout<<"Address";
				cout.setf(ios::left, ios::adjustfield);
				cout.width(10); cout<<"IPN";
				cout<<"Driving license No.   ";
				cout<<"Contact Number    ";
				cout<<"Height    ";
				cout<<"Roll No.    ";
				cout<<"Year of Birth\n";
				cout<<"###############################################################################################################################################\n";
				for(int i = 0; i<Person::count; i++){ cout.width(10);cout<<i+1; persons[i]->displayRow();}
				break;
			case 8:
				cout<<"Exiting...";
				return 0;
		}

	}
}
