package doja;
import java.util.*;
import java.io.*;
public class BOJ1113 {
	static int N,M;
	static int[][] map= new int[55][55];
	static int maxH=0;
	static int[] dx = {0,0,-1,1};
	static int[] dy = {-1,1,0,0};
	static int ans=0;
	static class Info{
		int x;
		int y;
		public Info(int x,int y) {
			this.x=x;
			this.y=y;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());
		N=Integer.parseInt(tok.nextToken());
		M=Integer.parseInt(tok.nextToken());
		for(int i=1;i<=N;i++) {
			String s= br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j+1]=s.charAt(j)-'0';
				if(maxH<map[i][j]){
					maxH=map[i][j];
				}
			}
		}
		for(int h=2;h<=maxH;h++) {
			BFS(h);
			for(int i=1;i<=N;i++) {
				for(int j=1;j<=M;j++) {
					if(map[i][j]<h) {
						ans+=1;
						map[i][j]+=1;
					}
				}
			}
		}
		System.out.println(ans);
	}
	static void BFS(int h) {
		Queue<Info> q=new LinkedList<>();
		Info st =new Info(0, 0);
		map[0][0]=h;
		q.add(st);
		while(!q.isEmpty()) {
			Info cur =q.poll();
			for(int i=0;i<4;i++) {
				int nx= cur.x+dx[i];
				int ny = cur.y+dy[i];
				if(nx<0||ny<0||nx>M+1||ny>N+1) {
					continue;
				}
				if(map[ny][nx]<h) {
					map[ny][nx]=h;
					Info nex = new Info(nx, ny);
					q.add(nex);
				}
			}
		}
	}
}
