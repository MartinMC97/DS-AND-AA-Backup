package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FindKth {

    static void MSort(List<Integer> list, List<Integer> temp, int start, int end) {

        if (start >= end)
            return;

        int len = end - start, mid = (len >> 1) + start;
        int index1 = start, end1 = mid;
        int index2 = mid + 1, end2 = end;

        MSort(list, temp, index1, end1);
        MSort(list, temp, index2, end2);

        int k = start;

        while (index1 <= end1 && index2 <= end2)        //归并开始
        {

            if (list.get(index1) < list.get(index2))
                temp.set(k++, list.get(index1++));
            else
                temp.set(k++, list.get(index2++));
        }

        while (index1 <= end1)
            temp.set(k++, list.get(index1++));

        while (index2 <= end2)
            temp.set(k++, list.get(index2++));


        for (k = start; k <= end; k++)        //把排序好的部分放入原数组中
            list.set(k, temp.get(k));
    }

    static void MergeSort(List<Integer> list) {
        List<Integer> temp = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            temp.add(0);
        }
        MSort(list, temp, 0, list.size() - 1);
    }

    public static void main(String[] args) {
        List<Integer> array = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the amount of number: ");
        int count = scanner.nextInt();
        System.out.println("Enter the numbers: ");
        for (int i = 0; i < count; i++)
            array.add(scanner.nextInt());
        MergeSort(array);
        System.out.println("Input the Kth number you wanna find: ");
        System.out.println(array.get(scanner.nextInt() - 1));
    }


}
