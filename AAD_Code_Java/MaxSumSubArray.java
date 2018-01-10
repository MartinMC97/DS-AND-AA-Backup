package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MaxSumSubArray {


    static int subMaxSum(List<Integer> input, int left, int right) {
        int sum = 0, leftSum = 0, rightSum = 0, middleSum = 0;
        if(left == right)
            sum += input.get(left);
        else
        {
            int center = (left + right) / 2;
            leftSum = subMaxSum(input, left, center);
            rightSum = subMaxSum(input, center + 1, right);
            int midLeftSum = 0;
            int temp = 0;
            for (int i = center; i >= left; i--) {
                temp += input.get(i);
                if(temp > midLeftSum) midLeftSum = temp;
            }
            int midRightSum = 0;
            temp = 0;
            for (int i = center + 1; i <= right; i++) {
                temp+=input.get(i);
                if(temp>midRightSum) midRightSum = temp;
            }
            middleSum = midLeftSum + midRightSum;
            if(middleSum < leftSum)
                sum = leftSum;
            else sum = middleSum;
            if(sum < rightSum) sum = rightSum;
        }
        return sum;
    }


    public static void main(String[] args) {
        List<Integer> array = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the amount of number: ");
        int count = scanner.nextInt();
        System.out.println("Enter the numbers: ");
        for (int i = 0; i < count; i++)
            array.add(scanner.nextInt());
        System.out.println(array);
        System.out.println(subMaxSum(array,0,array.size()-1));
    }
}
