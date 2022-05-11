package week10_collection;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class Collections {
    // Vector
    public static void vectorTest() {
        System.out.println("Vector Test ================");
        Vector<Integer> v = new Vector<>();
        System.out.println(v.capacity());
        System.out.println(v.size());
//        v.add(1);
        for (int i = 0; i < v.capacity(); i++) {
            v.add(i); // push
        }
        v.add(0,99); // insert
        System.out.println(v);
        System.out.println(v.capacity());

        for (int i = 0; i < v.size(); i++) {
            System.out.print(v.get(i) + " ");
        }
        System.out.println();
        v.set(0,98);// update
        System.out.println(v);
        v.remove(0);
        System.out.println(v);// remove


        Vector<Integer> v2 = new Vector<>();// v2 선언
        v2.add(101);
        v2.add(102);
        v2.add(103);
        System.out.println(v2);
        v.addAll(0,v2); // v 에 v2 추가
        System.out.println(v);
        System.out.println();
    }

    // ArrayList
    public static void arrayListTest() {
        System.out.println("ArrayList Example==================");
        ArrayList<String> ar = new ArrayList<>(); // ArrayList -> LinkedList로 바꿔도 가능
        // 내부 동작이 달라지지 List와 Collection을 상속 받음으로 구현은 같다.
        List<String> lar = ar; // List로 업캐스팅 가능
        ar.add("b");
        ar.add("p");
        ar.add("p");
        ar.add("l");
        ar.add("e");
        ar.add("!");
        System.out.println(ar);
        System.out.println(ar.size());
        for (int i = 0; i < ar.size(); i++) {
            System.out.print(ar.get(i) + " ");
        }
        System.out.println();
        ar.set(0,"a"); // update
        System.out.println(ar);
        ar.remove(5); // remove
        System.out.println(ar);
    }

    public static void main(String[] args) {
        vectorTest();
        arrayListTest();
    }
}
