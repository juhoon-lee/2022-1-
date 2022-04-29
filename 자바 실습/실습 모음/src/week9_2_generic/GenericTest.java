package week9_2_generic;

class ObjectItem {
    private Object data;

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }
}

class GenericItem <T> {
    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    private T data;
}

// 다중 타입 매개변수 사용
class multiTypeGeneric <K,V> {
    private K key;
    private V value;

    public K getKey() {
        return key;
    }
    public void setKey(K key) {
        this.key = key;
    }
    public V getValue() {
        return value;
    }
    public void setValue(V value) {
        this.value = value;
    }
}


public class GenericTest {
    public static void main(String[] args) {
        // 제네릭을 사용하지 않고 Object를 사용했을 때.
        ObjectItem objectItem = new ObjectItem();
        objectItem.setData(1); // 문자를 입력하면 런타임 에러 발생(아래에서 Integer로 형변환 했기 때문)
        Integer i = (Integer) objectItem.getData(); // Object를 Integer로 형변환해 사용.
        System.out.println(i);

        // 제네릭을 사용했을 때.
        GenericItem <Integer> gItem = new GenericItem<>();
        gItem.setData(2);
//        gItem.setData("1"); // Integer로 구체화해서 문자를 넣으려 하면 컴파일 에러(런타임 보다 더 좋음)
        Integer i2 = gItem.getData();
        System.out.println(i2);

        // 다중 타입 매개변수 제네릭
        multiTypeGeneric<String,Integer> a1 = new multiTypeGeneric<>(); // String, Integer
        multiTypeGeneric<Integer,Integer> a2 = new multiTypeGeneric<>();// Integer, Integer

    }
}
