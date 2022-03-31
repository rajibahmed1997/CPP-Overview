#include <iostream>
#include <cassert>
using namespace std;


class Matrix{
private:
    int m_data[4][4]{};
public:
    int& operator()(int row, int col);
};

int& Matrix :: operator()(int row, int col){
    assert(row >=0 && row <= 4);
    assert(col >=0 && col <= 4);
    return m_data[row][col];
}

int main(){
    Matrix arr{};
    arr(2,3) = 300;

    for(int i{0}; i<4; i++){
        for(int j{0}; j<4; j++){
            cout << arr(i,j) << "  ";
        }
        cout << '\n';
    }
}