package week14_Network;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;

public class ClientTester {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket();
        socket.connect(new InetSocketAddress("127.0.0.1",5000));
        System.out.println("[Client] Start!");
        DataInputStream dis = new DataInputStream(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

        // 데이터 보내기
        dos.writeUTF("bye");
        String str = dis.readUTF();
        System.out.println(str);

        dis.close();
        dos.close();
        socket.close();
        System.out.println("[Client] Terminated!");
    }
}
