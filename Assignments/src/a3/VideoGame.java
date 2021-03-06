package a3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class VideoGame {
	private static class Edge{
		public int start, end, change;
		Edge(int u, int v, int c) {
			start = u;
			end = v; 
			change = c;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			int N, M, K;
			List<Edge> edges = new ArrayList<>();
			N = sc.nextInt();
			M = sc.nextInt();
			K = sc.nextInt();
			int[] dif = new int[N];
			// Initialize difference array
			dif[0] = K;
			for (int i = 1; i < N; i++)
				dif[i] = Integer.MIN_VALUE;
			// Read in edges
			for (int m = 0; m < M; m++)
				edges.add(new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt())); // -1 because counting starts at 0, dammit
			// OK, have everything in memory now. Do Bellman-Ford.
			for (int n = 0; n < N-1; n++)
				for (Edge e : edges)
					if (dif[e.start] != Integer.MIN_VALUE && dif[e.start] + e.change > dif[e.end]) // maximizing health, so >
						dif[e.end] = dif[e.start] + e.change;
			// Relaxing (or flexing in this case, idk) done, now find answer 
			if (dif[N-1] == Integer.MIN_VALUE) // Nth room untouched, so unreachable from start.
				System.out.println("-1");
			else {
				boolean flex = false;
				for (int n = 0; n < N; n++)
					for (Edge e : edges)
			           if (dif[e.start] + e.change > dif[e.end])
			        	   flex = true;
				if (flex) // If we further flexed, we have a positive loop.
					System.out.println("Infinity");
				else // Healthy level, return the max health at this point.
					System.out.println(dif[N-1]);
			}
		}
		sc.close();
	}
}
