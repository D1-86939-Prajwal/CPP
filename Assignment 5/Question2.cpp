#include <iostream>
using namespace std;

class Product{

    private:
        int id, price;
        string title;

    public:
        Product(){
        }

        Product(int id, int price, string title){

            this->id = id;
            this->price = price;
            this->title = title;
        }

        int getPrice(){
            return price;
        }

        virtual void accept(){

            cout<<"Enter Product Details"<<endl;

            cout<<"ID       : ";
            cin>>id;
            cout<<"Price    : ";
            cin>>price;
            cout<<"Title    : ";
            cin>>title;            
        }

        virtual void display(){

            cout<<endl<<"ID       : "<< id <<endl;
            cout<<"Price    : "<< price <<endl;
            cout<<"Title    : "<< title <<endl;
        }

        virtual int calculateDiscount() = 0;

};

class Book : public Product{

    private:
        string author;

    public:

        Book(string author = "Prajwal"){

            this->author = author;
        }

        void accept(){

            cout<<"Enter Book Details"<<endl;
            cout<<"Author Name  : ";
            cin>>author;
            Product::accept();
        }

        void display(){

            cout<<"Books Details are"<<endl;
            cout<<"Author Name  : "<<author;
            Product::display();
        }

        int calculateDiscount(){
            
            int off = (Product::getPrice()*0.1) ;
            return off;
        }

};

class Tape : public Product{

    private:
        string artist;
    
    public:
        Tape(string artist="Taylor Swift"){

            this->artist = artist;
        }

        void accept(){

            cout<<"Enter Tape Details"<<endl;
            cout<<"Artist Name  : ";
            cin>>artist;
            Product::accept();
        }

        void display(){

            cout<<"Tape Details are"<<endl;
            cout<<"Artist Name  : "<<artist;
            Product::display();
        }

        int calculateDiscount(){

            int off = (Product::getPrice()*0.05) ;
            return off;
        }

};

int main(){

    // Book b;
    // b.accept();
    // b.display();
    
    Product *arr[3];
    int choice, finalbill = 0;

    for (int i = 0; i < 3; ++i) {

        cout << "Enter details for Product " << (i + 1) << endl;
        cout << "1. Book" << endl;
        cout << "2. Tape" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            arr[i] = new Book();
        } 

        else if (choice == 2) {

            arr[i] = new Tape();
        } 

        else {

            cout << "Invalid choice. Please choose either 1 (Book) or 2 (Tape)." << endl;
            --i; // Decrement i to redo this iteration
            continue;
        }

        arr[i]->accept();

        int priceAfterDiscount = arr[i]->getPrice() - arr[i]->calculateDiscount();

        finalbill += priceAfterDiscount;
    }
    

    cout<<endl;
    cout<<"--------------------------"<<endl;
    cout << "Final Bill Details:" << endl;
    cout<<"--------------------------";

    for (int i = 0; i < 3; ++i) {

        cout << "\nProduct " << (i + 1) << ":" << endl;
        arr[i]->display();
        cout << "Price after discount: " << arr[i]->getPrice() - arr[i]->calculateDiscount() << endl;
    }


    cout<<"=========================="<<endl;
    cout<<"Final Bill : "<<finalbill<<endl;
    cout<<"=========================="<<endl;

    for(int i=0; i<3; i++){

        delete arr[i];
    }

    return 0;
}
