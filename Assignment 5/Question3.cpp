#include <iostream>
using namespace std;

class Employee{
    private:
        int id;
        double salary;
    
    public:
        Employee(){

            id = 0;
            salary = 0.0;
        }

        Employee(int id, double salary){

            this->id = id;
            this->salary = salary;
        }

        void setId(int id){

            this->id = id;
        }

        void setSalary(double salary){

            this->salary = salary;
        }

        double getSalary() const{

            return salary;
        }

        virtual void accept(){

            cout<<"Enter Id         : ";
            cin>>id;
            cout<<"Enter Salary     : ";
            cin>>salary;
        }

        virtual void display() const{
            
            cout<<"Id               : "<<id<<endl;
            cout<<"Salary           : "<<salary<<endl;
        }
};


class Manager : virtual public Employee{

    private:
        double bonus;
    
    protected:
        void acceptManager(){

            cout<<"Enter bonus      : ";
            cin>>bonus;
        }

        void displayManager() const{

            cout<<"Bonus            : "<<bonus<<endl;
        }

    public:
        Manager() : Employee(), bonus(0.0) {}

        Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(this->bonus) {}

        void setBonus(double bonus) {this->bonus = bonus;}

        double getBonus() const {return bonus;}


        void accept() override {

            Employee::accept();
            acceptManager();
        }

        void display() const override {

            Employee::display();
            displayManager();
        }

};


class Salesman : virtual public Employee{
    private:
        double commission;
    
    protected:
        void acceptSalesman(){

            cout<<"Enter Commission : ";
            cin>>commission;
        }

        void displaySalesman() const{

            cout<<"Commission       : "<<commission<<endl;
        }

    public:
        Salesman() : Employee(), commission(0.0) {}

        Salesman(int id, double salary, double commission) : Employee(id, salary), commission(this->commission) {}

        void setCommission(double commission) {this->commission = commission;}

        double getCommission() {return commission;}

        void accept() override {

            Employee::accept();
            acceptSalesman();
        }

        void display() const override {

            Employee::display();
            displaySalesman();
        }

};


class SalesManager : public Manager, public Salesman {

    public:
        SalesManager() : Employee(), Manager(), Salesman() {}

        SalesManager(int id, double salary, double bonus, double commission) : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

        void accept() override{
            
            Manager::accept();
            Salesman::acceptSalesman();
        }

        void display() const override{

            Manager::display();
            Salesman::displaySalesman();
        }

};


int main(){

    SalesManager sm;

    cout<<"\nEnter Employee Details "<<endl;
    sm.accept();

    cout<<"\nEmployee Details are "<<endl;
    sm.display();
    
    return 0;

}

