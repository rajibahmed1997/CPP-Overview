// NORMAL FUNCTION WAY


#include <iostream>
using namespace std;



class Number{
private:
	int m_min;
	int m_max;

public:
	Number(int min, int max) : m_min{min}, m_max{max}
	{ }

	int get_min() const {return m_min;}
	int get_max() const {return m_max;}

	// Number operator+(const Number& one, const Number& two);
	// Number operator+(const Number& one, int value);

};


Number operator+(const Number& one, const Number& two){
	int min{one.get_min() < two.get_min() ? one.get_min() : two.get_min()};
	int max{one.get_max() > two.get_max() ? one.get_max() : two.get_max()};
	return{min, max};
}


Number operator+(const Number& one, int value){
	int min{one.get_min() < value ? one.get_min() : value};
	int max{one.get_max() > value ? one.get_max() : value};
	return{min, max};
}


int main(){
	Number a{5,10};
	Number b{7,8};
	Number c{3,2};
	Number d{21,11};

	Number result{a + 30 + b + 20 + c + d + 10};
	cout << result.get_min() << "  :  " << result.get_max() << endl;


}

