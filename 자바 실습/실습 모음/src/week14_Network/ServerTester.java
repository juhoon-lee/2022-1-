package week14_Network;

import java.io.*;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;



public class ServerTester {
    static Map<String,String> db = new HashMap<String,String>();
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(); // 서버소켓 생성
        db.put("map","지도");
        db.put("inha","인하");

        server.bind(new InetSocketAddress("127.0.0.1",5000)); // 소켓 바인딩
        System.out.println("[Server] Start!");

        boolean bRun = true;
        while (bRun) {
            // accept
            Socket socket = server.accept();
            System.out.println("[Server] Connected!");
            // Stream
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            // 데이터 통신이 어려워서 Filter Stream 사용
            DataInputStream dis = new DataInputStream(is); // 그냥 is 대신 socket.getInputStream() 사용 가능
            DataOutputStream dos = new DataOutputStream(os); // 그냥 os 대신 socket.getOutputStream() 사용 가능

            // data communication
            // 서버가 데이터를 받음
            String str = dis.readUTF();
            if (str.equals("server_os")) {
                dos.writeUTF(System.getProperty("os.name"));
            } else if (str.equals("server_arch")) {
                dos.writeUTF(System.getProperty("os.arch"));
            } else if (str.equals("server_time")) {
                Date now = new Date(System.currentTimeMillis());
                dos.writeUTF(now.toString());
            } else if (str.equals("bye")) {
                bRun = false;
                dos.writeUTF("bye");
            } else {
                String result = db.get(str);
                dos.writeUTF(result);
            }

            System.out.println(str);

            dis.close();
            dos.close();
            socket.close();
        }
        server.close();
        System.out.println("[Server] Terminated!");
    }
}
