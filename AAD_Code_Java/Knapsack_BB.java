package me.martinmc;

import java.util.Arrays;
import java.util.List;

public class Knapsack_BB {
    final static int sum = 4, MAXWEIGHT = 10;
    int[] weights = {4, 7, 5, 3};
    int[] values = {40, 42, 25, 12};
    int[] number = {1, 2, 3, 4};
    int down, up;
    List<Integer> selected = Arrays.asList(0, 0, 0, 0);

    public static void main(String[] args) {
        Knapsack_BB instance = new Knapsack_BB();
        instance.backtracking(-1);
    }

    public void setUpAndDownValue()
    {
        this.up = MAXWEIGHT * (values[0] / weights[0]);
        this.down = 65;
    }

    public int getUBValue(List<Integer> selected, int m) {
        int v = getTotalValue(selected);
        int w = getTotalWeight(selected);
        if ((m + 1) >= sum)
            return v;
        else
            return v + (MAXWEIGHT - w) * (values[m + 1] / weights[m + 1]);
    }

    public int getTotalValue(List<Integer> selected) {
        int totalValue = 0;
        for (int i = 0; i < selected.size(); i++)
            totalValue += values[i] * selected.get(i);
        return totalValue;
    }

    public int getTotalWeight(List<Integer> selected) {
        int totalWeight = 0;
        for (int i = 0; i < selected.size(); i++)
            totalWeight += weights[i] * selected.get(i);
        return totalWeight;
    }

    public void backtracking(int m) {
        int child = m + 1;
        if (child + 1 >= sum)    //是叶子节点
        {
            if (getTotalWeight(selected) <= MAXWEIGHT) {
                System.out.println("number\tvalue\tweight");
                for (int i = 0; i < selected.size(); i++) {
                    System.out.println((i + 1) + "\t" + values[i] + "\t" + weights[i]);
                }

                System.out.println("Max value:" + getTotalValue(selected));
                System.out.println("Choice: ");
                for (int i = 0; i < sum; i++)
                    if (selected.get(i) == 1)
                        System.out.print(i + 1 + "\t");
            }
        } else {
            int totalWeight;
            selected.set(child, 1);
            totalWeight = getTotalWeight(selected);
            int ub1 = (totalWeight <= MAXWEIGHT) ? getUBValue(selected, child) : -1;

            selected.set(child, 0);
            totalWeight = getTotalWeight(selected);
            int ub2 = (totalWeight <= MAXWEIGHT) ? getUBValue(selected, child) : -1;

            selected.set(child, (ub1 > ub2) ? 1 : 0);

            backtracking(m + 1);
        }
    }
}
