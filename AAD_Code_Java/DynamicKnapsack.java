package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DynamicKnapsack {

    static int Max(int num1, int num2) {
        return (num1 > num2) ? num1 : num2;
    }

    public static void main(String[] args) {
        int sum, MAXWEIGHT;
        List<Integer> result = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Input the amount of items and the max weight: ");
        sum = scanner.nextInt();
        MAXWEIGHT = scanner.nextInt();

        int[] weights = new int[sum + 1];
        int[] values = new int[sum + 1];
        weights[0] = 0;
        values[0] = 0;
        int[][] V = new int[sum + 1][MAXWEIGHT + 1];

        System.out.println("Input the weight and value of each item: ");
        for (int i = 1; i <= sum; i++) {
            weights[i] = scanner.nextInt();
            values[i] = scanner.nextInt();
        }

        for (int i = 0; i <= sum; i++) {
            V[i][sum] = 0;
        }

        for (int i = 0; i <= MAXWEIGHT; i++) {
            V[0][i] = 0;
        }

        for (int i = 1; i <= sum; i++)
            for (int j = 1; j <= MAXWEIGHT; j++)
                if (j < weights[i])
                    V[i][j] = V[i - 1][j];
                else
                    V[i][j] = Max(V[i - 1][j], V[i - 1][j - weights[i]] + values[i]);

        for (int j = MAXWEIGHT, i = sum; i > 0; i--) {
            if (V[i][j] > V[i - 1][j]) {
                result.add(i);
                j = j - weights[i];
            }
        }

        System.out.println("Max value: " + V[sum][MAXWEIGHT]);
        System.out.println("Final choice: " + result);
    }
}
