#include <iostream>
using namespace std;


class Number{
private:
	int m_id;
public:
	Number(int id = 0) : m_id{id}
	{ }

	Number& operator++(); // Pre increment and decrement don't take any paramerter and use references
	Number& operator--();

	Number operator++(int); // Post increment and decrement takes parameter and don't use references
	Number operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const Number& number);
	friend std::istream& operator>>(std::istream& in, Number& number);

};


// Pre increment
Number& Number :: operator++(){
	if(m_id == 9){
		m_id = 0;
	}else{
		++m_id;
	}
	return *this;
}
Number& Number :: operator--(){
	if(m_id == 0){
		m_id = 9;
	}else{
		--m_id;
	}
	return *this;
}


// Post increment
Number Number :: operator++(int){
	Number temp{*this};
	++(*this);
	return temp;
}
Number Number :: operator--(int){
	Number temp{*this};
	--(*this);
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Number& number){
	out << number.m_id << " ";
	return out;
}

std::istream& operator>>(std::istream& in, Number& number){
	in >> number.m_id;
	return in;
}


int main(){
	cout << "Enter a number : ";
	Number digit;
	std::cin >> digit;
	
	cout << digit;
	cout << digit--;
	cout << digit;
	cout << digit++;
	cout << digit--;
	cout << digit;
	cout << ++digit;
	cout << ++digit;
	cout << --digit;
	cout << digit;
}

// 5 5 4 4 5 4 5 6 5 5