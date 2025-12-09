#include <stdio.h>
#include <stdlib.h>

typedef struct Vehicle Vehicle;

typedef void (*AccelerateFunction)(Vehicle*);
typedef void (*BrakeFunction)(Vehicle*);

struct Vehicle {
    AccelerateFunction accelerate;
    BrakeFunction brake;
};//end

typedef struct {
    Vehicle base;  
} Car;//end

void carAccelerate(Vehicle* vehicle) {
    printf("Car: Pressing gas pedal...\n");
}//end carAccelerate

void carBrake(Vehicle* vehicle) {
    printf("Car: Applying brakes...\n");
}//end carBrake

void vehicleStartEngine(Vehicle* vehicle) {
    printf("Engine started!\n");
}//end vehicleStartEngine

Vehicle* carCreate() {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car) {
        car->base.accelerate = carAccelerate;
        car->base.brake = carBrake;
    }
    return (Vehicle*)car;
}//end carCreate

void vehicleDestroy(Vehicle* vehicle) {
    free(vehicle);
}//end vehicleDestroy

int main() {
    Vehicle* myCar = carCreate();
    
    vehicleStartEngine(myCar);
    myCar->accelerate(myCar);
    myCar->brake(myCar);
    
    vehicleDestroy(myCar);
    
    return 0;
}//end main