class MyBST {

    private static final int INVALID_INDICATOR = -1;
    private Node root;

    public MyBST() {
        root = null;
    }

    public class Node {
        double nubmber;
        Node left, right;

        public Node(double nubmber) {
            this.nubmber = nubmber;
            left = right = null;
        }
    }

    public void setRoot(Node root) {
        this.root = root;
    }

    public void insert(double number) {
        if (number < 0)
            return;

        if (root == null) {
            root = new Node(number);
            System.out.println(number + " inserted successfully");
            return;
        }

        Node currNode = root;

        while (true) {
            if (currNode.nubmber < number) {
                if (currNode.right == null) {
                    //  ADD AS THE RIGHT CHILD
                    currNode.right = new Node(number);
                    break;
                } else {
                    //  TRAVERSING THE RIGHT SUBTREE
                    currNode = currNode.right;
                }
            } else {
                if (currNode.left == null) {
                    //  ADD AS THE LEFT CHILD
                    currNode.left = new Node(number);
                    break;
                } else {
                    //  TRAVERSING THE LEFT SUBTREE
                    currNode = root.left;
                }
            }
        }
        System.out.println(number + " inserted successfully");
    }

    public Node getRoot() {
        return root;
    }

    public void searchItem(double number) {
        if (search(number, root)) {
            System.out.println(number + " has been found");
        } else {
            System.out.println(number + " has not been found");
        }
    }

    private boolean search(double number, Node root) {

        while (root != null) {
            if (root.nubmber == number) {

                return true;
            } else if (root.nubmber < number) {
                //  TRAVERSING THE RIGHT SUBTREE
                root = root.right;

            } else {
                //  TRAVERSING THE LEFT SUBTREE
                root = root.left;
            }
        }
        if (root == null) {

            return false;
        }
        return false;
    }

    public Node getMinNode(Node root) {

        while (root.left != null) {
            root = root.left;
        }
        return root;
    }

    public double getInOrderSuccessor(double number) {

        Node bkpRoot = root;
        Node successor[] = new Node[1];
        successor[0] = new Node(-1);
        //  SENDING AN ARRAY OF OBJECT IN ORDER TO PASS THE REFERENCE OF THE SUCCESSOR NODE
        //  AND SEE THE CHANGE GLOBALLY
        inOrderSuccessor(number, root, successor);
        root = bkpRoot;

        return successor[0].nubmber;
    }

    private void inOrderSuccessor(double number, Node currRoot, Node successor[]) {
        if (currRoot == null) {
            return;
        }

        if (currRoot.nubmber == number) {
            if (currRoot.right != null) {
                successor[0] = getMinNode(currRoot.right);
            }

        } else if (currRoot.nubmber > number) {
            successor[0] = currRoot;
            inOrderSuccessor(number, currRoot.left, successor);

        } else {
            inOrderSuccessor(number, currRoot.right, successor);
        }
    }

    public Node getMaxNode(Node root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }

    public double getInOrderPredecessor(double number) {

        Node bkpRoot = root;
        Node predecessor[] = new Node[1];
        predecessor[0] = new Node(-1);
        //  SENDING AN ARRAY OF OBJECT IN ORDER TO PASS THE REFERENCE OF THE PREDECESSOR NODE
        //  AND SEE THE CHANGE GLOBALLY
        inOrderPredecessor(number, root, predecessor);
        root = bkpRoot;

        return predecessor[0].nubmber;
    }

    private void inOrderPredecessor(double number, Node currRoot, Node predecessor[]) {
        if (currRoot == null) {
            return;
        }

        if (currRoot.nubmber == number) {
            if (currRoot.left != null) {
                predecessor[0] = getMaxNode(currRoot.left);

            }

        } else if (currRoot.nubmber > number) {

            inOrderPredecessor(number, currRoot.left, predecessor);

        } else {
            predecessor[0] = currRoot;
            inOrderPredecessor(number, currRoot.right, predecessor);

        }
    }

    public void deleteItem(double number) {

        if (deleteItemRecursion(root, number) == null) {
            System.out.println(number + " Not found in the BST");
        } else {
            System.out.println(number + " Deleted successfully");
        }
    }

    private Node deleteItemRecursion(Node root, double number) {

        if (!search(number, root)) {
            //  THE ITEM IS NOT IN THE BST
            return null;
        }

        if (root == null) {
            return root;
        } else if (number < root.nubmber) {
            root.left = deleteItemRecursion(root.left, number);
        } else if (number > root.nubmber) {
            root.right = deleteItemRecursion(root.right, number);
        } else {
            //  GOT THE DELETABLE NODE
            if (root.left == null && root.right == null) {
                //  THE NODE HAS NO CHILDREN
                root = null;
            } else if (root.left == null) {
                //  HAS ONLY RIGHT CHILD
                Node temp = root;
                root = root.right;
                temp = null;
            } else if (root.right == null) {
                //  HAS ONLY LEFT CHILD
                Node temp = root;
                root = root.left;
                temp = null;
            } else {
                //  GET THE MIN OF THE RIGHT CHILD OF THE DELETABLE NODE
                //  REPLACE THE MIN NODE WITH THE DELETABLE NODE
                Node minNode = getMinNode(root.right);
                double minVal = minNode.nubmber;
                root.nubmber = minVal;

                root.right = deleteItemRecursion(root.right, minVal);
            }
        }
        return root;

    }

    public int getItemDepth(double number) {
        return getDepth(number, root);
    }

    private int getDepth(double number, Node root) {

        if (!search(number, root)) {
            return INVALID_INDICATOR;
        }

        if (root == null) {
            return INVALID_INDICATOR;
        }
        int itemDepth = 0;
        while (root != null) {
            if (root.nubmber == number) {
                return itemDepth;
            } else if (root.nubmber < number) {
                //  TRAVERSING THE RIGHT SUBTREE
                root = root.right;
                itemDepth++;

            } else {
                //  TRAVERSING THE LEFT SUBTREE
                root = root.left;
                itemDepth++;
            }
        }
        return itemDepth;
    }

    public double getMinItem() {
        return getMinItem(root);
    }

    private double getMinItem(Node root) {

        while (root.left != null) {
            root = root.left;
        }
        return root.nubmber;
    }

    public double getMaxItem() {
        return maxItem(root);
    }

    private double maxItem(Node root) {

        while (root.right != null) {
            root = root.right;
        }
        return root.nubmber;
    }

    public int getHeight() {
        return height(root);
    }

    private int height(Node root) {

        if (root == null)
            return -1;

        int depthLeft = height(root.left);
        int depthRight = height(root.right);

        if (depthLeft > depthRight)
            return depthLeft + 1;
        else
            return depthRight + 1;
    }

    public void printInOrder() {
        inOrderTraversal(root);
    }

    private void inOrderTraversal(Node root) {
        if (root == null)
            return;

        inOrderTraversal(root.left);
        System.out.print(root.nubmber + " ");
        inOrderTraversal(root.right);
    }

    public void printPreOrder() {
        preOrderTraversal(root);
    }

    private void preOrderTraversal(Node root) {

        if (root == null)
            return;

        System.out.print(root.nubmber + " ");
        preOrderTraversal(root.left);
        preOrderTraversal(root.right);
    }

    public void printPostOrder() {
        postOrderTraversal(root);
    }

    private void postOrderTraversal(Node root) {

        if (root == null)
            return;

        postOrderTraversal(root.left);
        postOrderTraversal(root.right);
        System.out.print(root.nubmber + " ");
    }

    public int getSize() {
        return size(root);
    }

    private int size(Node root) {
        if (root == null)
            return 0;
        else {
            return size(root.left) + size(root.right) + 1;
        }
    }

}