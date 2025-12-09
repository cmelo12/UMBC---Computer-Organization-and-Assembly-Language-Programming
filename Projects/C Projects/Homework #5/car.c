#include <stdio.h>
#include <stdlib.h>

typedef struct Vehicle Vehicle;

typedef void (*AccelerateFunc)(Vehicle*);
typedef void (*BrakeFunc)(Vehicle*);

struct Vehicle {
    AccelerateFunc accelerate;
    BrakeFunc brake;
};

typedef struct {
    Vehicle base;  
} Car;

void car_accelerate(Vehicle* vehicle) {
    printf("Car: Pressing gas pedal...\n");
}

void car_brake(Vehicle* vehicle) {
    printf("Car: Applying brakes...\n");
}

void vehicle_start_engine(Vehicle* vehicle) {
    printf("Engine started!\n");
}

Vehicle* car_create() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car) {
        car->base.accelerate = car_accelerate;
        car->base.brake = car_brake;
    }
    return (Vehicle*)car;
}

void vehicle_destroy(Vehicle* vehicle) {
    free(vehicle);
}

int main() {
    Vehicle* myCar = car_create();
    
    vehicle_start_engine(myCar);
    myCar->accelerate(myCar);
    myCar->brake(myCar);
    
    vehicle_destroy(myCar);
    
    return 0;
}