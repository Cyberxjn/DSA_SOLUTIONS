Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.



According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:

<img width="200" height="190" alt="image" src="https://github.com/user-attachments/assets/82235857-d154-46d1-8adf-00d0fb3a5cfc" />



Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

<img width="200" height="190" alt="image" src="https://github.com/user-attachments/assets/a4735ac7-b91a-4ac2-ac6d-b0c81357adc4" />


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 
