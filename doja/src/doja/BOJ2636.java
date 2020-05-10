package doja;

import java.io.*;
import java.util.*;

public class BOJ2636 {

	static int[][] map = new int[105][105];
	static boolean[][] isOuter;
	static int N, M;
	static int chCnt = 0;
	static int dx[] = { 0, 0, -1, 1 };
	static int dy[] = { -1, 1, 0, 0 };

	static class Info {
		int x, y;

		Info(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());
		N = Integer.parseInt(tok.nextToken());
		M = Integer.parseInt(tok.nextToken());
		for (int i = 1; i <= N; i++) {
			tok = new StringTokenizer(br.readLine());
			for (int j = 1; j <= M; j++) {
				map[i][j] = Integer.parseInt(tok.nextToken());
				if (map[i][j] == 1)
					chCnt++;
			}
		}
		solve();
	}

	static void solve() {
		Queue<Info> q = new LinkedList<>();
		int time =0;
		int leftCh=0;
		while(chCnt!=0) {
			isOuter = new boolean[N+2][M+2];
			leftCh=chCnt;
			Info t= new Info(0,0);
			q.add(t);
			while(!q.isEmpty()) {
				Info cur= q.poll();
				for(int i=0;i<4;i++) {
					int nx = cur.x+dx[i];
					int ny = cur.y+dy[i];
					if(nx>=0&&nx<=M+1&&ny>=0&&ny<=N+1) {
						if(map[ny][nx]==0) {
							if(isOuter[ny][nx]==false) {
							isOuter[ny][nx]=true;
							Info nextPos= new Info(nx,ny);
							q.add(nextPos);
							}
						}
					}
				}
			}
			for(int i=1;i<=N;i++) {
				for(int j=1;j<=M;j++) {
					if(map[i][j]==1) {
						boolean flag =false;
						for(int k=0;k<4;k++) {
							int nx= j+dx[k];
							int ny = i+dy[k];
							if(isOuter[ny][nx]) {
								flag =true;
								break;
							}
						}
						if(flag) {
							map[i][j]=0;
							chCnt--;
						}
					}
				}
			}
			time++;
		}
		System.out.println(time);
		System.out.println(leftCh);
	}
}
