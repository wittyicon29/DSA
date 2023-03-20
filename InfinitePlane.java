import java.util.*;

public class InfinitePlane {
    
    static class Point {
        int x;
        int y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public boolean equals(Object obj) {
            if (obj instanceof Point) {
                Point other = (Point) obj;
                return this.x == other.x && this.y == other.y;
            }
            return false;
        }
        
        public int hashCode() {
            return Objects.hash(this.x, this.y);
        }
    }
    
    public static int minMoves(int a, int b, int c, int d) {
        Queue<Point> queue = new LinkedList<>();
        Map<Point, Integer> distances = new HashMap<>();
        Point start = new Point(a, b);
        Point end = new Point(c, d);
        queue.offer(start);
        distances.put(start, 0);
        while (!queue.isEmpty()) {
            Point current = queue.poll();
            int x = current.x;
            int y = current.y;
            int dist = distances.get(current);
            if (current.equals(end)) {
                return dist;
            }
            Point rightUp = new Point(x+1, y+1);
            Point left = new Point(x-1, y);
            if (!distances.containsKey(rightUp)) {
                queue.offer(rightUp);
                distances.put(rightUp, dist+1);
            }
            if (!distances.containsKey(left)) {
                queue.offer(left);
                distances.put(left, dist+1);
            }
        }
        return -1; // unreachable
    }
    
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
         int t = sc.nextInt();
         while (t-- > 0) {
             int a = sc.nextInt();
             int b = sc.nextInt();
             int c = sc.nextInt();
             int d = sc.nextInt();
             System.out.println(minMoves(a, b, c, d));
         }
    }
}
