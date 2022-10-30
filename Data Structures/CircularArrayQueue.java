class MyQueueCircularArr {

    private static final int DEFAULT_SIZE = 1000;
    char[] arr;
    int head, tail, length, sizeOfArray;

    public MyQueueCircularArr() {
        arr = new char[DEFAULT_SIZE];
        head = tail = length = 0;
        sizeOfArray = DEFAULT_SIZE;
    }

    public MyQueueCircularArr(int size) {
        arr = new char[size];
        head = tail = length = 0;
        sizeOfArray = size;
    }

    public void enqueue(char item) {
        if (tail < sizeOfArray) {
            arr[tail++] = item;
            length++;
            System.out.println(item + " inserted");
        } else if (tail == sizeOfArray && tail != head) {
            tail = 0;
            if (tail == head) {
                System.out.println("The array is full");
            } else {
                arr[tail++] = item;
                length++;
                System.out.println(item + " inserted");
            }
        }
    }

    public int dequeue() throws Exception {
        if (!isEmpty()) {
            length--;
            System.out.println("Dequeuing " + arr[head]);
            int top = arr[head];
            if (head == sizeOfArray - 1)
                head = 0;
            else
                head++;
            return top;
        } else {
            throw new Exception("The queue is empty");
        }
    }

    public void printSequence() {
        int h = head;
        for (int i = 0; i < length; i++) {
            System.out.println(arr[h++] + " ");
            if (h == sizeOfArray)
                h = 0;
        }
    }

    public char peek() throws Exception {
        if (!isEmpty()) {
            return arr[head];
        } else {
            throw new Exception("The queue is empty");
        }
    }

    public void removeAnElement(char item) throws Exception {
        if (!isEmpty()) {
            if (arr[head] == item) {
                dequeue();
            } else {
                int h = head;
                for (int i = 0; i < length; i++, h++) {
                    if (h == sizeOfArray )
                        h = 0;
                    if (arr[h] == item) {
                        for (int j = 0; j < length - i - 1; j++, h++) {
                            if (h == sizeOfArray - 1)
                                h = 0;
                            arr[h] = arr[h + 1];
                        }
                        tail--;
                        length--;
                        break;
                    }
                }
            }

        } else {
            throw new Exception("The queue is empty");
        }
    }

    public boolean isEmpty() {
        if (length == 0)
            return true;
        return false;
    }
}

public class CircularArrayQueue {

    public static void main(String[] args) {

        MyQueueCircularArr array = new MyQueueCircularArr(4);
        array.enqueue('a');
        array.enqueue('b');
        array.enqueue('c');
        array.enqueue('d');
//
//        array.dequeue();
//        array.dequeue();
        try {
            array.removeAnElement('c');
            array.removeAnElement('a');
        } catch (Exception e) {
            e.printStackTrace();
        }
//        array.enqueue('e');

        array.printSequence();

    }
}
