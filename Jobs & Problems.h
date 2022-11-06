char Job_titles[5][50] = {"Service Technician", "Brake and Transmission Technician",
"Body Repair Technician", "Motor Repairer", "Tune-up Specialist"};
int Jobs_minimum_wage[5] = {3000, 3200, 2700, 3600, 2900};

class Part{
public:
    char *name = (char *) malloc(30 * sizeof(char));
    int price;

    Part(char *name, int price):name(name), price(price){}
};

// Part Engine("Engine",5500);
// Part Radiator("Radiator", 40);
// Part Battery("Battery", 70);

// Part Door("Door", 900);
// Part Wheel("Wheel", 100);
// Part Lights("Lights", 60);
// Part Windscreen("Windscreen", 100);

// Part Transmission("Transmission", 600);
// Part Brakes("Brakrs",400);

// Part FIS("Fuel Injection System", 450);
// Part Muffler("Muffler", 90);

// Part Motoroil("MotorOil", 6);

// Part Parts[12] = {Engine,Radiator,Battery,Door,Wheel,Lights,Windscreen,
// Transmission,Brakes,FIS,Muffler,Motoroil};