
class MyLinkedList<T> {
    Node head;

    private static class Node<T> {
        T data;
        Node next;

        Node(T data) {
            this.data = data;
            next = null;
        }
    }

    public void insert(T data) {
        Node newNode = new Node(data);
        newNode.next = null;

        if (head == null) {
            head = newNode;
        }
        // Else traverse till the last node
        // and insert the new_node there
        else {
            Node lastNode = head;
            while (lastNode.next != null) {
                lastNode = lastNode.next;
            }
            lastNode.next = newNode;
        }

    }

    public void removeAnElement( T element) {

        Node currNode, prev = null;
        currNode = head;

        if (currNode != null && currNode.data.equals(element)) {
            head = currNode.next;
            System.out.println(element + " deleted successfully");
            return;
        }
        while (currNode != null && !currNode.data.equals(element)) {
            prev = currNode;
            currNode = currNode.next;
        }

        if (currNode != null) {
//            Unlink currNode from linked list
            prev.next = currNode.next;
            System.out.println(element + " deleted successfully");
        }

        if (currNode == null) {
            System.out.println(element + " not found");
        }
    }

    public void removeAtPosition( int position) {

        Node currNode = head, prev = null;

        if (position == 0 && currNode != null) {
            head = currNode.next;
            System.out.println("Element at " + position + " deleted successfully");
            return;
        }

        int cou = 0;
        while (currNode != null) {
            if (cou == position) {
                prev.next = currNode.next;
                System.out.println("Element at position " + position + " deleted successfully");
                break;
            } else {
                cou++;
                prev = currNode;
                currNode = currNode.next;
            }
        }
        if (currNode == null) {
            System.out.println(position + " element not found");
        }
    }

    public void printList() {
        Node currNode = head;
        while (currNode != null) {
            System.out.println(currNode.data + "\t");
            currNode = currNode.next;
        }
    }
}

public class LinkedList {

    public static void main(String[] args) {

        MyLinkedList myList = new MyLinkedList();
        myList.insert(22);
        myList.insert(23);
        myList.insert(23);
        myList.removeAnElement(23);
        myList.removeAtPosition(1);

        myList.printList();


    }
}
