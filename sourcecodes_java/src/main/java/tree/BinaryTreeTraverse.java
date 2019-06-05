package tree;

import java.util.Stack;

public class BinaryTreeTraverse {

    /**
     * 中序递归遍历
     */
    public static void inOrderTraverseRecursive(Node root) {
        if (root.left != null) {
            inOrderTraverseRecursive(root.left);
        }

        System.out.println(root.val);

        if (root.right != null) {
            inOrderTraverseRecursive(root.right);
        }
    }

    /**
     * 前序递归遍历
     */
    public void preOrderTraverseRecursive(Node root) {
        System.out.println(root.val);

        if (root.left != null) {
            preOrderTraverseRecursive(root.left);
        }
        if (root.right != null) {
            preOrderTraverseRecursive(root.right);
        }
    }

    /**
     * 后序递归遍历
     */
    public void postOrderTraverseRecursive(Node root) {
        if (root.left != null) {
            postOrderTraverseRecursive(root.left);
        }
        if (root.right != null) {
            postOrderTraverseRecursive(root.right);
        }

        System.out.println(root.val);
    }

    /**
     * 中序非递归遍历
     */
    public void inOrderTraverseNonRecursive(Node root) {
        Stack<Node> stack = new Stack<Node>();

        Node tmp = root;
        while (tmp != null) {
            stack.push(tmp);
            tmp = tmp.left;
        }

        while (!stack.isEmpty()) {
            tmp = stack.pop();
            System.out.println(tmp.val);

            tmp = tmp.right;
            while (tmp != null) {
                stack.push(tmp);
                tmp = tmp.left;
            }
        }
    }

    /**
     * 前序非递归遍历
     */
    public void preOrderTraverseNonRecursive(Node root) {
        Stack<Node> stack = new Stack<Node>();

        stack.push(root);

        Node tmp = null;
        while (!stack.isEmpty()) {
            tmp = stack.pop();

            System.out.println(tmp.val);

            if (tmp.right != null) {
                stack.push(tmp.right);
            }

            if (tmp.left != null) {
                stack.push(tmp.left);
            }
        }
    }

    /**
     * 后序非递归遍历
     */
    public void postOrderTraverseNonRecursive(Node root) {
        Stack<Node> stack = new Stack<Node>();

        stack.push(root);

        Node pre = null;
        Node tmp;
        while (!stack.isEmpty()) {
            tmp = stack.peek();

            if (tmp.left == null && tmp.right == null) {
                System.out.println(tmp.val);

                stack.pop();
                pre = tmp;

                continue;
            }

            if (pre != null && (pre == tmp.left || pre == tmp.right)) {
                System.out.println(tmp.val);

                stack.pop();
                pre = tmp;

                continue;
            }

            if (tmp.right != null) {
                stack.push(tmp.right);
            }

            if (tmp.left != null) {
                stack.push(tmp.left);
            }
        }
    }

    private static class Node {

        int val;

        Node left;

        Node right;

        public Node(int val) {
            this.val = val;
        }
    }

}
