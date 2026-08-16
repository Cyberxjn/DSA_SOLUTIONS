class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {

        // If any tree is completely TRUE
        if (quadTree1->isLeaf && quadTree1->val)
            return quadTree1;

        if (quadTree2->isLeaf && quadTree2->val)
            return quadTree2;

        // If first tree is leaf FALSE
        if (quadTree1->isLeaf)
            return quadTree2;

        // If second tree is leaf FALSE
        if (quadTree2->isLeaf)
            return quadTree1;

        // Recursively process 4 children
        Node* topLeft =
            intersect(quadTree1->topLeft, quadTree2->topLeft);

        Node* topRight =
            intersect(quadTree1->topRight, quadTree2->topRight);

        Node* bottomLeft =
            intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);

        Node* bottomRight =
            intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        // If all 4 children are TRUE leaves,
        // merge them into one TRUE leaf
        if (topLeft->isLeaf && topRight->isLeaf &&
            bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val && topRight->val &&
            bottomLeft->val && bottomRight->val) {

            return new Node(true, true);
        }

        return new Node(false, false,
                        topLeft, topRight,
                        bottomLeft, bottomRight);
    }
};