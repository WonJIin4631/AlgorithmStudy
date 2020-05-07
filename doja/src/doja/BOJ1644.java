package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1644 {

	static boolean[] sosu = new boolean[4000001];
	static int N;
	static int ans = 0;
	static int[] sosuList = new int[300000];
	static int cnt = 0;
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		getSosu(N);
		solve();
		System.out.println(ans);
	}

	static void getSosu(int n) {
		for (int i = 2; i <= n; i++) {
			if (sosu[i])
				continue;
			sosuList[cnt++]=i;
			for (int j = i + i; j <= n; j += i) {
				sosu[j] = true;
			}
		}
	}
	static void solve() {
		int st=0, e=0;
		int sum=0;
		while(e<=cnt) {
			if(sum<N) {
				sum+=sosuList[e++];
				continue;
			}
			if(sum==N) {
				ans++;
			}
			sum-=sosuList[st++];
		}
	}

}
