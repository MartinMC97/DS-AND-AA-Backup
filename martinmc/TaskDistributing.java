package me.martinmc;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TaskDistributing {

    List<List<Integer>> costMatrix = Arrays.asList(
            Arrays.asList(9, 2, 7, 8),
            Arrays.asList(6, 4, 3, 7),
            Arrays.asList(5, 8, 1, 8),
            Arrays.asList(7, 6, 9, 4));
    List<Integer> selectedTask = new ArrayList<>();
    List<SnapshotNode> PT = new ArrayList<>();
    int up, down;

    TaskDistributing() {
        setUpAndDown();
        for (int i = 0; i < 4; i++) {
            selectedTask.add(-1);
        }
    }

    public static void main(String[] args) {
        TaskDistributing instance = new TaskDistributing();
        instance.processing(-1);
    }

    public SnapshotNode findMinSnapshot() {
        SnapshotNode temp = new SnapshotNode();
        int tempLB = up;
        for (SnapshotNode node : PT
                ) {
            if (node.LBValue < tempLB) {
                temp = node;
                tempLB = node.LBValue;
            }
        }
        return temp;
    }

    public int findMinValueByRow(int row) {
        int minValue = up;
        List<Integer> selected = costMatrix.get(row);
        for (int i = 0; i < selected.size(); i++) {
            minValue = (selected.get(i) < minValue) ? selected.get(i) : minValue;
        }
        return minValue;
    }

    public int getCost() {
        int totalCost = 0;
        for (int i = 0; i < selectedTask.size(); i++) {
            if (selectedTask.get(i) != -1) {
                totalCost += costMatrix.get(i).get(selectedTask.get(i));
            }
        }
        return totalCost;
    }

    public int getLBValue(int row) {
        int LBValue = getCost();
        for (int i = row + 1; i < costMatrix.size(); i++) {
            LBValue += findMinValueByRow(i);
        }
        return LBValue;
    }

    public void setUpAndDown() {
        for (int i = 0; i < selectedTask.size(); i++) {
            down += findMinValueByRow(i);
        }
        up = 14;
    }

    public void processing(int row) {
        int child = row + 1;
        while (true)     //叶子节点
        {
            List<Integer> rowCost = costMatrix.get(child);
            int[] rowLB = {up, up, up, up};
            for (int i = 0; i < rowCost.size(); i++) {      //计算选择每个任务的时候的LB值
                if (selectedTask.indexOf(i) == -1) {
                    selectedTask.set(child, i);
                    int LBValue = getLBValue(child);
                    if (LBValue <= up) {
                        rowLB[i] = LBValue;
                        PT.add(new SnapshotNode(selectedTask, child, LBValue));
                    }
                }
            }
            SnapshotNode snap = findMinSnapshot();
            selectedTask.clear();
            selectedTask.addAll(snap.selectedTask);
            child = snap.row;
            PT.remove(snap);
            if(child == selectedTask.size()-1)
                break;
            else
                child++;
        }
        System.out.println("final result:");
        for (int i = 0; i < selectedTask.size(); i++) {
            System.out.println((char) ('a' + i) + ": " + (selectedTask.get(i) + 1));
        }
    }

    class SnapshotNode {
        List<Integer> selectedTask = new ArrayList<>();
        int row;
        int LBValue;

        SnapshotNode(List<Integer> selectedTask, int row, int LBValue) {
            this.selectedTask.addAll(selectedTask);
            this.row = row;
            this.LBValue = LBValue;
        }

        SnapshotNode() {

        }
    }

}
