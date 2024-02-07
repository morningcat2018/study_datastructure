import java.util.PriorityQueue;

public class KthLargest {

    private final PriorityQueue<Integer> q;
    private final int k;
    public KthLargest(int k, int[] a){
        this.q = new PriorityQueue<>();
        this.k = k;
        for (int n:a){
            add(n);
        }   
    }

    public void add (int n){
        if (q.size()<k)
            q.offer(n);
        else if(q.peek()<n){
            q.poll();
            q.offer(n);

        }
    }

    public int getTop(){
        return q.poll();
    }

    public int getSize(){
        return q.size();
    }

    public static void main(String[] args){
        int[] a = {23,4,123,567};
        KthLargest kl = new KthLargest(3, a);

        while (kl.getSize()>0) {
            System.out.println(kl.getTop());
        }
        
    }
    
}
