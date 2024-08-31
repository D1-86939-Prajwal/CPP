#include<iostream>
using namespace std;

class Cylinder
{ private:
    double radius;
    double height;
    double volume;
    static double Pi;

public:
    Cylinder():radius(10), height(10){}

    Cylinder(double r , double h ) : radius(r), height(h){}  
    

    double getradius(){
        return radius;
    }


    double getheight(){
        return height;
    }

    void setradius(double r){
        radius  = r ;
    }

    void setheight(double h){
        height = h;
    }

    double calculateVolume(){
        return  Pi * radius * radius * height;
    
    }


};

double Cylinder::Pi = 3.14;

int main(){
    Cylinder c1;
    double radius , height ;
    cout<<"Enter the radius "<<endl;
    cin>>radius;
    cout<<"Enter the height "<<endl;
    cin>>height;
    c1.setradius(radius);
    c1.setheight(height);
    c1.getheight();
    c1.getradius();
    double volume = c1.calculateVolume();
    cout<<"The volume of the cylinder is "<<volume<<endl;
    return 0;
}