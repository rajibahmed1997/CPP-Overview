#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

class Patient;


class Doctor{
private:
    std::string m_name;
    std::vector <std::reference_wrapper<const Patient>> m_patient{};


public:
    Doctor(const std::string& name) : m_name{name}
    {}

    void add_patient(Patient& patient);

    const std::string& get_name() const {return m_name; }
    friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

};



class Patient{
private:
    std::string m_name;
    std::vector<std::reference_wrapper<const Doctor>> m_doctor{};

    void add_doctor(const Doctor& doctor){
        m_doctor.push_back(doctor);
    }
public:
    Patient(const std::string& name) : m_name{name}
    {}

    // void add_doctor(Doctor& doctor);
    const std::string& get_name() const {return m_name; }
    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

    friend void Doctor::add_patient(Patient& patient);
};



void Doctor :: add_patient(Patient& patient){
    m_patient.push_back(patient);
    patient.add_doctor(*this);
}


// void Patient :: add_doctor(Doctor& doctor){
//     m_doctor.push_back(doctor);
//     doctor.add_patient(*this);
// }


std::ostream& operator<<(std::ostream& out, const Doctor& doctor){
    if(doctor.m_patient.empty()){
        out << doctor.m_name << ", has no patients" << '\n';
        return out;
    }
    out << doctor.m_name << ", has patients : ";
    for(const auto& patient : doctor.m_patient){
        out << patient.get().get_name() << "  ";
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient){
    if(patient.m_doctor.empty()){
        out << patient.m_name << ", not showing any doctor" << '\n';
        return out;
    }
    out << patient.m_name << ", showing doctors : ";
    for(const auto& doctor : patient.m_doctor){
        out << doctor.get().get_name() << " ";
    }

    return out;
}

int main(){
    Doctor d1{"Rajib"};
    Doctor d2{"Saidul"};
    Doctor d3{"Islam"};
    // cout << d1;

    Patient p1{"Rajib Ahmed_1"};
    Patient p2{"Rajib Ahmed_2"};
    Patient p3{"Rajib Ahmed_3"};
    Patient p4{"Rajib Ahmed_4"};

    d1.add_patient(p1);
    d1.add_patient(p3);
    d1.add_patient(p4);



    cout << d1 << '\n';
    cout << p3 << '\n';
}