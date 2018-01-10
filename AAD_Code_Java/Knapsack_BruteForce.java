package me.martinmc;

import java.util.ArrayList;
import java.util.List;

public class Knapsack_BruteForce {

    public static void main(String[] args) {
        int[] weights = {7, 3, 4, 5};
        int[] values = {42, 12, 40, 25};
        Integer[] number = {1, 2, 3, 4};

        final int sum = 4, MAXWEIGHT = 10;
        int maxValue = 0;

        List<Integer> resultSet = new ArrayList<>();

        for (int i = 0; i <(1<<sum) ; i++) {

            String setIndexString = String.format("%" + number.length + "s",Integer.toBinaryString(i)).replace(' ', '0');

            List<Integer> selected = new ArrayList<>();

            for (int j = 0; j < setIndexString.length(); j++) {
                if(setIndexString.charAt(j) == '1')
                    selected.add(number[j]);
            }

            int totalWeight = 0;
            int totalValue = 0;

            for (Integer index: selected
                 ) {
                totalWeight+= weights[index - 1];
                totalValue += values[index - 1];
            }

            if(totalWeight <= MAXWEIGHT)
            {
                if(totalValue >= maxValue)
                {
                    maxValue = totalValue;
                    resultSet = selected;
                }
                else
                    continue;
            }
            else
                continue;

        }

        System.out.println("number\tvalue\tweight");
        for (int i = 0; i < number.length; i++) {
            System.out.println(number[i] + "\t" + values[i] + "\t" + weights[i]);
        }

        System.out.println("Final chioce: " + resultSet);
        System.out.println("Max value: " + maxValue);
    }
}
