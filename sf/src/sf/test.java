package sf;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class test {
    /*
     * Complete the function below.
     */
    static int shortestPath(String[] relationships, String client1, String client2) {
        // Write your code here.
        HashMap<String, Node> nodes = new HashMap<>();
        for (String str : relationships) {
        	String split[] = str.split(":");
        	if (!nodes.containsKey(split[0])) {
        		Node n = new Node();
        		n.children.add(split[1]);
        		nodes.put(split[0], n);
        	} else
        		nodes.get(split[0]).children.add(split[1]);
        }
        // OK got our graph, now let's go through it. BFS.
        LinkedList<String> q = new LinkedList<>();
        q.add(client1);
        nodes.get(client1).depth=0;
        while (q.size() > 0) {
        	Node n = nodes.get(q.getFirst());
        	n.visited = true;
        	for (String s : n.children) {
        		Node c_n = nodes.get(s);
        		if (c_n == null)
        			c_n = new Node();
        		if (!c_n.visited) {
	        		c_n.depth = n.depth+1;
	        		if (s.equals(client2))
	        			return c_n.depth;
	        		q.add(s);
        		}
        	}
        	q.remove();
        }
        return -1;
    }
    private static class Node {
    	List<String> children = new ArrayList<>();
    	boolean visited = false;
    	int depth = Integer.MAX_VALUE;
    }
    
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int relationshipsSize = Integer.parseInt(scan.nextLine().trim());

        String[] relationships = new String[relationshipsSize];

        for (int relationshipsItr = 0; relationshipsItr < relationshipsSize; relationshipsItr++) {
            String relationshipsItem = scan.nextLine();
            relationships[relationshipsItr] = relationshipsItem;

        }

        String client1 = scan.nextLine();

        String client2 = scan.nextLine();

        int res = shortestPath(relationships, client1, client2);

        bw.write(String.valueOf(res));
        bw.newLine();

        bw.close();
    }
}

