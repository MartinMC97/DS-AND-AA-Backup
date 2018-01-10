package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Gasoline {

    static List<Integer> distances = new ArrayList<>();
    static int d = 0;

    static int getDistance(int currentStation, int tempStation)
    {
        int tempDistance = 0;
        for (int i = currentStation + 1; i <= tempStation ; i++) {
            tempDistance+=distances.get(i);
        }
        return tempDistance;
    }

    public static void main(String[] args) {

        List<Integer> result = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of stations: ");
        int stationCount = scanner.nextInt();
        System.out.println("Enter max distance of the car: ");
        d = scanner.nextInt();
        distances.add(-1);

        System.out.println("Please enter the distance between the stations: ");
        for (int i = 0; i < stationCount; i++) {
            distances.add(scanner.nextInt());
        }

        int currentStation = 0;
        int tempStation;
        while((currentStation + 1) != stationCount)
        {
            tempStation = currentStation;
            while(getDistance(currentStation, tempStation) <= d)
            {
                tempStation++;
                if(tempStation == stationCount)
                    break;
            }
            currentStation = tempStation -1;
            result.add(currentStation);
        }
        System.out.println("The result station numbers :\n" + result);

    }
}