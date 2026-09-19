class IntersectionOfLinkedList {

  static class ListNode {
    int val;
    ListNode next;

    ListNode() {
      this.val = -1;
      this.next = null;
    }

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

  public static ListNode intersectionOfList(ListNode head1, ListNode head2) {
    ListNode dummy = new ListNode();
    ListNode curr = dummy;

    ListNode ptr1 = head1;
    ListNode ptr2 = head2;

    while (ptr1 != null && ptr2 != null) {
      if (ptr1.val == ptr2.val) {
        curr.next = new ListNode(ptr1.val);
        curr = curr.next;
        ptr1 = ptr1.next;
        ptr2 = ptr2.next;
      }

      else if (ptr1.val < ptr2.val) {
        ptr1 = ptr1.next;
      }

      else {
        ptr2 = ptr2.next;
      }

    }
    return dummy.next;

  }


  public static void main(String[] args) {
    int[] arr1 = {1, 2, 2, 3, 4};
    ListNode head1 = createList(arr1);

    int[] arr2 = {2, 2, 2, 4};
    ListNode head2 = createList(arr2);

    ListNode newList = intersectionOfList(head1, head2);

    printList(newList);
  }
}