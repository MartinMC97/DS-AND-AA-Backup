package me.martinmc;

import java.util.Stack;

public class StableMatching {

    static int[][] menPreferences = {{0, 1, 2, 3, 4}, {1, 2, 3, 0, 4}, {2, 3, 0, 1, 4}, {3, 0, 1, 2, 4}, {0, 1, 2, 3, 4}};
    static int[][] womenPreferences = {{1, 2, 3, 4, 0}, {2, 3, 4, 0, 1}, {3, 4, 0, 1, 2}, {4, 0, 1, 2, 3}, {0, 1, 2, 3, 4}};

    static int findPosition(int selectedWoman, int manNow) {
        for (int i = 0; i < womenPreferences[selectedWoman].length; i++) {
            if (womenPreferences[selectedWoman][i] == manNow)
                return i;
        }
        return -1;
    }

    static void startMatching(Stack<Integer> singleDogs, int currentMan, int[] menSelection, int[] menSelectionInPreferences, int[] womenToMen) {
        int selectedWoman = menPreferences[currentMan][menSelectionInPreferences[currentMan]];

        if (womenToMen[selectedWoman] == -1) {
            womenToMen[selectedWoman] = currentMan;
            menSelection[currentMan] = selectedWoman;
        } else {
            int currentManPos = findPosition(selectedWoman, currentMan);
            int selectedManPos = findPosition(selectedWoman, womenToMen[selectedWoman]);
            if (selectedManPos < currentManPos) {
                menSelectionInPreferences[currentMan]++;
                singleDogs.push(currentMan);
            } else {
                //Forgive her, of course.
                menSelectionInPreferences[womenToMen[selectedWoman]]++;
                singleDogs.push(womenToMen[selectedWoman]);
                womenToMen[selectedWoman] = currentMan;
                menSelection[currentMan] = selectedWoman;
            }
        }
    }

    public static void main(String[] args) {


        int[] menSelection = {0, 0, 0, 0, 0};
        int[] menSelectionInPreferences = {0, 0, 0, 0, 0};
        int[] womenToMen = {-1, -1, -1, -1, -1};

        Stack<Integer> singleDogs = new Stack<Integer>();

        for (int i = 0; i < menPreferences.length; i++) {
            startMatching(singleDogs, i, menSelection, menSelectionInPreferences, womenToMen);
        }

        while (!singleDogs.empty()) {
            int selectedMan = singleDogs.peek();
            singleDogs.pop();
            startMatching(singleDogs, selectedMan, menSelection, menSelectionInPreferences, womenToMen);
        }

        System.out.println("Preferences of men:");
        for (int index = 0; index < menSelection.length; index++) {
            System.out.print(index + ":\t");
            for (int i = 0; i < menSelection.length; i++) {
                System.out.print(menPreferences[index][i] + " ");
            }
            System.out.print("\n");
        }

        System.out.println("Preferences of women:");
        for (int index = 0; index < womenToMen.length; index++) {
            System.out.print(index + ":\t");
            for (int i = 0; i < womenToMen.length; i++) {
                System.out.print(womenPreferences[index][i] + " ");
            }
            System.out.print("\n");
        }

        System.out.println("Final stable pair:");
        for (int i = 0; i < menSelection.length; i++) {
            System.out.println(i + "-" + menSelection[i]);
        }
    }
}
