package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ShortDistance {

    static int Partition(List<Integer> input, int low, int high) {
        int pivot = input.get(low);

        while (low < high) {
            while (high > low && input.get(high) >= pivot)
                high--;
            input.set(low, input.get(high));
            while (high > low && input.get(low) <= pivot)
                low++;
            input.set(high, input.get(low));
        }
        input.set(low, pivot);
        return low;
    }

    static void QSort(List<Integer> input, int low, int high) {
        if (low < high) {
            int pivot = Partition(input, low, high);
            QSort(input, low, pivot - 1);
            QSort(input, pivot + 1, high);
        }
    }

    static void QuickSort(List<Integer> input) {
        QSort(input, 0, input.size() - 1);
    }


    public static void main(String[] args) {
        List<Integer> xCoordinate = new ArrayList<>();
        List<Integer> yCoordinate = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int loop = scanner.nextInt();

        System.out.println("Enter the coordinates: ");
        for (int i = 0; i < loop; i++) {
            xCoordinate.add(scanner.nextInt());
            yCoordinate.add(scanner.nextInt());
        }

        QuickSort(xCoordinate);
        QuickSort(yCoordinate);

        double resultX;
        double resultY;
        if (loop % 2 == 0) {
            int mid = loop / 2 - 1;
            resultX = (xCoordinate.get(mid) + xCoordinate.get(mid + 1)) / 2.0;
            resultY = (yCoordinate.get(mid) + yCoordinate.get(mid + 1)) / 2.0;
        } else {
            resultX = xCoordinate.get(loop / 2);
            resultY = yCoordinate.get(loop / 2);
        }

        double totalDistance = 0.0;
        for (int i = 0; i < loop; i++) {
            totalDistance += (Math.abs((double) xCoordinate.get(i) - resultX) + Math.abs((double) yCoordinate.get(i) - resultY));
        }

        System.out.println("Shortest distance: " + totalDistance);
    }
}
