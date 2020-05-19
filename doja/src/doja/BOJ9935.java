package doja;

import java.io.*;
import java.util.*;

public class BOJ9935 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Character> st = new Stack<>();
		String input = br.readLine();
		String del = br.readLine();
		for (int i = input.length() - 1; i >= 0; i--) {
			boolean flag = false;
			char c = input.charAt(i);
			st.push(c);
			if (c == del.charAt(0) && st.size() >= del.length()) {
				flag = true;
				for (int j = 0; j < del.length(); j++) {
					if (del.charAt(j) != st.get(st.size() - 1 - j)) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int k = 0; k < del.length(); k++) {
						st.pop();
					}
				}
			}
		}
		StringBuffer sb = new StringBuffer();
		if (st.isEmpty()) {
			System.out.println("FRULA");
		} else {
			for (int i = st.size() - 1; i >= 0; i--) {
				sb.append(st.get(i));
			}
		}
		System.out.println(sb);
	}
}
