#include <iostream>
using namespace std;

class publication{
protected:
	string title;
	float price;

public:
	publication(){
		title = "";
		price = 0.0;
	}
	publication(string title, float price){
		this->title = title;
		this->price = price;
	}

	void set_data(){
		cout<<"Enter title: "; cin>>title;
		cout<<"Enter price: "; cin>>price;
	}

	string get_tile(){return title;}
	float get_price(){return price;}

	void display(){
		cout<<"Title: "<<title<<endl;
		cout<<"Price: "<<price<<endl;
	}
};

class book: public publication{
	int pages;

public:
	book(){
		title = "";
		price = 0.0;
		pages = 0;
	}
	book(string title, float price, int pages){
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void set_data(){
		publication::set_data();
		cout<<"Enter pages: ";
		try{
			cin>>pages;
		if(pages == 0) throw pages;
		}
		catch(int){
			cout<<"Pages cannot be zero";
		}
	}

	int get_pages(){
		return pages;
	}

	void display(){
			publication::display();
			cout<<"No. of Pages: "<<pages<<endl;
		}

};

class CD:public publication{
	float duration;

public:
	CD(){
		title = "";
		price = 0.0;
		duration = 0.0;
	}

	CD(string title, float price,float duration){
		this->title = title;
		this->price = price;
		this->duration = duration;
	}

	void set_data(){
		publication::set_data();
		cout<<"Enter Duration: ";
		try{
			cin>>duration;
			if (duration == 0) throw duration;
		}

		catch(float){
			cout<<"Duration cannot be zero";
		}
	}

	float get_duration(){
		return duration;
	}

	void display(){
		publication::display();
		cout<<"Duration: "<<duration<<endl;

	}
};

int main() {
	book b;
	book b2("C++", 230, 300);

	cout<<"Details of b2:\n";
	b2.display();

	CD C1;
	CD C2("C++", 100, 120.5);

	cout<<"\nDetails of C2:\n";
	C2.display();

	cout<<"\nEnter details of b:\n";
	b.set_data();

	cout<<"\nEnter details of C1:\n";
	C1.set_data();

	cout<<"\nDetails of b:\n";
	b.display();

	cout<<"\nDetails of C1:\n";
	C1.display();

	return 0;
}
