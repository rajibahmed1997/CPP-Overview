// Member function way

#include <iostream>
using namespace std;


class Number{
	int m_id;
public:
	Number(int id):m_id{id}
	{ }

	// friend Number operator+(const Number& n, int value);
	Number operator+(int value);

	int get_id(){return m_id;}
};


// Number operator+(const Number& n, int value){
// 	return n.m_id + value;
// }

Number Number :: operator+(int value){
	return (m_id * value);
}


int main(){
	Number one{5};
	Number result{one + 10};
	cout << "Result is : " << result.get_id() << '\n';

	return 0;
}