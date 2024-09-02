#include <iostream>
#include <typeinfo>

using namespace std;


class Employee{
    private:
        int id;
        double salary;
    
    public:
        Employee() : id(1001), salary(15000) {}

        Employee(int id, double salary) : id(this->id = id), salary(this->salary = salary) {}

        void setId(int id) {this->id = id;}

        int getId() const {return id;}

        void setSalary(double salary) {this->salary = salary;}

        double getSalary() const {return salary;}

        virtual void accept() {

            cout<<"Enter ID         : ";
            cin>>id;
            cout<<"Enter Salary     : ";
            cin>>salary;
        }

        virtual void display() const {

            cout<<"ID           : "<<id<<endl;
            cout<<"Salary       : "<<salary<<endl;
        }

};


class Manager : virtual public Employee {
    private:
        double bonus;

    protected:
        void acceptManager(){

            cout<<"Enter Bonus      : ";
            cin>>bonus;
        }

        void displayManager() const {

            cout<<"Bonus        : "<<bonus<<endl;
        }

    public:
        Manager() : Employee(), bonus(50000) {}

        Manager(int id, double salary, double bonus) : Employee(id, salary) , bonus(this->bonus = bonus) {}

        void setBonus(double bonus) { this->bonus = bonus;}

        double getBonus() const { return bonus;}

        void accept(){

            Employee::accept();
            acceptManager();
        }

        void display(){

            Employee::display();
            displayManager();
        }

};


class Salesman : virtual public Employee {
    private:
        double commission;

    protected:
        void acceptSalesman() {

            cout<<"Enter Commission : ";
            cin>>commission;
        }

        void displaySalesman() const {

            cout<<"Commission   : "<<commission<<endl;
        }

    public:
        Salesman() : Employee(), commission(1000) {}

        Salesman(int id, double salary, double commission) : Employee(id, salary), commission(this->commission = commission) {}

        void setCommission(double commission) { this->commission = commission; }

        double getCommission() const { return commission; }

        void accept(){

            Employee::accept();
            acceptSalesman();
        }

        void display(){

            Employee::display();
            displaySalesman();
        }



};


class SalesManager : public Manager, public Salesman {
    public:
        SalesManager() : Manager(), Salesman() {}

        SalesManager(int id, double salary, double bonus, double commission) : Manager(id, salary, bonus), Salesman(id, salary, commission) {}

        void accept(){

            Manager::accept();
            Salesman::acceptSalesman();
        }

        void display(){

            Manager::display();
            Salesman::displaySalesman();
        }
};


void acceptEmployee(Employee* arr[], int &index){

    int opt;

    cout<<endl<<"Selete from Below"<<endl;
    cout<<"1. Accept Manager"<<endl;
    cout<<"2. Accept Salesman"<<endl;
    cout<<"3. Accept SalesManager"<<endl;

    cin>>opt;

    if(opt == 1){
        
        arr[index] = new Manager();                 
    }

    else if(opt == 2){

        arr[index] = new Salesman();
    }

    else if(opt == 3){

        arr[index] = new SalesManager();

    }

    else{

        cout<<"Invalid Option :("<<endl;
        return;
    }

    arr[index]->accept();
    index++;

}


void employeeCount(Employee* arr[], int index){

    int managerCount=0, salesmanCount=0, salesManagerCount=0;

    for(int i=0; i<index; i++){

        if( typeid(Manager).name() == typeid(*arr[i]).name() ){
            managerCount++;
        }

        else if(typeid(Salesman).name() == typeid(*arr[i]).name() ){
            salesmanCount++;
        }

        else if(typeid(SalesManager).name() == typeid(*arr[i]).name() ){
            salesManagerCount++;
        }
    }

    cout<<"\n======================================"<<endl;
    cout<<"Total Manager Count is       : "<<managerCount<<endl;
    cout<<"Total Salesman Count is      : "<<salesmanCount<<endl;
    cout<<"Total SalesManager Count is  : "<<salesManagerCount<<endl;
    cout<<"======================================="<<endl;

}


void displayAllManagers(Employee* arr[], int index){

    cout<<"==================================================\n";
    cout<<"====================MANAGERS======================\n"<<endl;

    for(int j=0; j<index; j++){

        Manager* mgr = dynamic_cast<Manager *> (arr[j]) ;       // Pay keen attention here

        if( mgr && typeid(*arr[j]).name() != typeid(SalesManager).name() ){

            mgr->display();
            cout<<endl;
        }
    }

    cout<<"==================================================\n";
    cout<<"==================================================\n"<<endl;

}


void displayAllSalesman(Employee* arr[], int index){

    cout<<"==================================================\n";
    cout<<"====================SALESMANS=====================\n"<<endl;

    for(int k=0; k<index; k++){

        Salesman* sals = dynamic_cast<Salesman*> (arr[k]);          //IMPORTANT

        if( sals && typeid(*arr[k]).name() != typeid(SalesManager).name() ){

            sals->display();
            cout<<endl;
        }
    }

    cout<<"==================================================\n";
    cout<<"==================================================\n"<<endl;
    
}


void displayAllSalesManager(Employee* arr[], int index){

    cout<<"==================================================\n";
    cout<<"=================SALESMANAGERS===================\n"<<endl;

    for(int l=0; l<index; l++){

        SalesManager* smagr =dynamic_cast<SalesManager*> (arr[l]);      //IMPORTANT

        if( smagr ){

            smagr->display();
            cout<<endl;
        }
    }

    cout<<"==================================================\n";
    cout<<"==================================================\n"<<endl;

}


int main(){

    int choice;
    int index = 0;
    
    Employee *arr[10];
    
    
    while(true){

        cout<<"0. EXIT"<<endl;
        cout<<"1. Accept Employees"<<endl;
        cout<<"2. Display Count of All Employees with respect to Designation"<<endl;
        cout<<"3. Display All Managers"<<endl;
        cout<<"4. Display All Salesman"<<endl;
        cout<<"5. Display All SalesManager"<<endl;

        cin>>choice;

        switch(choice){

            case 0:

                return 0;

            case 1:
                
                if(index >= 10){
                    
                    cout<<"\n================================"<<endl;
                    cout<<"Cannot add more Employees"<<endl;
                    cout<<"=================================\n"<<endl;

                    break;

                }
                acceptEmployee(arr, index);

                break;
            
            case 2: 

                employeeCount(arr, index);

                break;
            
            case 3:

                displayAllManagers(arr, index);

                break;
            
            case 4:

                displayAllSalesman(arr, index);

                break;

            case 5:

                displayAllSalesManager(arr, index);

                break;

            default: 
                
                cout<<"Invalid Choice"<<endl;
        }

    }

    return 0;
}

