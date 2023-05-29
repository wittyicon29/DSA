class ParkingSystem {
    int biglimit, mediumlimit, smalllimit;
    int[] parkingArray;

    public ParkingSystem(int big, int medium, int small) {
        this.biglimit = big;
        this.mediumlimit = medium;
        this.smalllimit = small;

        this.parkingArray = new int[big + medium + small];
        for(int i = 0; i < this.parkingArray.length; i++){
            this.parkingArray[i] = 0;
        }
    }
    
    public boolean addCar(int carType) {
        int limit = 0;
        if(carType == 1){
            limit = this.biglimit;
        }
        if(carType == 2){
            limit = this.mediumlimit;
        }
        if(carType == 3){
            limit = this.smalllimit;
        }
        int count = 0;
        for(int i = 0; i < this.parkingArray.length; i++){
            if(this.parkingArray[i] == carType){
                count++;
            }
            if(count == limit){
                return false;
            }
            if(this.parkingArray[i] == 0){
                this.parkingArray[i] = carType;
                return true;
            }
        }
        return false;
    }

}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */