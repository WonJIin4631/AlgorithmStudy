package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ15653 {

	static class BInfo {
		int ry, rx;
		int bx, by;

		BInfo(int rx, int ry, int bx, int by) {
			this.rx = rx;
			this.ry = ry;
			this.bx = bx;
			this.by = by;
		}
	}

	static int N, M;
	static char[][] map = new char[11][11];
	static int rx, ry;
	static int bx, by;
	static int gx, gy;
	static int dx[] = { 0, 0, -1, 1 };
	static int dy[] = { -1, 1, 0, 0 };
	static Queue<BInfo> q;
	static int ans = 987654321;
	static boolean[][][][] visit = new boolean[11][11][11][11];

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());	
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = s.charAt(j);
				if (s.charAt(j) == 'B') {
					map[i][j] = '.';
					bx = j;
					by = i;
				} else if (s.charAt(j) == 'R') {
					map[i][j] = '.';
					rx = j;
					ry = i;
				} else if (s.charAt(j) == 'O') {
					gx = j;
					gy = i;
				}
			}
		}
		visit[ry][rx][by][bx] = true;
		BInfo info = new BInfo(rx, ry, bx, by);
		q = new LinkedList<>();
		q.add(info);
		BFS();
		if(ans==987654321)
			System.out.println(-1);
		else
			System.out.println(ans);
	}

	static void BFS() {
		int time = 0;
		int qsz;
		while (!q.isEmpty()) {
			qsz=q.size();
			for (int m = 0; m < qsz; m++) {
				BInfo cur = q.poll();
				if (cur.rx == gx && cur.ry == gy) {
					if (cur.bx != gx || cur.by != gy) {
						ans = time;
						return;
					}
				}
				for (int i = 0; i < 4; i++) {
					int crx = cur.rx;
					int cry = cur.ry;
					int cbx = cur.bx;
					int cby = cur.by;
					int cnt[] = new int[2];
					boolean flag[]=new boolean[2]; 
					while (true) {
						if (map[cry + dy[i]][crx + dx[i]] == '#')
							break;
						cnt[0]++;
						cry += dy[i];
						crx += dx[i];
						if (map[cry][crx] == 'O') {
							flag[0]=true;
							break;
						}
					}
					while (true) {
						if (map[cby + dy[i]][cbx + dx[i]] == '#')
							break;
						cnt[1]++;
						cby += dy[i];
						cbx += dx[i];
						if (map[cby][cbx] == 'O') {
							flag[1]=true;
							break;
						}
					}
					if (crx == cbx && cry == cby) {
						if (cnt[0] < cnt[1]) {
							cbx -= dx[i];
							cby -= dy[i];
						} else {
							crx -= dx[i];
							cry -= dy[i];
						}
					}
					if(flag[1])
						continue;
					if (!visit[cry][crx][cby][cbx]) {
						//System.out.println("push"+crx+ " "+cry+" "+cbx+" "+cby);
						visit[cry][crx][cby][cbx] = true;
						BInfo nInfo = new BInfo(crx, cry, cbx, cby);
						q.add(nInfo);
					}
				}
			}
			time++;
		}

	}
}
