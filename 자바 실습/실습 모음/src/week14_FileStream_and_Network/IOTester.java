package week14_FileStream_and_Network;

import java.io.*;
import java.util.Scanner;

public class IOTester {
    static void binCopy() {
        String src = "Blue.jpg";
        String des = "CopyImg.jpg";
        try {
            FileInputStream fis = new FileInputStream(src);
            FileOutputStream fout = new FileOutputStream(des);
            int c;
            while((c = fis.read()) != -1 ) {
                fout.write(c);
            }
            fis.close();
            fout.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void binRead() {
        try {
            FileInputStream fis = new FileInputStream("test.out");
            DataInputStream dis = new DataInputStream(fis);
            System.out.println(fis.read());
            System.out.println(dis.readDouble());
            System.out.println(dis.readUTF());
            fis.close();
            dis.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void binWrite() {
        try {
            byte [] buf = {1,2,3,4,5,6,7,8};
            FileOutputStream fos = new FileOutputStream("test.out");
            fos.write(buf);
            fos.close();

            FileOutputStream out = new FileOutputStream("test.out");
            DataOutputStream fos2 = new DataOutputStream(out); // 다양한 타입의 데이터 처리 가능
            fos2.write(2);
            fos2.writeDouble(3.14);
            fos2.writeUTF("String byte로 넣기");
            fos2.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void fileCopy() {
        try {
            FileReader fin = new FileReader("test.txt");
            FileWriter fout = new FileWriter("test2.txt");
            Scanner sc = new Scanner(fin);
            int lineNumber = 1;
            while (sc.hasNext()) {
                String line = sc.nextLine();
                System.out.printf("%3d %s \n",lineNumber,line);
                fout.write(String.format("%3d %s \n",lineNumber,line));
                lineNumber++;
            }
            sc.close();
            fin.close();
            fout.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void fileWrite() {
        // 바이트 단위 : FileOutputStream
        // 문자 단위 : FileWriter
        // 필터스트림: BufferInputStream, DataInputStream
        try {
            FileOutputStream fout = new FileOutputStream("test2.txt");
            fout.write('자');
            fout.close();

            FileOutputStream out = new FileOutputStream("test2.txt");
            OutputStreamWriter fout2 = new OutputStreamWriter(out);
            fout2.write("자바기반 응용프로그래밍 - OutputStream");
            fout2.close();

            FileWriter fw = new FileWriter("test2.txt");
            String str = "자바기반 응용 프로그래밍 - Filewriter";
            fw.write(str, 0, str.length());
            fw.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    static void fileRead() {
        // 바이트 단위: 바이트 스트림 - FileInputStream
        // 문자 단위: 문자 스트림 - FileReader
        // 필터스트림: BufferInputStream, DataInputStream

        // lab1. 바이트스트림 파일을 읽어서 모니터로 출력
        try {
            // 바이트 리더
            FileInputStream fin = new FileInputStream("test.txt"); // 바이트를 출력해서 이상한 문자
            int c;
            while ((c = fin.read()) != -1) {
                System.out.print((char) c);
            }
            System.out.println();
            fin.close();

            // 바이트 리드, 문자로 변환 // 스트림 체이닝
            FileInputStream in = new FileInputStream("test.txt");
            InputStreamReader fin2 = new InputStreamReader(in); // 바이트스트림을 읽어서 문자로 변환 및 출력
            while ((c = fin2.read()) != -1) {
                System.out.print((char) c);
            }
            System.out.println();
            fin2.close();

            // fileReader가 가장 무난하고 쉬운 방법(while문 처리나 한 줄 씩 읽는 것)
            // 파일 자체를 읽어서 텍스트 출력
            FileReader fin3 = new FileReader("test.txt"); // 파일을 텍스트로 읽어서 입출력
            while ((c = fin3.read()) != -1) {
                System.out.print((char) c);
            }
            System.out.println();
            fin3.close();

            // 파일을 버퍼 단위로 읽어서 출력
            char[] buf = new char[256];
            FileReader fin4 = new FileReader("test.txt");
            fin4.read(buf); // 버퍼에 텍스트 파일 넣기
            System.out.println(buf);
            fin4.close();

            FileReader r = new FileReader("test.txt");
            BufferedReader fin5 = new BufferedReader(r);
            System.out.println(fin5.readLine()); // 라인별로 받아서 출력
            System.out.println(fin5.readLine()); // 두번째 라인이 없어서 null
            r.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        // 텍스트 데이터 읽고 쓰기
//        fileWrite();
//        fileRead();
//        fileCopy();
        // 이진 데이터 읽고 쓰기
        binWrite();
        binRead();
        binCopy();
    }
}
