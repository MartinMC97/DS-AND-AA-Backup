package me.martinmc;

import java.util.Scanner;
import java.util.Stack;

class Tuple<A, B> {
    private A elementA;
    private B elementB;

    public Tuple(A a, B b) {
        elementA = a;
        elementB = b;
    }

    public A getElementA() {
        return elementA;
    }

    public B getElementB() {
        return elementB;
    }
}

public class ChaosLabyrinthos {
    int row, column;
    int[][] maze;
    int[][] visited;
    int startX, startY, goalX, goalY;
    Stack<Tuple<Integer, Integer>> routeStack = new Stack<Tuple<Integer, Integer>>();

    public static void main(String[] args) {
        ChaosLabyrinthos instance = new ChaosLabyrinthos();
        instance.initialize();
        instance.solution();
    }

    void initialize() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please enter the rows and columns");
        row = scanner.nextInt();
        column = scanner.nextInt();
        maze = new int[row][column];
        visited = new int[row][column];
        System.out.println("Build the maze. Use \'0\' for path, \'1\' for walls");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }
        System.out.println("enter the start point");
        startX = scanner.nextInt();
        startY = scanner.nextInt();
        System.out.println("enter the goal");
        goalX = scanner.nextInt();
        goalY = scanner.nextInt();
    }

    boolean checkGoal() {
        int topX = routeStack.peek().getElementA();
        int topY = routeStack.peek().getElementB();
        return ((topX == goalX) && (topY == goalY));
    }

    void goAhead(int X, int Y) {
        routeStack.push(new Tuple<Integer, Integer>(X, Y));
    }

    void solution() {
        routeStack.push(new Tuple<Integer, Integer>(startX, startY));
        visited[startX][startY] = 1;
        while ((!routeStack.empty())) {
            if (checkGoal())
                break;

            int topX = routeStack.peek().getElementA();
            int topY = routeStack.peek().getElementB();
            visited[topX][topY] = 1;
            if (maze[topX][topY + 1] != 1 && visited[topX][topY + 1] != 1) {
                goAhead(topX, topY + 1);
                continue;
            }
            if (maze[topX - 1][topY] != 1 && visited[topX - 1][topY] != 1) {
                goAhead(topX - 1, topY);
                continue;
            }
            if (maze[topX][topY - 1] != 1 && visited[topX][topY - 1] != 1) {
                goAhead(topX, topY - 1);
                continue;
            }
            if (maze[topX + 1][topY] != 1 && visited[topX + 1][topY] != 1) {
                goAhead(topX + 1, topY);
                continue;
            }
            routeStack.pop();
            //visited[topX][topY] = 0;
        }
        if (routeStack.empty())
            System.out.println("No Solution.");
        else if (checkGoal()) {
            //print the result.
            System.out.println("Final result:");
            for (int i = 0; i < routeStack.size(); i++) {
                System.out.println("(" + routeStack.get(i).getElementA() + ", " + routeStack.get(i).getElementB() + ")");
            }
        }
    }
}
