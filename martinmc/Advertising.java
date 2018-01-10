//INCORRECT, DO NOT USE IT.

/*package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Advertising {

    static List<Integer> locations = new ArrayList<>();
    static List<Integer> income = new ArrayList<>();
    static List<Integer> result = new ArrayList<>();

    static int firstOutOfRange(int index) {
        if (index > 0) {
            for (int i = index - 1; i >= 0; i--) {
                if (locations.get(index) - locations.get(i) >= 5) // found it. return it.
                    return i;
            }
        }
        return 0;   //cannot find.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the amount of possible locations: ");
        int count = scanner.nextInt();
        System.out.println("Enter the locaion and income for each spot.\nPlease write in pair:");
        for (int i = 0; i < count; i++) {
            locations.add(scanner.nextInt());
            income.add(scanner.nextInt());
        }

        int[][] choice = new int[count + 1][count];
        int[] opt = new int[count + 1];

        opt[0] = 0;

        for (int i = 0; i < count; i++) {
            choice[0][i] = 0;
        }

        for (int i = 1; i <= count; i++) {
            if ((income.get(i - 1) + opt[firstOutOfRange(i - 1)]) > opt[i - 1]) {
                for (int j = 0; j < count; j++) {
                    choice[i][j] = choice[firstOutOfRange(i - 1)][j];
                }
                choice[i][i - 1] = 1;
                opt[i] = income.get(i - 1) + opt[firstOutOfRange(i - 1)];

            } else {
                for (int j = 0; j < count; j++)
                    choice[i][j] = choice[i - 1][j];

                opt[i] = opt[i - 1];
            }
        }
        System.out.println("Max Value: " + opt[count - 1]);
    }
}
*/
