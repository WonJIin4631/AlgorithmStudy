package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ2003 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());
		int N, M;
		N = Integer.parseInt(tok.nextToken());
		M = Integer.parseInt(tok.nextToken());
		int[] list = new int[10001];
		tok = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			list[i] = Integer.parseInt(tok.nextToken());
		}
		int st = 0, end = 0;
		int sum = list[0];
		int ans = 0;
		while (true) {
			if (sum == M)
				ans++;
			if (st == N)
				break;
			if (sum + list[end+1] > M||end==N-1) {
				sum -= list[st];
				st++;
			} else if (sum + list[end+1] <= M) {
				if (end < N) {
					end++;
					sum += list[end];
				}
			}
		}
		System.out.println(ans);
	}

}
