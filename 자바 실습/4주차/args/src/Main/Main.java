package Main;

public class Main {

    private static int[][] arraySignFilter(int[] src) {
        int[][] result = new int[2][];

        int pCount = 0;
        int nCount = 0;

        for (int e: src){
            if (e >= 0){
                pCount += 1;
            }
            else {
                nCount += 1;
            }
        }

        int[] positive = new int[pCount];
        int[] negative = new int[nCount];
        result[0] = positive;
        result[1] = negative;

        pCount = 0;
        nCount = 0;

        for (int e: src){
            if (e >= 0){
                positive[pCount] = e;
                pCount++;
            }
            else {
                negative[nCount] = e;
                nCount++;
            }
        }
        return result;
    }

    private static void printArray(String title, int[] arr){
        System.out.print(title + " : ");
        for (int e : arr) {
            System.out.print(e + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] inputArray = {1,2,3,-1,-2,-3};

        int[][] filteredArray = arraySignFilter(inputArray);

        printArray("양의 정수", filteredArray[0]);
        printArray("음의 정수", filteredArray[1]);
    }
}
