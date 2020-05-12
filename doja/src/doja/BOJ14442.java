package doja;

import java.io.*;
import java.util.*;

public class BOJ14442 {

	static int N, M, K;
	static char[][] map= new char[1001][1001];
	static int[] dx= {0,0,-1,1};
	static int[] dy= {-1,1,0,0};
	static boolean[][][] visit;
	static class Info implements Comparable<Info>{
		int y;
		int x;
		int broken;
		int cnt;
		Info(int x,int y,int cnt,int broken) {
			this.x=x;
			this.y=y;
			this.cnt=cnt;
			this.broken =broken;
		}
		@Override
		public int compareTo(Info target) {
			if(this.broken>target.broken) {
				return 1;
			}
			else if(this.broken<target.broken) {
			return 0;
			}
			return 0;
		}
		
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());

		N = Integer.parseInt(tok.nextToken());
		M = Integer.parseInt(tok.nextToken());
		K = Integer.parseInt(tok.nextToken());
		visit =new boolean[N][M][11];
		for(int i=0;i<N;i++) {
			String s = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] =s.charAt(j);
			}			
		}
		BFS();
	
	}
	static void BFS() {
		visit[0][0][0]=true;
		Info st= new Info(0, 0,1,0);
		Queue<Info> q= new LinkedList<>();
		q.add(st);
		
		while(!q.isEmpty()) {
			Info cur = q.poll();
			if(cur.x==M-1&&cur.y==N-1) {
				System.out.println(cur.cnt);
				return;
			}
			for(int i=0;i<4;i++) {
				int nx = cur.x+dx[i];
				int ny = cur.y+dy[i];
				if(nx>=0&&nx<M&&ny>=0&&ny<N) {
					if(map[ny][nx]=='1') {
						if(cur.broken==K)
							continue;
						if(!visit[ny][nx][cur.broken+1]) {
							visit[ny][nx][cur.broken+1]=true;
							Info ne= new Info(nx, ny, cur.cnt+1, cur.broken+1);
							q.add(ne);
						}
					}
					else {
						if(!visit[ny][nx][cur.broken]) {
							visit[ny][nx][cur.broken]=true;
							Info ne= new Info(nx, ny, cur.cnt+1, cur.broken);
							q.add(ne);
						}
					}
				}
			}
		}
		System.out.println(-1);
	}

}
