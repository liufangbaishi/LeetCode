/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    void Ser(TreeNode* root, string &s)
    {
        if(root == NULL)
        {
            s += '$';
            return;
        }
        s += to_string(root->val);
        s += ',';
        Ser(root->left, s);
        Ser(root->right, s);
    }
    char* Serialize(TreeNode *root) {
        string s;
        Ser(root, s);
        char *res = new char[s.size()+1];
        int i=0;
        for(i=0; i<s.size(); i++)
            res[i] = s[i];
        res[i] = '\0';
        return res;
    }
    TreeNode* Deser(char *str, int &index)
    {
        if(str[index] == '$')
        {
            index++;
            return NULL;
        }
        int num=0;
        while(str[index] != '\0' && str[index] != ',')
        {
            num = num*10+(str[index]-'0');
            index++;
        }
        TreeNode* root = new TreeNode(num);
        if(str[index] == '\0')
            return root;
        else
            index++;
        root->left = Deser(str, index);
        root->right = Deser(str, index);
        return root;
    }
    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        int index = 0;
        return Deser(str, index);
    }
};