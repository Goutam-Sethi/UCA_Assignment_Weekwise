import java.util.ArrayList;

class SearchInLL {
  static class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
      this.val = val;
      this.next = null;
    }
  }

  public static ListNode createList(int[] arr) {
    if (arr.length == 0) return null;

    ListNode head = new ListNode(arr[0]);
    ListNode temp = head;

    for (int i = 1; i < arr.length; i++) {
      temp.next = new ListNode(arr[i]);
      temp = temp.next;
    }

    return head;
  }  

  static int[] findLPS (ArrayList<Integer> pattern) {
    int m = pattern.size();
    int length = 0, i = 1;

    int[] lps = new int[m];
    lps[0] = 0;

    while (i < m) {
      if (pattern.get(i) == pattern.get(length)) {
        length++;
        lps[i] = length;
        i++;
      }
      else {
        if (length == 0) {
          lps[i] = 0;
          i++;
        }
        else {
          length = lps[length - 1];
        }
      }
    }

    return lps;
  }

  static boolean KMP (ListNode head, ArrayList<Integer> pattern) {
    ListNode ite = head;
    int m = pattern.size();
    int j = 0;
    int[] lps = findLPS(pattern);

    while (ite != null) {

      if (ite.val == pattern.get(j)) {
        ite = ite.next;
        j++;
        
        if (j == m) 
          return true;
      }
      else {
        if (j == 0)
          ite = ite.next;
        else 
          j = lps[j-1];
      }
    }

    return false;
  }

  static boolean searchLL (ListNode head1, ListNode head2) {
    ListNode ite = head1;
    ArrayList<Integer> pattern = new ArrayList<>();

    while (ite != null) {
      pattern.add(ite.val);
      ite = ite.next;
    }

    return KMP(head2, pattern);
  }

  public static void main(String[] args) {
    int[] list1 = {1, 2, 3, 4};
    ListNode head1 = createList(list1);

    int[] list2 = {1, 2, 2, 1, 2, 3};
    ListNode head2 = createList(list2);

    boolean ans = searchLL(head1, head2);

    if (ans) {
      System.out.println("Yes");
    } else {
      System.out.println("No");
    }
  }
}