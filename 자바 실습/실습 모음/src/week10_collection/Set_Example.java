package week10_collection;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.TreeSet;

public class Set_Example {
    public static void hashSetTest() {
        System.out.println("Hash Set===============");
        HashSet<String> s = new HashSet<>();
        s.add("a");
        s.add("p");
        s.add("p");
        s.add("l");
        s.add("e");
        System.out.println(s);
        System.out.println(s.size());

        Iterator<String> it = s.iterator();
        while(it.hasNext()){ // true 면 원소가 있다.
            String e = it.next();
            System.out.println(e + " ");
        }
        // 위의 것을 forEach 로 구현
        for (String e : s) {
            System.out.println(e + " ");
        }
    }

    public static void LinkedHashSetTest() {
        System.out.println("Linked Hash Set===============");
        LinkedHashSet<String> s = new LinkedHashSet<>();
        s.add("a");
        s.add("p");
        s.add("p");
        s.add("l");
        s.add("e");
        System.out.println(s);
        System.out.println(s.size());
    }
    public static void treeSetTest() {
        System.out.println("Tree Hash Set===============");
        TreeSet<String> s = new TreeSet<>();
        s.add("a");
        s.add("p");
        s.add("p");
        s.add("l");
        s.add("e");
        System.out.println(s);
        System.out.println(s.size());
    }

    public static void main(String[] args) {
        hashSetTest(); // 순서 보장 x
        LinkedHashSetTest(); // add 순서대로
        treeSetTest(); // 트리를 통해 알파벳 순서대로
    }
}
