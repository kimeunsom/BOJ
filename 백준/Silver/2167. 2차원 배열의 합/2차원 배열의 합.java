import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int n=s.nextInt();
		int m=s.nextInt();
		
		int [][] a = new int [n][m];
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				a[i][j]=s.nextInt();
			}
		}
		
		int t=s.nextInt();
		
		
		
		int sum=0;
		int x1=0;
		int x2=0;
		int y1=0;
		int y2=0;
		while(t>0) {
			
			x1=s.nextInt()-1;
			y1=s.nextInt()-1;
			x2=s.nextInt()-1;
			y2=s.nextInt()-1;
			
			for(int i=x1; i<=x2; i++) {
				for(int j=y1; j<=y2; j++) {
					sum+=a[i][j];
				}
			}
			
			
			System.out.println(sum);
			
			t--;
			sum=0;
		}
		
	}

}
