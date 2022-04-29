package week9_2_generic;

class WildcardGenericClass <T> {
    private T data;

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return "WildcardGenericClass[" +
                "data=" + data +
                ']';
    }
}

public class Wildcard {
    // 와일드카드 사용 메서드
    static void printItem(WildcardGenericClass<?> item) {
        String data = item.toString();
        System.out.println(data);
    }

    public static void main(String[] args) {
        WildcardGenericClass<Integer> item1 = new WildcardGenericClass<>(); // Integer Generic
        item1.setData(1);
        WildcardGenericClass<Double> item2 = new WildcardGenericClass<>(); // Double Generic
        item2.setData(2.2);

//        WildcardGenericClass <Number> item3 = item2; // 불가능
        WildcardGenericClass<?> item3 = item2; // 가능

        // 와일드카드 메서드 호출
        printItem(item1);
        printItem(item3);
    }
}
