package me.martinmc;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FishBuying {


   /* boolean isValid(String indexString, int[][] coexist)
    {
        for (int i = 0; i < indexString.length(); i++) {
            for (int j = 0; j < ; j++) {
                
            }
        }
    }*/
    
    
    public static void main(String[] args) {
        System.out.println("输入总钱数和鱼的种类：");
        Scanner inputScanner = new Scanner(System.in);
        int totalMoney = inputScanner.nextInt();
        int fishSpecies = inputScanner.nextInt();

        System.out.println("鱼编号和价格：");
        List<Integer> prices = new ArrayList<>();
        List<Integer> numbers = new ArrayList<>();
        Scanner priceScanner = new Scanner(System.in);
        for (int i = 0; i < fishSpecies; i++) {
            numbers.add(inputScanner.nextInt());
            prices.add(inputScanner.nextInt());
        }

        System.out.println(numbers);
        System.out.println("请输入不能共存的两条鱼的编号，输入“0 0”表示输入完毕 ");
        int[][] coexist = new int[fishSpecies][fishSpecies];
        int x, y;
         do {
             x = inputScanner.nextInt() - 1;
             y = inputScanner.nextInt() - 1;
             if(x == -1)
                 break;
             else
                coexist[x][y] = 1;
        } while(true);



        /*for (int i = 0; i < fishSpecies; i++) {
            for (int j = 0; j < fishSpecies; j++) {
                System.out.print(coexist[i][j]);
            }
            System.out.print("\n");
        }*/
        /*int[] enemy = new int[fishSpecies];
        int[] killed = new int[fishSpecies];
        for (int i = 0; i < fishSpecies; i++) {
            for (int j = 0; j < fishSpecies; j++) {
                if(coexist[i][j] == 1)
                    enemy[i]++;
            }
        }*/

        for (int i = 0; i <(1<<fishSpecies) ; i++) {
            String setIndexString = String.format("%" + fishSpecies + "s",Integer.toBinaryString(i)).replace(' ', '0');
            
            List<Integer> selected = new ArrayList<>();

            for (int j = 0; j < setIndexString.length(); j++) {
                if(setIndexString.charAt(j) == '1')
                    selected.add(numbers.get(j));
            }
            
            
        }











    }

}
