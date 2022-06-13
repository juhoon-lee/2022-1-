package week9_1;

class Rect {
    int width;
    int height;
    public Rect(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof Rect)) return false;
        Rect r = (Rect) obj;
        if (width*height == r.height*r.width) return true;
        else return false;
    }
}

class Point {
    int x,y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public boolean equals(Object p) {
        if (!(p instanceof Point)) return false;
        Point obj = (Point) p;
        if (x == obj.x && y == obj.y) return true;
        else return true;
    }
}

public class Tester {
    public static void main(String[] args) {
        Point p1 = new Point(1,2);
        Point p2 = new Point(3,4);
        Point p3 = p1;

        System.out.println("=============hashCode()=====================");
        System.out.println(p1.hashCode()); //System.out.println(System.identityHashCode(a));
        System.out.println(p2.hashCode());
        System.out.println(p3.hashCode());

        System.out.println("=============getClass()=====================");
        Point p4 = new Point(5,6);
        System.out.println(p4.getClass().getName());
        System.out.println(p4.getClass().getSimpleName());
        System.out.println(p4.getClass().getPackageName());

        System.out.println("=============toString()=====================");
        Point p5 = new Point(7,8);
        System.out.println(p5.toString());
        System.out.println(p5); // 레퍼런스 타입이지만 사실 toString을 통해 출력된다.

        System.out.println("=============equals()=====================");
        Point a = new Point(2,3);
        Point b = new Point(2,3);
        System.out.println(a.equals(b));
        System.out.println("equals() 오버라이딩 예제");
        Rect c = new Rect(2,3);
        Rect d = new Rect(3,2);
        if (c.equals(d)) System.out.println("넓이 같음");
        else System.out.println("넓이 다름");
    }
}
