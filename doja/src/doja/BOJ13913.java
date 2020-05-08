package doja;

import java.io.*;
import java.util.*;

public class BOJ13913 {

	static class Info {
		int pos;
		int cnt;

		Info(int pos, int cnt) {
			this.pos = pos;
			this.cnt = cnt;
		}
	}

	static int N, M;
	static int[] dx = { -1, 1 };
	static int[] visit = new int[100002];
	static Stack<Integer> st = new Stack<>();
	static Queue<Info> q = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		Arrays.fill(visit, -1);
		visit[N] = N;
		q.add(new Info(N, 0));
		BFS();
	}

	public static void BFS() {
		while (!q.isEmpty()) {
			Info cur = q.poll();
			if (cur.pos == M) {
				System.out.println(cur.cnt);
				st.add(M);
				while (M != N) {
					st.add(visit[M]);
					M = visit[M];
				}
				while (!st.isEmpty()) {
					System.out.print(st.pop() + " ");
				}
				break;
			}
			for (int i = 0; i < 3; i++) {
				int nx;
				if (i != 2) {
					nx = cur.pos + dx[i];
				} else {
					nx = cur.pos * 2;
				}
				if (nx >= 0 && nx <= 100000 && visit[nx] == -1) {
					q.add(new Info(nx, cur.cnt + 1));
					visit[nx] = cur.pos;
				}
			}
		}
	}
}
