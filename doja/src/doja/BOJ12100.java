package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ12100 {

	static int N;
	static int[][] map;
	static int[][] temp;
	static int ans=0;
	static void solve(int cnt,int val, int[][] m) {
		if(cnt==5) {
			ans=Math.max(val, ans);
			return;
		}
		Deque<Integer> dq = new LinkedList<>();
		temp = new int[N + 1][N + 1];
		//left
		int maxVal=0;
		for (int i = 0; i < N; i++) {
			// 수를 모두 덱에넣기
			for (int j = 0; j < N; j++) {
				if(m[i][j]==0)
					continue;
				dq.addLast(m[i][j]);
			}
			int idx = 0;
			while (!dq.isEmpty()) {
				int cur = dq.pollFirst();
				if (!dq.isEmpty()) {
					if (cur == dq.peekFirst()) {
						dq.pollFirst();
						maxVal=Math.max(maxVal, cur*2);
						temp[i][idx++] = cur * 2;
					} else {
						maxVal=Math.max(maxVal, cur);
						temp[i][idx++]=cur;
					}
				}
				else {
					maxVal=Math.max(maxVal, cur);
					temp[i][idx++]=cur;
				};
			}
		}
		solve(cnt+1,maxVal,temp);
		//right
		temp = new int[N + 1][N + 1];
		maxVal=0;
		for (int i = 0; i < N; i++) {
			// 수를 모두 덱에넣기
			for (int j = N-1; j >=0 ; j--) {
				if(m[i][j]==0)
					continue;
				dq.addLast(m[i][j]);
			}
			int idx = N-1;
			while (!dq.isEmpty()) {
				int cur = dq.pollFirst();
				if (!dq.isEmpty()) {
					if (cur == dq.peekFirst()) {
						dq.pollFirst();
						maxVal=Math.max(maxVal, cur*2);
						temp[i][idx--] = cur * 2;
					} else {
						maxVal=Math.max(maxVal, cur);
						temp[i][idx--]=cur;
					}
				}
				else {
					maxVal=Math.max(maxVal, cur);
					temp[i][idx--]=cur;
				}
			}
		}
		solve(cnt+1,maxVal,temp);
		//up
		temp = new int[N + 1][N + 1];
		maxVal=0;
		for (int i = 0; i < N; i++) {
			// 수를 모두 덱에넣기
			for (int j = 0; j <N ; j++) {
				if(m[j][i]==0)
					continue;
				dq.addLast(m[j][i]);
			}
			int idx = 0;
			while (!dq.isEmpty()) {
				int cur = dq.pollFirst();
				if (!dq.isEmpty()) {
					if (cur == dq.peekFirst()) {
						dq.pollFirst();
						maxVal=Math.max(maxVal, cur*2);
						temp[idx++][i] = cur * 2;
					} else {
						maxVal=Math.max(maxVal, cur);
						temp[idx++][i]=cur;
					}
				}
				else {
					maxVal=Math.max(maxVal, cur);
					temp[idx++][i]=cur;
				}
			}
		}
		solve(cnt+1,maxVal,temp);
		//down
		temp = new int[N + 1][N + 1];
		maxVal=0;
		for (int i = 0; i < N; i++) {
			// 수를 모두 덱에넣기
			for (int j = N-1; j >=0 ; j--) {
				if(m[j][i]==0)
					continue;
				dq.addLast(m[j][i]);
			}
			int idx = N-1;
			while (!dq.isEmpty()) {
				int cur = dq.pollFirst();
				if (!dq.isEmpty()) {
					if (cur == dq.peekFirst()) {
						dq.pollFirst();
						maxVal=Math.max(maxVal, cur*2);
						temp[idx--][i] = cur * 2;
					} else {
						maxVal=Math.max(maxVal, cur);
						temp[idx--][i]=cur;
					}
				}
				else {
					maxVal=Math.max(maxVal, cur);
					temp[idx--][i]=cur;
				}
			}
		}
		solve(cnt+1,maxVal,temp);
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N + 1][N + 1];
		for (int i = 0; i < N; i++) {
			StringTokenizer tok = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(tok.nextToken());
			}
		}
		solve(0,0,map);
		System.out.println(ans);
	}

}
