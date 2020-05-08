package doja;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BOJ10799 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		Stack<Integer> st = new Stack<Integer>();
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				if(i+1<s.length()) {
					if(s.charAt(i+1)==')') {
					ans+=st.size();
					i++;
					continue;
					}
				}
				st.push(0);
				ans+=1;
			}
			else {
				st.pop();
			}
		}
		System.out.println(ans);
	}
}
