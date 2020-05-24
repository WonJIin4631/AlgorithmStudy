package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1010 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		int N;
		N= Integer.parseInt(br.readLine());
		long dp[][] =new long[31][31];
		for(int i=1;i<30;i++) {
			dp[i][i]=1;
			dp[1][i]=i;
		}
		for(int i=2;i<30;i++) {
			for(int j=i+1;j<30;j++) {
				for(int k=1;k<j;k++) {
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
		StringTokenizer tok;
		for(int i=0;i<N;i++) {
			int a,b;
			tok = new StringTokenizer(br.readLine());
			a=Integer.parseInt(tok.nextToken());
			b= Integer.parseInt(tok.nextToken());
			System.out.println(dp[a][b]);
		}
	}

}
