import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Collections;

public class medianOfStream {

  static PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
  static PriorityQueue<Integer> minHeap = new PriorityQueue<>();

  static void insert(int num) {

    if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
      maxHeap.add(num);
    } else {
      minHeap.add(num);
    }

    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.add(maxHeap.poll());
    }

    if (minHeap.size() > maxHeap.size() + 1) {
      maxHeap.add(minHeap.poll());
    }
  }

  static double getMedian() {

    if (maxHeap.size() == minHeap.size()) {
      return (maxHeap.peek() + minHeap.peek()) / 2.0;
    }

    if (maxHeap.size() > minHeap.size()) {
      return maxHeap.peek();
    }

    return minHeap.peek();
  }

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    System.out.println("Enter numbers (type 'exit' to stop):");

    while (true) {

      String input = sc.next();

      if (input.equals("exit")) {
        break;
      }

      int num = Integer.parseInt(input);
      insert(num);
      System.out.printf("Current Median: %.2f%n", getMedian());
    }

    sc.close();
  }
}