package a3;

import java.util.Scanner;

public class p598D {

	private static int N, M;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K;
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		sc.nextLine();
		boolean[][] g = new boolean[N][M];
		//System.out.println(N + " " + M + " " + K + " " + sc.next());
		for (int n = 0; n < N; n++) {
			String s = sc.nextLine();
//			System.out.println(s);
			for (int m = 0; m < M; m++) {
				g[n][m] = s.charAt(m)=='*';
			}
		}
		for (int k = 0; k < K; k++) {
			int x, y;
			x = sc.nextInt()-1;
			y = sc.nextInt()-1;
//			System.out.println(x+" "+y);
			boolean[][] v = new boolean[N][M];
			System.out.println(search(x, y, g, v));
		}
		sc.close();
	}
	
	private static int search(int x, int y, boolean[][] g, boolean[][] v) {
		if (g[x][y])
			return 1;
		else if (v[x][y] || x < 0 || y < 0 || x >= N || y >= M)
			return 0;
		else {
			v[x][y] = true;
			return search(x-1, y, g, v)+search(x+1, y, g, v)+search(x, y-1, g, v)+search(x, y+1, g, v);
		}
	}

}