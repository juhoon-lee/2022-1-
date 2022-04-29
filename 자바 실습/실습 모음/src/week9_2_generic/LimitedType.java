package week9_2_generic;

class MyMath {
    static <T extends Number> double getMax(T[] arr){ // 숫자 타입으로 제한
        T max = arr[0];
        for (T e: arr) {
            if (max.doubleValue() < e.doubleValue())
                max = e;
        }
        return max.doubleValue();
    }
}

public class LimitedType {
    public static void main(String[] args) {
        Integer[] arr = {12,32,42,53,25,34,51};
        System.out.println(MyMath.getMax(arr));
    }
}
