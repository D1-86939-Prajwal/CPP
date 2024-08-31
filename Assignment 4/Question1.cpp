#include<iostream>
using namespace std;


class Date{
    private:
    int day;
    int month;
    int year;

    public:
    Date(){
         day = 11;
         month = 11;
         year = 2000;
    }

    Date(int day , int month ,int year){
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
            this->year = year;
        }

    void acceptdate(){
        cout<<"Enter the day"<<endl;
        cin>>day;

        cout<<"Enter the month"<<endl;
        cin>>month;

        cout<<"Enter the year"<<endl;
        cin>>year;
    }


    void displaydate(){
        cout<<"Birthdate is : "<<day<<"/"<<month<<"/"<<year<<endl;
    }

};


class Person{
    private:
    string name;
    string address;
    Date birthdate;


    public:
    Person(){
        name = "Raj";
        address = "Hinjewadi";
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

    void acceptperson(){
        cout<<"Enter the name"<<endl;
        cin>>name;
        cout<<"Enter the address"<<endl;
        cin>>address;
        cout<<"Enter the date"<<endl;
        birthdate.acceptdate();

    }

    void dispalaydate(){
        cout<<"Name is : "<<name<<endl;
        cout<<"Address is : "<<address<<endl;
        birthdate.displaydate();
    }
};


int main(){
    Person p1;

    p1.acceptperson();
    p1.dispalaydate();
    return 0;
}



