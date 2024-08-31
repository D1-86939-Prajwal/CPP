#include<iostream>
using namespace std;

class Date{
    private:
    int day, month,year;

    public:
    Date(){
        day = 11;
        month = 22;
        year = 2000;
    }

    Date(int day , int month , int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getday(){
        return day;
    }

    int getmonth(){
        return month;
    }

    int getyear(){
        return year;
    }

    void setday(int day){
        this->day = day;
    }

    void setmonth(int month){
        this->month = month;
    }

    void setyear(int year){
        this->year=year;
    }
    
    void acceptdate(){
        cout<<"Enter the day : "<<endl;
        cin>>day;
        cout<<"Enter the month :"<<endl;
        cin>>month;
        cout<<"Enter the year :"<<endl;
        cin>>year;
    }

    void displaydate(){
        cout<<"The Birthdate is : "<<day<<"/"<<month<<"/"<<year<<endl;
    }


};
    class Person{
        private:
        string name ,address;
        Date birthdate;

        public:
        Person(){
            name = "Raj";
            address = "Pune";
        }

        Person(string name , string address){
            this->name = name ;
            this->address = address;
        }

        string getname(){
            return name;
        }

        string getaddress(){
            return address;
        }

        void setname(string name){
            this->name = name;
        }

        void setaddress(string address){
            this->address = address;
        }

        void acceptPerson(){
            cout<<"Enter the name :"<<endl;
            cin>>name;
            cout<<"Enter the address :"<<endl;
            cin>>address;
            cout<<"Enter the birthdate :"<<endl;
            birthdate.acceptdate();
        }

        void displayPerson(){
            cout<<"Name      :"<<name<<endl;
            cout<<"Address   :"<<address<<endl;
            cout<<"Birthdate :"<<endl;
            birthdate.displaydate();
        }
    };

    class Employee :public Person{
        private:
        int empid, salary;
        string department;
        Date joiningDate;


        public:
        Employee(){
            empid = 44;
            salary = 33000;
            department = "Sunbeam";
        }

        Employee(int empid , int salary , string department){
            this->empid = empid;
            this->salary = salary;
            this->department = department;
        }


        int getempid(){
            return empid;
        }

        int getsalary(){
            return salary;
        }

        string getdepartment(){
            return department;
        }

        void setempid(int empid){
            this->empid = empid;
        }
        void setsalary(int salary){
            this->salary = salary;
        }

        void setdepartment(string department){
            this->department = department;
        }

        void acceptEmployee(){
            cout<<"Enter Empid :"<<endl;
            cin>>empid;
            cout<<"Enter Salary :"<<endl;
            cin>>salary;
            cout<<"Enter Department :"<<endl;
            cin>>department;
            cout<<"Enter Joining Date :"<<endl;
            joiningDate.acceptdate();
        }

        void displayEmployee(){
            cout<<"Empid        :"<<empid<<endl;
            cout<<"Salary       :"<<salary<<endl;
            cout<<"Department   :"<<department<<endl;
            cout<<"Joining date :"<<endl;
            joiningDate.displaydate();
        }

};

int main(){

    Person p;
    p.acceptPerson();
    p.displayPerson();


    Employee e;
    e.acceptEmployee();
    e.displayEmployee();

    return 0;
}

