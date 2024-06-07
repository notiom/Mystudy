/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//1.我自己的解
//既然要深拷贝，那么就需要另外开辟一份内存空间，并记录原来的random的指向
//我通过指向容器索引值来判断其指向第几个元素
//如果循环结束j==n，则让random指向nullptr
class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if(head==nullptr) return nullptr;
        vector<Node*> vecdeep;
        vector<Node*> vecbase;
        Node* p = head;
        while(p!=NULL)
        {
            Node* copyNode = new Node(p->val);
            vecdeep.push_back(copyNode);
            vecbase.push_back(p);
            p = p->next;
        }
        int n = vecdeep.size();
        for(int i = 0; i < n;i++)
        {
            Node* q = head; 
            int j = 0;
            for(;j < n; j++)
            {
                if(vecbase.at(i)->random == q)
                {
                    //相等说明random指向当前的q值
                    break;
                }
                q = q->next; 
            }
            //执行完循环如果没有退出，q会自动指向break
            if(j == n) 
            {
                vecdeep.at(i)->random = nullptr;
            }
            else
            {
                vecdeep.at(i)->random = vecdeep.at(j);
            }
            if(i == n - 1) 
            {
                vecdeep.at(i)->next = nullptr;
                break;
            }
            vecdeep.at(i)->next = vecdeep.at(i + 1);
        }
    return vecdeep.at(0);
    }
};
