public class MyQueue<T> {

    Node firstNode, lastNode;

    public MyQueue() {
        firstNode = null;
        lastNode = null;
    }

    private class Node {
        Node next;
        T item;

        public Node() {
            next = null;
        }
    }

    public boolean isEmpty() {
        if (firstNode == null)
            return true;
        return false;
    }

    public void enqueue(T newItem) {
        Node newNode = new Node();
        newNode.item = newItem;

        if (isEmpty()) {
            firstNode = newNode;
            lastNode = newNode;
        } else {
            lastNode.next = newNode;
            lastNode = newNode;
        }
    }

    public T dequeue() throws Exception {
        if (isEmpty()) {
            throw new Exception("The queue is empty");
        } else {
            T item = firstNode.item;
            firstNode = firstNode.next;
            return item;

        }
    }

    public T peek() throws Exception {
        if (isEmpty()) {
            throw new Exception("The queue is empty");
        } else
        return firstNode.item;
    }

}
