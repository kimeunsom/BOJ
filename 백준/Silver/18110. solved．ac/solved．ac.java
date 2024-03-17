import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		if(n==0) {
			System.out.println(0);
			return;
		}
		
		int [] a = new int [n];
		
		for(int i=0; i<n; i++) { 
			a[i]=Integer.parseInt(br.readLine()); 
		}
		
		Arrays.sort(a);
		
		
		//n의 15퍼센트를 반올림해 몇 명 제거해야하는지 구하기.
		float r = (float) (n*0.15);
		int temp=(int) (r*10%10);
		int num=(int) (n*0.15);
		
		if(temp>=5) {
			num++;
		}
		
		//평균 계산에서 제외할 수를 -1로 처리.
		for(int i=0; i<num; i++) {
			a[i]=-1;
			a[a.length-i-1]=-1;
		}
		
		int sum=0;
		for(int i=0; i<a.length; i++) {
			if(a[i]!=-1) {
				sum+=a[i];
			}
		}
		
		float avg = (float)sum/(n-num*2); 
		int ans = sum/(n-num*2);
		int c = (int) (avg*10%10);
		
		if(c>=5) {
			ans++;
		}
		
		System.out.println(ans);

		
	}

}
