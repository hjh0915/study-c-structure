#define MaxSize 100
typedef int DataType;

typedef struct SeqList {
    DataType data[MaxSize];
    int length;
} SeqList;

void InitList(SeqList * L);     //初始化顺序表
int CreateList(SeqList * L, DataType a[], int n);    //建立顺序表
int Empty(SeqList * L);     //判断是否长度为0
int Length(SeqList * L);    //顺序表的长度
void PrintList(SeqList * L);    //遍历顺序表
int Locate(SeqList * L, DataType x);    //按值查找
int Get(SeqList * L, int i, DataType * ptr);    //按位查找
int Insert(SeqList * L, int i, DataType x);     //插入
int Delete(SeqList * L, int i, DataType * ptr); //删除