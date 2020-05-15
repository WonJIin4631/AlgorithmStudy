package doja;

import java.io.*;
import java.util.*;

public class BOJ1938 {

	static int N;
	static int[][] map = new int[51][51];
	static boolean[][][] visit = new boolean[2][51][51];
	static int dx[]= {0,0,-1,1};
	static int dy[]= {-1,1,0,0};
	static int cx[]= {-1,0,1,-1,1,-1,0,1};
	static int cy[]= {-1,-1,-1,0,0,1,1,1};
	static class Info {
		int x;
		int y;
		int dir;
		//0은 가로 1은 세로
		Info(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}

	static Info stPos;
	static Info endPos;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine());
		N = Integer.parseInt(tok.nextToken());
		boolean sCheck=false;
		boolean eCheck=false;
		for(int i=0;i<N;i++) {
			String s = br.readLine();
			for(int j=0;j<N;j++) {
				if(s.charAt(j)=='B') {
					map[i][j]=0;
					if(sCheck) 
						continue;
					if(j==N-1) {
						stPos=new Info(j, i+1, 1);
					}
					else if(s.charAt(j+1)=='B') {
						stPos= new Info(j+1, i, 0);
					}
					else {
						stPos=new Info(j, i+1, 1);
					}
					sCheck=true;
				}
				else if(s.charAt(j)=='E') {
					map[i][j]=0;
					if(eCheck) 
						continue;
					if(j==N-1) {
						endPos=new Info(j, i+1, 1);
					}
					else if(s.charAt(j+1)=='E') {
						endPos=new Info(j+1, i, 0);
					}
					else {
						endPos=new Info(j, i+1, 1);
					}
					eCheck=true;
				}
				else {
					map[i][j]=s.charAt(j)-'0';
				}
			}
		}
		solve();
	}
	static void solve() {
		Queue<Info> q =new LinkedList<>();
		q.add(stPos);
		visit[stPos.dir][stPos.y][stPos.x]=true;
		int time=0;
		while(!q.isEmpty()) {
			int qsz= q.size();
			for(int t=0;t<qsz;t++) {
				Info cur =q.poll();
				int x= cur.x;
				int y= cur.y;
				if((cur.x==endPos.x)&&(cur.y==endPos.y)&&(cur.dir==endPos.dir)) {
					System.out.println(time);
					return;
				}
				if(cur.dir==0) {
					for(int i=0;i<4;i++) {
						int nx= x+dx[i];
						int ny= y+dy[i];
						if(nx-1>=0&&nx+1<N&&ny>=0&&ny<N) {
							if((map[ny][nx-1]==1) ||(map[ny][nx]==1)||(map[ny][nx+1]==1))
								continue;
							if(visit[0][ny][nx])
								continue;
							visit[0][ny][nx]=true;
							Info nex= new Info(nx, ny,0);
							q.add(nex);
						}
					}
					if(x>=0&&x<N&&y-1>=0&&y+1<N) {
						boolean flag=false;
						for(int i=0;i<8;i++) {
							int nx=x+cx[i];
							int ny=y+cy[i];
							if(map[ny][nx]==1) {
								flag =true;
								break;
							}
						}
						if(flag)
							continue;
						if(visit[1][y][x])
							continue;
						visit[1][y][x]=true;
						Info nex= new Info(x, y,1);
						q.add(nex);
					}
				}
				else {
					for(int i=0;i<4;i++) {
						int nx= x+dx[i];
						int ny= y+dy[i];
						if(nx>=0&&nx<N&&ny-1>=0&&ny+1<N) {
							if((map[ny-1][nx]==1) ||(map[ny][nx]==1)||(map[ny+1][nx]==1))
								continue;
							if(visit[1][ny][nx])
								continue;
							visit[1][ny][nx]=true;
							Info nex= new Info(nx, ny,1);
							q.add(nex);
						}
					}
					if(x-1>=0&&x+1<N&&y>=0&&y<N) {
						boolean flag=false;
						for(int i=0;i<8;i++) {
							int nx=x+cx[i];
							int ny=y+cy[i];
							if(map[ny][nx]==1) {
								flag =true;
								break;
							}
						}
						if(flag)
							continue;
						if(visit[0][y][x])
							continue;
						visit[0][y][x]=true;
						Info nex= new Info(x, y,0);
						q.add(nex);
					}
				}
			}
			time++;
		}
		System.out.println(0);
	}
	
}
