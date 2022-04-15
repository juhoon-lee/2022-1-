package week5;

public class Circle {
    int radius = 1;

    Circle(int r) {
        radius = r;
    }

    double getArea() {
        return  3.14*radius*radius;
    }

    void  printArea() {
        System.out.println(getArea());
    }

    public static void main(String[] args) {
        Circle[] cArr = new Circle[5];
        for (int i = 0; i < cArr.length; i++) {
            cArr[i] = new Circle(i);
            cArr[i].printArea();
        }
    }
}