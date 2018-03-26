package a7;

import java.util.Arrays;
import java.util.Scanner;

public class p4D {
	private static class Envelope implements Comparable<Envelope> {
		int w, h, max, prev, n;
		Envelope(int width, int height, int number) {
			w = width;
			h = height;
			n = number;
		}
		public boolean fitsIn(Envelope a) { return a.w > w && a.h > h; }
		@Override
		public int compareTo(Envelope arg0) { return w-arg0.w; }
		@Override
		public String toString() { return n+": <"+max+"> ("+w+", "+h+")"; }
	}
	
	public static void main(String[] args) {
	// READ IN
	    int N, W, H;
	    Scanner in = new Scanner(System.in);
	    N = in.nextInt();
	    W = in.nextInt();
	    H = in.nextInt();
	    Envelope[] envelopes = new Envelope[N];
	    for (int i = 0; i < N; i++) { // read in envelopes and set max to 1 if they can fit the card
	    	envelopes[i] = new Envelope(in.nextInt(), in.nextInt(), i+1);
	    	envelopes[i].max = envelopes[i].w > W && envelopes[i].h > H ? 1 : 0;
	    }
	    in.close();
	// DO LOGIC
	    Arrays.sort(envelopes); // sort according to width
	    int maxIndx = 0;
	    for (int i = 0; i < N; i++) {
	    	for (int j = 0; j < i; j++) {
	    		if (envelopes[j].fitsIn(envelopes[i]) && envelopes[j].max >= envelopes[i].max && envelopes[j].max > 0) {
	    			envelopes[i].max = envelopes[j].max + 1;
	    			envelopes[i].prev = j;
	    		}
	    	}
	    	if (envelopes[i].max > envelopes[maxIndx].max)
	    		maxIndx = i;
	    }
	    // Get path (must read it backwards into an array from the prevs)
	    int current = maxIndx, maxVal = envelopes[maxIndx].max;
	    int[] path = new int[maxVal];
	    for (int i = maxVal-1; i >= 0; i--) {
	    	path[i] = envelopes[current].n;
	    	current = envelopes[current].prev;
	    }
	    // Print results
    	System.out.println(maxVal);
	    if (maxVal > 0)
		    for (int i = 0; i < path.length; i++)
		    	System.out.print(path[i]+" ");
	}

}
