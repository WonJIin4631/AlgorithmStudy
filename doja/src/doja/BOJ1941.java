package doja;

import java.io.*;
import java.util.*;

public class BOJ1941 {

	static char[][] map = new char[6][6];
	static boolean[][] visit;
	static boolean[] check;
	static int dx[] = { 0, 0, -1, 1 };
	static int dy[] = { -1, 1, 0, 0 };
	static int ans = 0;
	static class Info{
		int x;
		int y;
		Info(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 5; i++) {
			String s = br.readLine();
			for (int j = 0; j < 5; j++) {
				map[i][j] = s.charAt(j);
			}
		}
		
		for(int i=0;i<25;i++) {
			 visit = new boolean[6][6];
			 check = new boolean[25];
			DFS(i,1,0);
		}
		System.out.println(ans);
	}

	static void DFS(int idx, int cnt, int sTeam) {
		int x = idx % 5;
		int y = idx / 5;
		if (map[y][x] == 'S') {
			sTeam++;
		}
		visit[y][x] = true;
		check[idx] = true;
		if (cnt == 7) {
			if (sTeam >= 4) {
				BFS(x,y);
			}
		} else {
			for (int i = idx + 1; i < 25; i++) {
				if (check[i] == false) {
					DFS(i,cnt+1,sTeam);
				}
			}
		}
		visit[y][x] = false;
		check[idx] = false;
	}
	static void BFS(int x,int y) {
		Queue<Info> q= new LinkedList<>();
		Info st= new Info(x, y);
		q.add(st);
		boolean[][] cc = new boolean[6][6];
		int cnt=1;
		cc[y][x]=true;
		while (!q.isEmpty()) {
			Info cur =q.poll();
			for(int i=0;i<4;i++) {
				int nx= cur.x+dx[i];
				int ny =cur.y+dy[i];
				if(nx>=0&&ny>=0&&ny<5&&nx<5) {
					if(cc[ny][nx]==false) {
						if(visit[ny][nx]==true) {
							cnt++;
							cc[ny][nx]=true;
							Info nex = new Info(nx, ny);
							q.add(nex);
						}
					}
				}
			}
		}
		if(cnt==7) {
			ans++;
		}
	}
}
