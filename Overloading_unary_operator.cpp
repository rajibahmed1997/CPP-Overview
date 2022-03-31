#include <iostream>
using namespace std;



class Number{
private:
	int m_x;
	int m_y;
public:
	Number(int x = 0, int y = 0): m_x{x}, m_y{y}
	{ }

	int get_x() const{return m_x;}
	int get_y() const{return m_y;}

	Number operator-() const;
	bool operator!() const;
	friend std::ostream& operator<<(std::ostream& out, const Number& number);

};

Number Number :: operator-() const{
	return{-m_x, -m_y};
}

bool Number :: operator!() const{
	return(m_x == 0 && m_y == 0);
}

std::ostream& operator<<(std::ostream& out, const Number& number){
	out << "X : " << number.m_x << '\n';
	out << "Y : " << number.m_y << '\n';
	return out;
}


int main(){
	Number number{};
	if(!number){
		cout << "Number is same" << '\n';
	}else{
		cout << "They are not same" << '\n';
	}
}