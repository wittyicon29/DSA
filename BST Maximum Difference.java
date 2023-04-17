class Solution{
    public static int maxDifferenceBST(Node root, int target){
        // Find the node with given target value in the BST
    Node node = findNode(root, target);
    
    // If the node is not found, return -1
    if (node == null)
        return -1;
    
    // Calculate sum of values of nodes till the node with target value is found
    int sum1 = sum(root, node.data) - node.data;
    
    // Calculate minimum sum of values the child nodes of target node
    int sum2 = minSum(node) - node.data;
    
    // Return the difference between sum1 and sum2
    return sum1 - sum2;
}

// Find the node with given target value in the BST
private static Node findNode(Node root, int target) {
    // If the root is null or target value is found in the root node, return the root node
    if (root == null || root.data == target)
        return root;
    
    // If the root's value is greater than target value, search in the left subtree
    if (root.data > target)
        return findNode(root.left, target);
    else // Otherwise, search in the right subtree
        return findNode(root.right, target);
}

// Calculate sum of values upto target value in the BST
private static int sum(Node node, int target) {
    // If the node is null, return 0
    if (node == null)
        return 0;
    
    // If the node's value matches the target value, return the node's value
    if (node.data == target)
        return node.data;
    
    // If the node's value is greater than target value, add it to the sum and search in the left subtree
    if (node.data > target)
        return node.data + sum(node.left, target);
    else // Otherwise, add it to the sum and search in the right subtree
        return node.data + sum(node.right, target);
}

// Calculate sum of values of child nodes of the target node in the BST
private static int minSum(Node node) {
    // If the node is null, return 0
    if (node == null)
        return 0;
    
    // If the node is a leaf node, return its value
    if (node.left == null && node.right == null)
        return node.data;
    
    // If the node has no left child, add its value to the sum and search in the right subtree
    if (node.left == null)
        return node.data + minSum(node.right);
    
    // If the node has no right child, add its value to the sum and search in the left subtree
    if (node.right == null)
        return node.data + minSum(node.left);
    
    // If the node has both left and right child, add its value to the minimum sum of the left and right subtrees
    return Math.min(node.data + minSum(node.left), node.data + minSum(node.right));
    }
}