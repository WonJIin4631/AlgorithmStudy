package doja;

import java.io.*;
import java.util.*;

public class BOJ1722 {
	static int N;
	static int[] arrList = new int[21];
	static long[] dp = new long[21];
	static boolean[] check = new boolean[21];

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		dp[0] = 1;
		for (int i = 1; i <= 20; i++) {
			dp[i] = dp[i - 1] * i;
		}
		StringTokenizer tok = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(tok.nextToken());
		if (c == 1) {
			long mCnt = Long.parseLong(tok.nextToken());
			for (int i = 0; i < N; i++) {
				for (int j = 1; j <= N; j++) {
					if (check[j])
						continue;
					if (dp[N - i - 1] < mCnt) {
						mCnt -= dp[N - i - 1];
					} else {
						arrList[i] = j;
						check[j] = true;
						break;
					}
				}
			}
			for (int i = 0; i < N; i++) {
				System.out.print(arrList[i] + " ");
			}
			System.out.println();
		} else {
			for (int i = 0; i < N; i++) {
				arrList[i] = Integer.parseInt(tok.nextToken());
			}
			long ans = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 1; j < arrList[i]; j++) {
					if (!check[j])
						ans += dp[N - i - 1];
				}
				check[arrList[i]] = true;
			}
			System.out.println(ans + 1);
		}

	}

}
