import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();


        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken()); 
        int K = Integer.parseInt(st.nextToken()); 


        char[] arr = new char[N];
        Arrays.fill(arr, '?'); 

        int idx = 0; 


        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int S = Integer.parseInt(st.nextToken()); 
            char c = st.nextToken().charAt(0); 


            idx = (idx - S % N + N) % N; 


            if (arr[idx] != '?' && arr[idx] != c) {
                System.out.println("!");
                return;
            }

            arr[idx] = c; 
        }


        boolean[] used = new boolean[26]; 
        for (int i = 0; i < N; i++) {
            if (arr[i] != '?') {
                int alphaIndex = arr[i] - 'A';
                if (used[alphaIndex]) { 
                    System.out.println("!");
                    return;
                }
                used[alphaIndex] = true; 
            }
        }


        for (int i = 0; i < N; i++) {
            sb.append(arr[(idx + i) % N]); 
        }

        System.out.println(sb.toString()); 
    }
}