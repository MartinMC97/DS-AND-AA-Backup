package me.martinmc;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Knapsack_Backtracking {
    final static int sum = 4, MAXWEIGHT = 10;
    int[] weights = {7, 3, 4, 5};
    int[] values = {42, 12, 40, 25};
    List<Integer> number = Arrays.asList(0, 0, 0, 0);
    int maxValue = 0;
    List<Integer> selected = new ArrayList<>();

    public static void main(String[] args) {
        Knapsack_Backtracking instance = new Knapsack_Backtracking();
        instance.backtracking(0);

        System.out.println("number\tvalue\tweight");
        for (int i = 0; i < instance.number.size(); i++) {
            System.out.println((i + 1) + "\t" + instance.values[i] + "\t" + instance.weights[i]);
        }

        System.out.println("Max value:" + instance.maxValue);
        System.out.println("Choice: ");
        for (int i = 0; i < sum; i++)
            if (instance.selected.get(i) == 1)
                System.out.print(i + 1 + "\t");
    }

    public boolean checkWeight() {

        int totalWeight = 0, totalValue = 0;
        for (int i = 0; i < sum; i++) {
            totalValue += number.get(i) * values[i];
            totalWeight += number.get(i) * weights[i];
        }
        if (totalWeight > MAXWEIGHT)
            return false;
        else {
            if (totalValue > maxValue) {
                maxValue = totalValue;
                selected = new ArrayList<>(number);
            }
            return true;
        }
    }

    public void backtracking(int m) {
        if (m + 1 > sum)
            checkWeight();
        else {
            number.set(m, 1);
            if (checkWeight())
                backtracking(m + 1);
            number.set(m, 0);
            if (checkWeight())
                backtracking(m + 1);
        }
    }
}