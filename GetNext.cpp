/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        TreeLinkNode* pNext = NULL;
        if(pNode->right)
        {
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left != NULL)
                pRight = pRight->left;
            pNext = pRight;
        }
        else if(pNode->next != NULL)
        {
            TreeLinkNode* pcur = pNode;
            TreeLinkNode* ppar = pNode->next;
            while(ppar != NULL && ppar->right == pcur)
            {
                pcur = ppar;
                ppar = ppar->next;
            }
            pNext = ppar;
        }
        return pNext;
    }
};