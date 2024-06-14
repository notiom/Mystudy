/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//1.我自己的解，使用前序遍历，加入的元素未必是升序排列，再循环结束后，还需要进行一个快速排序
//所以算法不够严谨
vector<int> operator+(const vector<int> &nums1,const vector<int> &nums2)
{
    vector<int> res = nums1;
    res.insert(res.end(),nums2.begin(),nums2.end());
    return res;
}
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {   
        dfs(root);
        vector<int> nums = quickSort(this->res);
        return nums.at(k - 1);
    }

    void dfs(TreeNode* root)
    {
        //递归的终止条件
        if(root == nullptr) return;
        //递归的逻辑处理
        //先将当前元素加入
        //加入元素的方式应该是5,3,2,1,4,6
        this->res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> quickSort(vector<int> &nums)
    {
        int n = nums.size();
        if(n <= 1) return nums;

        int pivot = (n - 1) >> 1;
        vector<int> left{};
        vector<int> right{};
        vector<int> middle{};
        for(int i = 0; i < n;i++)
        {
            if(nums.at(i) < nums.at(pivot)) left.push_back(nums.at(i));
            if(nums.at(i) == nums.at(pivot)) middle.push_back(nums.at(i));
            if(nums.at(i) > nums.at(pivot)) right.push_back(nums.at(i));
        }
        return quickSort(left) + middle + quickSort(right);
    }
private:
    vector<int> res{}; //先初始化一个空列表
};
//结论：有改进空间，使用中序遍历，可以保证一定是升序排列

// 深度优先遍历（DFS）：

// 前序遍历
// 中序遍历
// 后序遍历
// 广度优先遍历（BFS）：

// 层次遍历

//2.使用中序遍历
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {   
        dfs(root);
        return res.at(k - 1);
    }

    void dfs(TreeNode* root)
    {
        //递归的终止条件
        if(root == nullptr) return;
        //递归的逻辑处理
        //先将当前元素加入
        //加入元素的方式应该是1，2，3，4，5，6
        dfs(root->left);
        this->res.push_back(root->val);
        dfs(root->right);
    }
private:
    vector<int> res{}; //先初始化一个空列表
};
//结论：提出思考，如果想要实现从大到小排列应该使用什么遍历

//先遍历右子树，在遍历根节点，最后再遍历左子树

// dfs(root->right);
// res.push_back(root->val);
// dfs(root->left);


//3.官方题解
//利用平衡二叉树解题

// 平衡二叉搜索树结点
struct Node {
    int val;
    Node * parent;
    Node * left;
    Node * right;
    int size;
    int height;

    Node(int val) {
        this->val = val;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0; // 结点高度：以node为根节点的子树的高度（高度定义：叶结点的高度是0）
        this->size = 1; // 结点元素数：以node为根节点的子树的节点总数
    }

    Node(int val, Node * parent) {
        this->val = val;
        this->parent = parent;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0; // 结点高度：以node为根节点的子树的高度（高度定义：叶结点的高度是0）
        this->size = 1; // 结点元素数：以node为根节点的子树的节点总数
    }

    Node(int val, Node * parent, Node * left, Node * right) {
        this->val = val;
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->height = 0; // 结点高度：以node为根节点的子树的高度（高度定义：叶结点的高度是0）
        this->size = 1; // 结点元素数：以node为根节点的子树的节点总数
    }
};


// 平衡二叉搜索树（AVL树）：允许重复值
class AVL {
public:
    AVL(vector<int> & vals) {
        if (!vals.empty()) {
            root = build(vals, 0, vals.size() - 1, nullptr);
        }
    }

    // 根据vals[l:r]构造平衡二叉搜索树 -> 返回根结点
    Node * build(vector<int> & vals, int l, int r, Node * parent) {
        int m = (l + r) >> 1;
        Node * node = new Node(vals[m], parent);
        if (l <= m - 1) {
            node->left = build(vals, l, m - 1, node);
        }
        if (m + 1 <= r) {
            node->right = build(vals, m + 1, r, node);
        }
        recompute(node);
        return node;
    }

    // 返回二叉搜索树中第k小的元素
    int kthSmallest(int k) {
        Node * node = root;
        while (node != nullptr) {
            int left = getSize(node->left);
            if (left < k - 1) {
                node = node->right;
                k -= left + 1;
            } else if (left == k - 1) {
                break;
            } else {
                node = node->left;
            }
        }
        return node->val;
    }

    void insert(int v) {
        if (root == nullptr) {
            root = new Node(v);
        } else {
            // 计算新结点的添加位置
            Node * node = subtreeSearch(root, v);
            bool isAddLeft = v <= node->val; // 是否将新结点添加到node的左子结点
            if (node->val == v) { // 如果值为v的结点已存在
                if (node->left != nullptr) { // 值为v的结点存在左子结点，则添加到其左子树的最右侧
                    node = subtreeLast(node->left);
                    isAddLeft = false;
                } else { // 值为v的结点不存在左子结点，则添加到其左子结点
                    isAddLeft = true;
                }
            }

            // 添加新结点
            Node * leaf = new Node(v, node);
            if (isAddLeft) {
                node->left = leaf;
            } else {
                node->right = leaf;
            }

            rebalance(leaf);
        }
    }

    // 删除值为v的结点 -> 返回是否成功删除结点
    bool Delete(int v) {
        if (root == nullptr) {
            return false;
        }

        Node * node = subtreeSearch(root, v);
        if (node->val != v) { // 没有找到需要删除的结点
            return false;
        }

        // 处理当前结点既有左子树也有右子树的情况
        // 若左子树比右子树高度低，则将当前结点替换为右子树最左侧的结点，并移除右子树最左侧的结点
        // 若右子树比左子树高度低，则将当前结点替换为左子树最右侧的结点，并移除左子树最右侧的结点
        if (node->left != nullptr && node->right != nullptr) {
            Node * replacement = nullptr;
            if (node->left->height <= node->right->height) {
                replacement = subtreeFirst(node->right);
            } else {
                replacement = subtreeLast(node->left);
            }
            node->val = replacement->val;
            node = replacement;
        }

        Node * parent = node->parent;
        Delete(node);
        rebalance(parent);
        return true;
    }

private:
    Node * root;

    // 删除结点p并用它的子结点代替它，结点p至多只能有1个子结点
    void Delete(Node * node) {
        if (node->left != nullptr && node->right != nullptr) {
            return;
            // throw new Exception("Node has two children");
        }
        Node * child = node->left != nullptr ? node->left : node->right;
        if (child != nullptr) {
            child->parent = node->parent;
        }
        if (node == root) {
            root = child;
        } else {
            Node * parent = node->parent;
            if (node == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        node->parent = node;
    }

    // 在以node为根结点的子树中搜索值为v的结点，如果没有值为v的结点，则返回值为v的结点应该在的位置的父结点
    Node * subtreeSearch(Node * node, int v) {
        if (node->val < v && node->right != nullptr) {
            return subtreeSearch(node->right, v);
        } else if (node->val > v && node->left != nullptr) {
            return subtreeSearch(node->left, v);
        } else {
            return node;
        }
    }

    // 重新计算node结点的高度和元素数
    void recompute(Node * node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }

    // 从node结点开始（含node结点）逐个向上重新平衡二叉树，并更新结点高度和元素数
    void rebalance(Node * node) {
        while (node != nullptr) {
            int oldHeight = node->height, oldSize = node->size;
            if (!isBalanced(node)) {
                node = restructure(tallGrandchild(node));
                recompute(node->left);
                recompute(node->right);
            }
            recompute(node);
            if (node->height == oldHeight && node->size == oldSize) {
                node = nullptr; // 如果结点高度和元素数都没有变化则不需要再继续向上调整
            } else {
                node = node->parent;
            }
        }
    }

    // 判断node结点是否平衡
    bool isBalanced(Node * node) {
        return abs(getHeight(node->left) - getHeight(node->right)) <= 1;
    }

    // 获取node结点更高的子树
    Node * tallChild(Node * node) {
        if (getHeight(node->left) > getHeight(node->right)) {
            return node->left;
        } else {
            return node->right;
        }
    }

    // 获取node结点更高的子树中的更高的子树
    Node * tallGrandchild(Node * node) {
        Node * child = tallChild(node);
        return tallChild(child);
    }

    // 重新连接父结点和子结点（子结点允许为空）
    static void relink(Node * parent, Node * child, bool isLeft) {
        if (isLeft) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        if (child != nullptr) {
            child->parent = parent;
        }
    }

    // 旋转操作
    void rotate(Node * node) {
        Node * parent = node->parent;
        Node * grandparent = parent->parent;
        if (grandparent == nullptr) {
            root = node;
            node->parent = nullptr;
        } else {
            relink(grandparent, node, parent == grandparent->left);
        }

        if (node == parent->left) {
            relink(parent, node->right, true);
            relink(node, parent, false);
        } else {
            relink(parent, node->left, false);
            relink(node, parent, true);
        }
    }

    // trinode操作
    Node * restructure(Node * node) {
        Node * parent = node->parent;
        Node * grandparent = parent->parent;

        if ((node == parent->right) == (parent == grandparent->right)) { // 处理需要一次旋转的情况
            rotate(parent);
            return parent;
        } else { // 处理需要两次旋转的情况：第1次旋转后即成为需要一次旋转的情况
            rotate(node);
            rotate(node);
            return node;
        }
    }

    // 返回以node为根结点的子树的第1个元素
    static Node * subtreeFirst(Node * node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // 返回以node为根结点的子树的最后1个元素
    static Node * subtreeLast(Node * node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // 获取以node为根结点的子树的高度
    static int getHeight(Node * node) {
        return node != nullptr ? node->height : 0;
    }

    // 获取以node为根结点的子树的结点数
    static int getSize(Node * node) {
        return node != nullptr ? node->size : 0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode * root, int k) {
        // 中序遍历生成数值列表
        vector<int> inorderList;
        inorder(root, inorderList);
        // 构造平衡二叉搜索树
        AVL avl(inorderList);

        // 模拟1000次插入和删除操作
        vector<int> randomNums(1000);
        std::random_device rd;
        for (int i = 0; i < 1000; ++i) {
            randomNums[i] = rd()%(10001);
            avl.insert(randomNums[i]);
        }
        shuffle(randomNums); // 列表乱序
        for (int i = 0; i < 1000; ++i) {
            avl.Delete(randomNums[i]);
        }

        return avl.kthSmallest(k);
    }

private:
    void inorder(TreeNode * node, vector<int> & inorderList) {
        if (node->left != nullptr) {
            inorder(node->left, inorderList);
        }
        inorderList.push_back(node->val);
        if (node->right != nullptr) {
            inorder(node->right, inorderList);
        }
    }

    void shuffle(vector<int> & arr) {
        std::random_device rd;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            int randIndex = rd()%length;
            swap(arr[i],arr[randIndex]);
        }
    }
};

//结论：晦涩难懂
