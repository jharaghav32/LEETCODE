/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* quad(vector<vector<int>>&grid,int i,int j,int n){
       if(n==1){
           Node* newNode= new Node(grid[i][j],true,NULL,NULL,NULL,NULL);
           return newNode;
       } 
      Node* newNode= new Node();
      Node* topleft = quad(grid,i,j,n/2);
      Node* topRight= quad(grid,i,j+n/2,n/2);
      Node* bottomLeft = quad(grid,i+n/2,j,n/2);
      Node* bottomRight=quad(grid,i+n/2,j+n/2,n/2);
    //Now value of all child node is equal and all child node is leaf node then parent node
    // is a leaf node as we are recursively checking every single element 
        if(topleft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topleft->val==topRight->val && topRight->val ==bottomLeft->val && bottomLeft->val == bottomRight->val ){
            newNode->isLeaf=true;// as all element in their child is equal
            newNode->val=topleft->val;
        }
        else {
            newNode->topLeft=topleft;
            newNode->topRight=topRight;
            newNode->bottomLeft=bottomLeft;
            newNode->bottomRight=bottomRight;
            
        }
        return newNode;
        
        
    }
    Node* construct(vector<vector<int>>& grid) {
     
       int n = grid.size();
       return  quad(grid,0,0,n);
      
    }
};