public class MyStack<T> {
    //  STACK USING SINGLY LINKED LIST

    private Node firstNode;

    public MyStack() {
        firstNode = null;
    }

    private class Node {
        Node next;
        T item;

        public Node() {
            next = null;
        }
    }

    public void push(T newItem) {
        Node newNode = new Node();
        newNode.item = newItem;
        newNode.next = firstNode;
        firstNode = newNode;
    }

    public T pop() throws Exception {
        if (!isEmpty()) {
            T item = firstNode.item;
            firstNode = firstNode.next;
            return item;
        } else {
            throw new Exception("The stack is empty");
        }
    }

    public T peek() throws Exception {
        if (firstNode != null)
            return firstNode.item;
        else {
            throw new Exception("The stack is empty");
        }
    }

    public boolean isEmpty() {
        if (firstNode == null)
            return true;
        else
            return false;
    }

}
