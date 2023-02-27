class Solution{
    public Node construct(int[][] grid) {
        return construct(grid, 0, 0, grid.length);
    }
    public Node construct(int[][] grid, int x, int y, int len) {
        if (len == 1) {
            return new Node(grid[x][y] == 1, true, null, null, null, null);
        }
        Node topLeft = construct(grid, x, y, len / 2);
        Node topRight = construct(grid, x, y + len / 2, len / 2);
        Node bottomLeft = construct(grid, x + len / 2, y, len / 2);
        Node bottomRight = construct(grid, x + len / 2, y + len / 2, len / 2);
        if (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf
                && topLeft.val == topRight.val && topRight.val == bottomLeft.val && bottomLeft.val == bottomRight.val) {
            return new Node(topLeft.val, true, null, null, null, null);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
}
