// Question : Given n villages with their populations and k clinics,
//            distribute the clinics so that every village gets at least one clinic
//            and the maximum patient load on any clinic is minimum.

// Approach : I use a Max Priority Queue based on the current load of
//            each village.Initially,
//            every village gets one clinic.For every extra clinic,
//            I take the village with the highest current load,
//            give it one more clinic,
//            recalculate its load,
//            and put it back into the priority queue.At the end,
//            the top of the queue is the minimum possible maximum load.

import java.util.*;

class ClinicAndVillages {

  static class Village {
    int population;
    int clinics;
    double load;

    Village(int population) {
      this.population = population;
      this.clinics = 1;
      this.load = population;
    }
  }

  static double minimumLoad(int[] population, int k) {
    PriorityQueue<Village> pq = new PriorityQueue<>((a, b) -> Double.compare(b.load, a.load));

    for (int p : population) {
      pq.add(new Village(p));
    }

    int extra = k - population.length;

    while (extra > 0) {
      Village v = pq.poll();

      v.clinics++;
      v.load = (double) v.population / v.clinics;

      pq.add(v);
      extra--;
    }

    return pq.peek().load;
  }

  public static void main(String[] args) {
    int[] population1 = {200, 20, 50};
    int k1 = 5;

    System.out.printf("%.2f\n", minimumLoad(population1, k1));
  }
}