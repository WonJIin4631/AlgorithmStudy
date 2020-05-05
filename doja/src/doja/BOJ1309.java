package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1309 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int N = Integer.parseInt(s);
		int[] dp = new int[1000001];
		dp[0] = 1;
		dp[1] = 3;
		for (int i = 2; i <= N; i++) {
			dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
		}
		System.out.println(dp[N]);
	}
}
