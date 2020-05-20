package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1213 {

	static int[] alpaCnt = new int[27];
	static char[] alpa = new char[27];

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		for (int i = 0; i < s.length(); i++) {
			alpaCnt[s.charAt(i) - 'A']++;
		}
		int check = 0;
		int oddIdx = 0;
		for (int i = 0; i < 26; i++) {
			alpa[i] = (char) ('A'+ i);
			if ((alpaCnt[i] % 2) != 0) {
				check++;
				oddIdx = i;
			}
		}
		StringBuffer ans = new StringBuffer();
		boolean flag = false;
		if (check >= 2) {
			flag = true;
		}
		if (!flag) {
			if (s.length() % 2 == 0) {
				if (check != 0)
					flag = true;
			} else {
				if (check != 1)
					flag = true;
				else {
					System.out.println(alpa[oddIdx]);
					ans.append(alpa[oddIdx]);
					alpaCnt[oddIdx]--;
				}
			}
			if (!flag) {
				int st = 26;
				while (true) {
					if (st == -1)
						break;
					if (alpaCnt[st] == 0) {
						st--;
					} else {
						ans.insert(0, alpa[st]);
						ans.append(alpa[st]);
						alpaCnt[st] -= 2;
					}
				}
			}
		}
		if (flag) {
			System.out.println("I'm Sorry Hansoo");
		}
		else {
			System.out.println(ans);
		}
	}

}
