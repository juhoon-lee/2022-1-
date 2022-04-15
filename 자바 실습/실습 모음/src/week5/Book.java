package week5;

// 생성자 오버로딩 예제
public class Book {
    String title ;
    String author;

    public Book(String t){
        this(t, "작자미상");
    }// this를 쓰려면 매개변수가 많은것 부터 줄여나가는게 좋을듯
    public  Book(String t, String a){
        title = t;
        author = a;
    }
    protected void printBook() {
        System.out.println("("+ title + ", " + author +")");
    }

    public static void main(String[] args) {
        Book littlePrince = new Book("어린왕자","생텍쥐페리");
        Book loveStory = new Book("츈향전");

        System.out.println(littlePrince.title + " " + littlePrince.author);
        System.out.println(loveStory.title + " " + loveStory.author);
    }
}
