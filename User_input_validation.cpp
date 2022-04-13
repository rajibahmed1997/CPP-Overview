#include <iostream>
#include <limits>





int get_number();
char get_operator();
void ignore_line();


void Calculation(int num_1, char op, int num_2){
    switch(op){
        case '+':
            std::cout << "Addition : " << (num_1 + num_2) << '\n';
            break;
        case '-':
            std::cout << "Subtraction : " << (num_1 - num_2) << '\n';
            break;
        case '*':
            std::cout << "Multiplication : " << (num_1 * num_2) << '\n';
            break;
        case '/':
            std::cout << "Division : " << (num_1 / num_2) << '\n';
            break;

        default:
            std::cerr << "Something went wrong" << '\n';
            break;
        
    }
}


int main(){
    int num_1{get_number()};
    char op{get_operator()};
    int num_2{get_number()};

    Calculation(num_1, op, num_2);

}

int get_number(){
    int num;
    static bool is_first_call = true;

    while(true){

        if(is_first_call){
            std::cout << "Enter first number : ";
            is_first_call = false;
        }else{
            std::cout << "Enter second number : ";
        }

        
        std::cin >> num;
        
        if(std::cin.fail()){
            std::cin.clear();
            ignore_line();
            std::cerr << "Please, try again" << "\n\n";
        }else{
            ignore_line();
            return num;
        }
    }

}

char get_operator(){
    char op;
    while(true){
        std::cout << "Enter operator (+,-,*,/) : ";
        std::cin >> op;
        ignore_line();

        switch(op){
            case '+':
            case '-':
            case '*':
            case '/':
                return op;
            default:
                std::cerr << "Invalid, please try again \n\n";
        }
    }
}

void ignore_line(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}






