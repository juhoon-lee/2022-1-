package week10_collection;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.TreeMap;

public class MapTest {
    public static void hashMapTest() { // 그냥 딕셔너리랑 똑같네
        HashMap<String,String> m = new HashMap<>();
        m.put("1","A");
        m.put("2","p");
        m.put("3","p");
        m.put("4","l");
        m.put("5","e");
        System.out.println(m);
    }

    public static void linkedHashMapTest() { // 삽입 순서대로
        LinkedHashMap<String,String> m = new LinkedHashMap<>();
        m.put("1","A");
        m.put("2","p");
        m.put("3","p");
        m.put("4","l");
        m.put("5","e");
        System.out.println(m);
    }

    public static void treeMapTest() { // 정렬된 map
        TreeMap<String,String> m = new TreeMap<>();
        m.put("1","A");
        m.put("2","p");
        m.put("3","p");
        m.put("4","l");
        m.put("5","e");
        System.out.println(m);
    }

    public static void main(String[] args) {
        hashMapTest();
        linkedHashMapTest();
        treeMapTest();
    }
}
