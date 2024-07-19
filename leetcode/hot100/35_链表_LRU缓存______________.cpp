// 1.觉得要手撕哈希表
// 直接看题解
// 官方题解
struct DLinkNode
{
    int key,value;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode() : key(0),value(0) {}
    DLinkNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache 
{
private:
    unordered_map<int,DLinkNode*> cache;
    DLinkNode* head; // 创立头节点和尾节点
    DLinkNode* tail;
    int size; // 记录当前元素个数
    int capacity; // 记录初始化的总的容量大小
public:
    LRUCache(int capacity) : capacity(capacity), size(0)
    {
        // 使用伪头部节点和尾部节点
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if(!cache.count(key)) return -1; //说明没有找到该元素键
        // 如果找到，就需要把该节点移动到双向链表的头部
        DLinkNode* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->value;
    }
    
    void put(int key, int value) 
    {
        if(!cache.count(key))
        {
            // 此时元素没有被添加该键，所以需要添加新的元素进入哈希表
            DLinkNode* node = new DLinkNode(key, value);
            cache[key] = node;

            //将此元素添加进入头部
            addToHead(node);
            size++;
            if(size > capacity)
            {
                // 说明此处需要删除尾部节点
                DLinkNode* temp =  removeTail();
                // 删除哈希表中的队应项
                cache.erase(temp->key);
                delete temp;
                size--;
            }
        }
        else
        {
            // 元素存在，所以需要更新其值
            DLinkNode* node = cache[key];
            node->value = value; //只要这个节点的值被改变，那么哈希表中的值也会被改变
            removeNode(node);
            addToHead(node);
        }
    }

    // 辅助函数：在双向链表中删除一个节点
    void removeNode(DLinkNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 辅助函数：在双向链表中添加一个节点到头部
    void addToHead(DLinkNode* node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 辅助函数：删除尾部节点
    DLinkNode* removeTail()
    {
        DLinkNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
// 结论:通过 哈希表加双向循环链表
