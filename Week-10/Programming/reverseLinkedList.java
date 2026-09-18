class reverseLinkedList {

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

  public static void printList(ListNode head) {
    ListNode temp = head;

    while (temp != null) {
      System.out.print(temp.val + " -> ");
      temp = temp.next;
    }

    System.out.println("null");
  }

  public static ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;

    ListNode newHead = reverseList(head.next);

    head.next.next = head;
    head.next = null;

    return newHead;
  }

  public static void main(String[] args) {
    int[] arr = {10, 20, 30, 40, 50};

    ListNode head = createList(arr);

    head = reverseList(head);

    printList(head);
  }
}