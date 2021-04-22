typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

Node * InitList();  // 初始化一个链表
int Empty(Node * first);    //判断链表是否只有头节点
void PrintList(Node * first);   // 遍历链表
int Length(Node * first);   // 链表的长度
int Locate(Node * first, DataType x);   // 按值查找
int Get(Node * first, int i, DataType * ptr);   // 按位查找
int Insert(Node * first, int i, DataType x);    // 链表中间插入
Node * CreateListByHead(DataType a[], int n);   // 头插法
Node * CreateListByTail(DataType a[], int n);   // 尾插法
int Delete(Node * first, int i, DataType * ptr); // 删除结点
void DestroyList(Node * first); // 销毁链表