import java.util.Objects;
import java.util.Stack;

// javac TreeNode.java -Xlint:unchecked && java TreeNode 
// 
public class TreeNode<E> {

    TreeNode<E> left;

    TreeNode<E> right;

    E value;

    public void setLeft(TreeNode<E> node) {
        this.left = node;
    }

    public void setRight(TreeNode<E> node) {
        this.right = node;
    }

    public TreeNode<E> getLeft() {
        return this.left;
    }

    public TreeNode<E> getRight() {
        return this.right;
    }

    public E getValue() {
        return this.value;
    }

    TreeNode(E value) {
        this.value = value;
    }

    public static TreeNode<Integer> getRootTree() {
        TreeNode<Integer> root = new TreeNode<>(80);
        TreeNode<Integer> left = new TreeNode<>(70);
        TreeNode<Integer> right = new TreeNode<>(90);
        left.setLeft(new TreeNode<>(69));
        left.setRight(new TreeNode<>(72));
        right.setRight(new TreeNode<>(122));
        root.setLeft(left);
        root.setRight(right);
        return root;
    }

    /**
     * 前序遍历 中左右
     */
    public static <E> void preorderTraversal(TreeNode<E> root) {
        Stack<TreeNode<E>> stack = new Stack<>();

        while (!stack.empty() || root != null) {
            while (root != null) {
                System.out.print(root.getValue() + " ");
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            root = root.right;
        }
        System.out.println();
    }

    /**
     * 中序遍历（左中右）--> 二叉查找树，可得到顺序数列
     */
    public static <E> void inorderTraversal(TreeNode<E> root) {
        Stack<TreeNode<E>> stack = new Stack<>();

        while (!stack.empty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            System.out.print(root.getValue() + " ");
            root = root.right;
        }
        System.out.println();
    }

    /**
     * 后序遍历 左右中
     */
    public static <E> void postorderTraversal(TreeNode<E> node) {

        if (node == null) {
            return;
        }
        Stack<TreeNode<E>> stack1 = new Stack<>();
        Stack<TreeNode<E>> stack2 = new Stack<>();
        stack1.push(node);

        while (!stack1.empty()) {
            TreeNode<E> temp = stack1.pop();
            stack2.push(temp);
            if (temp.left != null) {
                stack1.push(temp.left);
            }
            if (temp.right != null) {
                stack1.push(temp.right);
            }

        }
        while (!stack2.empty()) {
            TreeNode<E> temp2 = stack2.pop();
            System.out.print(temp2.getValue() + " ");
        }
        System.out.println();
    }

    /**
     * 后序遍历 递归实现
     */
    public static <E> void postOrder(TreeNode<E> node) {
        if (Objects.isNull(node)) {
            return;
        }

        if (Objects.nonNull(node.left)) {
            postOrder(node.left);
        }

        if (Objects.nonNull(node.right)) {
            postOrder(node.right);
        }

        if (Objects.nonNull(node)) {
            System.out.print(node.getValue() + " ");
        }
    }

    public static void main(String[] args) {

        /**
         * 80 - 90 - 122
         * |
         * 70 - 72
         * |
         * 69
         */
        TreeNode<Integer> root = getRootTree();
        preorderTraversal(root);
        inorderTraversal(root);
        postorderTraversal(root);
        // postOrder(root);
        // 80 70 69 72 90 122
        // 69 70 72 80 90 122
        // 69 72 70 122 90 80
    }

}
