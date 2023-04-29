#include "car.hpp"


Car::Car(){

}

void Car::print(string label){
    cout << "\nCar Object: " << label;
    cout << "\nx: " << x;
    cout << "\ny: " << y;
}
