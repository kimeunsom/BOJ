import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int wheelNumber = 0;
    public static char[] luckyWheel;
    public static boolean[] alphabets = new boolean[26];

    // 0 1 2 3 4 5 6 7
    // N O H R V A T I
    public static String turnLuckyWheel(int n, int s, char alphabet) {
        wheelNumber = (wheelNumber + s) % n;

        // 유효하지 않은 경우 (2가지)
        // 1. 다른 자리 같은 알파벳의 중복일 경우
        if (luckyWheel[wheelNumber] == '?' && alphabets[alphabet - 'A'])
            return "!";
        // 2. 같은 자리 다른 알파벳의 충돌일 경우
        if (luckyWheel[wheelNumber] != '?' && luckyWheel[wheelNumber] != alphabet)
            return "!";

        luckyWheel[wheelNumber] = alphabet;
        alphabets[alphabet - 'A'] = true;
        return new String(luckyWheel);
    }

    public static void printLuckyWheel(String turnResult, int alphabet, int n) {
        StringBuilder sb = new StringBuilder();
        int last = turnResult.indexOf(alphabet);
        // last로부터 거꾸로인 순서로
        for (int i = last + n; i > last; i--) {
            sb.append(turnResult.charAt(i % n));
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());   // n: 바퀴의 칸의 수
        int k = Integer.parseInt(st.nextToken());   // k: 바퀴를 돌리는 횟수

        luckyWheel = new char[n];
        Arrays.fill(luckyWheel, '?');

        char alphabet = 0;
        String turnResult = "";

        while (k-- > 0) {
            st = new StringTokenizer(br.readLine());

            int s = Integer.parseInt(st.nextToken());
            alphabet = st.nextToken().charAt(0);

            turnResult = turnLuckyWheel(n, s, alphabet);

            if (turnResult.equals("!")) {
                System.out.println(turnResult);
                return;
            }
        }

        printLuckyWheel(turnResult, alphabet, n);
    }
}