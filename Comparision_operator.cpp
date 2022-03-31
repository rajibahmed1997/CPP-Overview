#include <iostream>
using namespace std;



class Person{
private:
	string m_name;
	string m_email;
public:
	Person(string name="default name", string email="default email") : m_name{name}, m_email{email}
	{ }

	string get_name() const{return m_name;}
	string get_email() const{return m_email;}

	friend bool operator==(const Person& one, const Person& two);
	friend bool operator!=(const Person& one, const Person& two);

};


bool operator==(const Person& one, const Person& two){
	return(
		one.m_name == two.m_name &&
		one.m_email == two.m_email
	);
}
bool operator!=(const Person& one, const Person& two){
	return(
		one.m_name != two.m_name ||
		one.m_email != two.m_email
	);
}

int main(){
	Person one{"Rajib","rajib@gmail.com"};
	Person two{"Rajib","saidul@gmail.com"};

	if(one == two){
		cout << "They are equal" << '\n';
	}

	if(one != two){
		cout << "They are not" << '\n';
	}
	


}