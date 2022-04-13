#include <iostream>
#include <string>
#include <cassert>
using namespace std;


class Point{
private:
	int m_x;
	int m_y;
public:
	Point(){
		cout << "Default Point constructor" << '\n';
	}
	Point(int x, int y) : m_x{x}, m_y{y}
	{
		cout << "Parameterized Point constructor" << '\n';
	}

	void set_point(int x, int y){
		m_x = x;
		m_y = y;
	}


	friend std::ostream& operator<<(std::ostream& out, const Point& point){
		out << point.m_x << " : " << point.m_y << "\n";
		return out;
	}
};



class Creature{
private:
	std::string m_name;
	Point m_location;
public:
	Creature(std::string name, const Point& location) : m_name{name}, m_location{location}
	{
		cout << "Creature constructor" << '\n';
	}

	void Move_to(int x, int y){
		m_location.set_point(x,y);
	}

	friend std::ostream& operator<<(std::ostream& out, const Creature& creature){
		out << creature.m_name << " is at location : " << creature.m_location << '\n';
		return out;
	}	

};


int main(){
	std::string name;
	cout << "Enter creature name : ";
	getline(std::cin, name);

	Creature creature{name, {10,13}};


	while(true){
		int x_location = 0, y_location = 0;
		cout << creature << '\n';

		cout << "Enter X location : ";
		cin >> x_location;
		assert(x_location >= 0);

		cout << "Enter Y location : ";
		cin >> y_location;
		assert(y_location >= 0);

		creature.Move_to(x_location, y_location);

		

	}
}