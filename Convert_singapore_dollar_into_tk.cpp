#include <iostream>
#include <limits> // for numeric limits
using namespace std;


class bd_currency{
    private:
        int m_tk;
    public:
        bd_currency(int tk) : m_tk{tk}
        { }

        operator int() const {return m_tk; }
        // int get_tk() const {return m_tk; }
        void set_tk(int tk){
            m_tk = tk;
        } 

};


class Dollar{
    private:
        int m_dollar;
    public:
        Dollar(int dollar) : m_dollar{dollar}
        { }

        operator bd_currency() const {return m_dollar * 63; }

};

void ignore_line(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



int get_int_amount(){
    int dollar_amount;
    while(true){
        // Here, I'm not handling bugs for double/float user input
        cout << "Enter dollar amount you want to convert into tk : ";
        cin >> dollar_amount;

        if(std::cin.fail()){
            std::cin.clear();
            ignore_line();
            std::cerr << "Oops! Something went wrong. Please, try again" << endl;
        }else{
            ignore_line();
            return dollar_amount;
        }
    }
}


void display(bd_currency amount){
    cout << "BD Amount : " << amount << endl;
}

int main(){
    
    Dollar dollar{get_int_amount()};
    display(dollar);
}