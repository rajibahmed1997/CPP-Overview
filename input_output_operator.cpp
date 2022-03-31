#include <iostream>
using namespace std;


class Number{
	int m_min;
	int m_max;

public:
	Number(int min = 0, int max = 0) : m_min{min}, m_max{max}
	{ }

	int get_min() const {return m_min;}
	int get_max() const {return m_max;}

	friend std::ostream& operator<<(std::ostream& out, const Number& n);
	friend std::istream& operator>>(std::istream& in, Number& n);


};


std::istream& operator>>(std::istream& in, Number& n){
	in >> n.m_min;
	in >> n.m_max;

	return in;
}


std::ostream& operator<<(std::ostream& out, const Number& n){
	out << n.m_min << " : " << n.m_max << '\n';
	return out;
}


int main(){

	cout << "Please enter min and max value : ";
	Number number{};
	std::cin >> number;

	cout << "Enter number : " << number << '\n';

}