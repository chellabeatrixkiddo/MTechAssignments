package cars;

public abstract class Cars {
    float fuel_efficiency;
    float current_fuel_level;
    
     Cars(float fuel_efficiency, float current_fuel_level) {
        this.fuel_efficiency = fuel_efficiency;
        this.current_fuel_level = current_fuel_level;
    }
    
    abstract void showDetails();
    
    abstract float calculateRange();
   
}
class DieselCar extends Cars {
	DieselCar(float fuel_efficiency, float current_fuel_level) {
		super(fuel_efficiency, current_fuel_level);
	}
	float calculateRange() {
		float range = fuel_efficiency * current_fuel_level;
        return range;
	}
	 void showDetails() {
        System.out.println("Car Details:");
        System.out.println("-------------");
        System.out.println("Fuel Efficiency: " + this.fuel_efficiency + "km/l");
        System.out.println("Current Fuel Level: " + this.current_fuel_level + "l");
        System.out.println();
    }
}
class ElectricCar extends Cars {
	ElectricCar(float fuel_efficiency, float current_fuel_level) {
		super(fuel_efficiency, current_fuel_level);
	}
	float calculateRange() {
		float range = (current_fuel_level / fuel_efficiency) * 1000;
        return range;
	}
	 void showDetails() {
        System.out.println("Car Details:");
        System.out.println("-------------");
        System.out.println("Fuel Efficiency: " + this.fuel_efficiency + "Wh/km");
        System.out.println("Current Fuel Level: " + this.current_fuel_level + "kWh");
        System.out.println();
    }
}
