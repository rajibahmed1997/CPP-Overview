#include <iostream>
#include <string>
using namespace std;



class Person{
private:
	int m_id;
	std::string m_name;

public:
	Person(int id = 0, const std::string& name="Default Name") : m_id{id},m_name{name}
	{ }

	friend std::ostream& operator<<(std::ostream& out, const Person& person);
	friend std::istream& operator>>(std::istream& in, Person& person);
	friend Person operator+(const Person& person1, const Person& person2);

	int get_id() const {return m_id;}
	std::string get_name() const {return m_name;}

};


Person operator+(const Person& person1, const Person& person2){
	int min_id{person1.m_id < person2.m_id ? person1.m_id : person2.m_id};
	int max_id{person1.m_id > person2.m_id ? person1.m_id : person2.m_id};
	return (min_id);
}

std::ostream& operator<<(std::ostream& out, const Person& person){
	out << "ID : " << person.m_id << "\n";
	out << "Name : " << person.m_name << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, Person& person){
	in >> person.m_id;
	in >> person.m_name;
	return in;
}


int main(){
	// cout << "Enter ID & Name : ";
	Person rajib{201,"soneone"};
	// std::cin >> rajib;

	Person one{101, "Saidul"};
	Person two{103, "Islam"};
	Person three{105, "Rajib"};

	Person result{rajib + one + two + three};


	cout << rajib.get_id();
}