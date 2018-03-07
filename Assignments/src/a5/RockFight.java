package a5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class RockFight {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());
			
			int[] r = Arrays.stream(br.readLine().split(" "))
				    .mapToInt(Integer::parseInt)
				    .toArray();
			Arrays.sort(r);
			
			int[] b = Arrays.stream(br.readLine().split(" "))
				    .mapToInt(Integer::parseInt)
				    .toArray();
			Arrays.sort(b);
			
			int sum = 0, top = N-1, bot = 0;
			for (int n = N-1; n >= 0; n--)
				if (r[top] <= b[n])
					sum += r[bot++];
				else
					top--;
			
			System.out.println(sum);
		}
	}
}