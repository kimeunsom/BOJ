import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		int k=s.nextInt();
		int max0=0;
		int max1=0;
		int [][] arr = new int[2][6];
		for(int i=0; i<6; i++) {
			int dr = s.nextInt();
			
			if(dr==1 || dr==2) {
				arr[0][i] = 0;
			} else {
				arr[0][i] = 1; 
			}
			
			arr[1][i]=s.nextInt();
		}
		
		
		int index0=0;
		int index1=1;
		for(int i=0; i<3; i++) {
			max0=arr[1][0];
			if(max0<arr[1][2]) {
				max0=arr[1][2];
				index0=2;
			}
			if (max0<arr[1][4]) {
				max0=arr[1][4];
				index0=4;
			}
			
			max1=arr[1][1];
			if(max1<arr[1][3]) {
				max1=arr[1][3];
				index1=3;
			}
			if (max1<arr[1][5]) {
				max1=arr[1][5];
				index1=5;
			}
		}
		
		
		int aU=max0*max1;
		int aSub=0;
	
		
		index0+=3;
		index0%=6;
		int a=arr[1][index0];
		
		index1+=3;
		index1%=6;
		int b=arr[1][index1];
		
		aSub=a*b;
		
		System.out.println((aU-aSub)*k);
		
	}

}
