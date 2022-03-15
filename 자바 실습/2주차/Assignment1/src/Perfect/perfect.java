package Perfect;

public class perfect {
    static boolean perfectCheck(int arg) {
        int sum = 0;
        for (int i = 1; i < arg; i++) {
            if (arg % i == 0) {
                sum += i;
            }
        }

        return arg == sum;
    }

    public static void printPerfect(int n) {
        System.out.print("Perfect Number:\n" + " ");
        for (int i = 2; i <= n; i++) {
            if (perfectCheck(i)) {
                System.out.print(i + " ");
            }
        }
    }
}
