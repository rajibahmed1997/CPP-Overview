#include <iostream>
using namespace std;



class Number{
private:
	int m_cents;
public:
	Number(int cents) : m_cents{cents}{}
	friend Number operator+(const Number& one, const Number& two);
	int get_cents() const {return m_cents;}
};


Number operator+(const Number& one, const Number& two){
	return(one.m_cents + two.m_cents);
}

int main(){
	Number one{10};
	Number two{20};

	Number result{one+two};
	cout << (one+two).get_cents();
}