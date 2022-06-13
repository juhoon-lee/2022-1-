package week9_2_generic;

class Rect <T> {
    private T width;
    private T height;

    public Rect(T width, T height) {
        this.width = width;
        this.height = height;
    }

    // toString 오버라이드
    @Override
    public String toString() {
        return "Rect [width=" + width + ", height=" + height + "]";
    }
}

// 제네릭 예제
public class GenericBasic {
    public static void main(String[] args) {
        Rect <Integer> r1 = new Rect<Integer>(1,2);
        System.out.println(r1);

        Rect <Double> r2 = new Rect<Double>(1.1,2.2);
        System.out.println(r2);
    }
}