        Part Engine("Engine",5500);
        Part Radiator("Radiator", 40);
        Part Battery("Battery", 70);

        Part f[2] = {Battery, Radiator};
        Part Door("Door", 900);
        Part Wheel("Wheel", 100);
        Part Lights("Lights", 60);
        Part Windscreen("Windscreen", 100);

        Part Transmission("Transmission", 600);
        Part Brakes("Brakrs",400);

        Part FIS("Fuel Injection System", 450);
        Part Muffler("Muffler", 90);

        Part Motoroil("MotorOil", 6);


        Problem Checkup("checkup","Service Technician", 15);
        Problem Bad_Engine("Bad Engine", "Motor Repairer", 100);
        Problem Dead_Battery("Dead Battery", "Motor Repairer", 70);


        Problem Change_Oil("Change motor oil", "Service Technician", 15, Motoroil);
        Problem Destroyed_Engine("Destroyed Enginee", "Motor Repairer", 120, Engine);
        Problem Destroyed_Battery("Destroyed Battery", "Motor Repairer", 80, Battery);
        Problem Bad_Windscreen("Bad Windscreen", "Body Repair Technician", 50, Windscreen);
        Problem Bad_Headlights("Bad Headlights", "Body Repair Technician", 40, Lights);
        Problem Bad_Wheels("Bad Wheels", "Body Repair Technician", 40, Wheel);
        Problem Bad_TS_Unit("Bad Transmission Unit", "Brake and Transmission Technician", 70,
        Transmission);
        Problem Bad_Brakse("Bad Brakes", "Brake and Transmission Technician", 40, Brakes);
        Problem Bad_FIS("Bad Fuel Injection System", "Tune-up Specialist", 100, FIS);
        Problem Bad_Muffler("Bad Muffler", "Tune-up Specialist", 90, Muffler);