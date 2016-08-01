package cars;

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class FleetOfCars {
    public static void main(String[] args) throws FileNotFoundException {
        
        try {
            File file = new File("cars/carsDetails.txt");
            Scanner fileInput = new Scanner(file);
            int noOfCars = fileInput.nextInt();
            Cars[] fleetOfCars = new Cars[noOfCars];
            int type_of_car;
            float fuel_efficiency;
            float current_fuel_level;
            int iterator = 0;
            
            // Read car details from file
            while(fileInput.hasNextLine()) {
                type_of_car = fileInput.nextInt();
                fuel_efficiency = fileInput.nextFloat();
                current_fuel_level = fileInput.nextFloat();
                if(type_of_car == 1)
                	fleetOfCars[iterator] = new DieselCar(fuel_efficiency, current_fuel_level);
                else if(type_of_car == 2)
                	fleetOfCars[iterator] = new ElectricCar(fuel_efficiency, current_fuel_level);
                iterator++;
            }
        
            //Display car details
            for(iterator = 0; iterator < noOfCars; iterator++) {
                fleetOfCars[iterator].showDetails();
            }
        
            //Display car range details
            for(iterator = 0; iterator < noOfCars; iterator++) {
                System.out.println("Car " + (iterator + 1) + " Range: " + fleetOfCars[iterator].calculateRange() + " kms");
            }
        }
        catch (FileNotFoundException e) {
            throw new FileNotFoundException(e.toString());
        }
    }

}