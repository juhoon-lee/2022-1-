package Assignment4;

import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Objects;
import java.util.Scanner;

class Car {
    private final int carNumber;
    private final String owner;

    public Car(int carNumber, String owner) {
        this.carNumber = carNumber;
        this.owner = owner;
    }

    public int getCarNumber() {
        return carNumber;
    }

    public String getOwner() {
        return owner;
    }
}

class Parking {
    private final Car[] carList = new Car[6];
    private final int[][] parkingState;

    public Parking(int row, int column, String[] names) {
        // 주차장 세팅
        parkingState = new int[row][column];
        for (int[] i : parkingState) {
            Arrays.fill(i, 0);
        }

        // 차량 등록 세팅 1111 ~ 6666;
        int carNumber = 1111;
        for (int i = 0; i < carList.length; i++) {
            carList[i] = new Car(carNumber, names[i]);
            carNumber += 1111;
        }
    }

    public void printArea() {
        for (int i = 0; i < parkingState.length; i++ ) {
            for (int j = 0; j < parkingState[i].length; j ++){
                if (parkingState[i][j] == 0) {
                    System.out.print("("+i+", "+j+") : ____ ");
                } else {
                    String owner = "";
                    for (Car c : carList) {
                        if (c.getCarNumber() == parkingState[i][j]){
                            owner = c.getOwner();
                        }
                    }
                    System.out.print("("+i+", "+j+") : " + parkingState[i][j] + "(" +owner +") ");
                }
            }
            System.out.println();
        }
    }

    public void check(int carNumber) {
        boolean isCarRegister = false;
        boolean isEmptyArea = false;

        // 등록된 차량인지 체크
        for (Car c: carList) {
            if (c.getCarNumber() == carNumber) {
                isCarRegister = true;
                break;
            }
        }
        // 등록되지 않은 차량이면 out
        if (!isCarRegister){
            System.out.println("등록되지 않은 차량입니다.");
            return;
        }

        // 등록된 차량이면 입차, 출차, 만차 결정

        // 차량이 있는지 확인
        for (int i = 0; i < parkingState.length; i++) {
            for (int j = 0; j < parkingState[i].length; j++) {
                if (parkingState[i][j] == carNumber) {
                    // 출차
                    carOut(carNumber,i,j);
                    return;
                }
            }
        }

        // 출차할 차량이 아니라면 빈자리 확인
        for(int[] ps: parkingState) {
            for (int isEmpty: ps){
                if (isEmpty == 0) {
                    isEmptyArea = true;
                    break;
                }
            }
        }
        if (!isEmptyArea) {
            System.out.println("만차입니다.");
            return;
        }

        // 빈자리 찾아서 입차
        for (int i = 0; i < parkingState.length; i++) {
            for (int j = 0; j < parkingState[i].length; j++) {
                    if (parkingState[i][j] == 0) {
                        // 입차
                        carEnter(carNumber,i,j);
                        return;
                    }
            }
        }
    }

    private void carEnter(int carNumber, int firstIndex, int secondIndex) {
        parkingState[firstIndex][secondIndex] = carNumber;
        System.out.println(carNumber + "번 차량이 (" + firstIndex + ", " + secondIndex + ")에 주차했습니다.");
    }

    private void carOut(int carNumber, int firstIndex, int secondIndex) {
        String owner = findOwner(carNumber);
        parkingState[firstIndex][secondIndex] = 0;
        System.out.println("차주 " + owner + ", " + carNumber + "번 차량이 출차했습니다.");
    }

    private String findOwner(int carNumber) {
        for (Car c : carList) {
            if (c.getCarNumber() == carNumber) {
                return  c.getOwner();
            }
        }
        return "존재하지 않는 차량 번호입니다.";
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("이주훈(12181818)");
        Scanner scanner = new Scanner(System.in);
        String[] defaultNames = new String[] {"Lee","Kim","Gang","Park","Hong","Go"};

        int row;
        int column;
        String command;

        // 주차장 크기 정하기
        while(true) {
            try {
                System.out.print("주차장 크기(행과 열)을 입력하세요: ");
                row = scanner.nextInt();
                if (row <= 0)
                    throw new Exception("Error!! 0보다 큰 정수를 입력하세요.");
                column = scanner.nextInt();
                if (column <= 0)
                    throw new Exception("Error!! 0보다 큰 정수를 입력하세요.");
                break;
            }
            catch (InputMismatchException e1) {
                System.out.println("Error!! 정수를 입력하세요.");
                scanner.nextLine();
            }
            catch (Exception e2) {
                System.out.println(e2.getMessage());
                scanner.nextLine();
            }
            System.out.println();
        }

        Parking parking = new Parking(row, column, defaultNames); // Parking

        // 근무 시작
        System.out.println("이주훈 근무를 시작합니다.");
        while(true) {
            int carNumber = 0;
            parking.printArea(); // 주차장 현황 출력
            System.out.print("차량 번호를 입력하세요: ");
            command = scanner.next();
            if (Objects.equals(command, "퇴근"))
                break;

            // 에러처리
            try {
                carNumber = Integer.parseInt(command);
                if (command.length() != 4) {
                    throw new Exception("4자리 차량 번호를 입력하세요.");
                }
            }
            catch (NumberFormatException e1) { // 퇴근이 아닌 숫자를 입력했을 때.
                System.out.println("Error!! 퇴근 또는 차량 번호를 입력하세요.");
                System.out.println();
                continue;
            }
            catch (Exception e2) { // 숫자나 퇴근이지만 차량 번호인 4자리가 아닐 때.
                System.out.println("Error!! " + e2.getMessage());
                System.out.println();
                continue;
            }
            
            parking.check(carNumber); // 차량 번호로 차량 관리
            System.out.println();
        }
        System.out.println("이주훈 퇴근합니다.");
     scanner.close();
    }
}
