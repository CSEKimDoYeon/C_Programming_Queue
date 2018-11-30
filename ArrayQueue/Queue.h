#include "Common.h"

typedef struct _Queue Queue;
typedef char Element;
#define MAX_CAPACITY 5

struct _Queue {
	
	//int _size; ������Ӽ� _size�� �������� ����, front�� rear�� ���Ұ�.
	Element* _elements; // �迭�� �������� �Ҵ�.
	int _capacity; // �߰�
	int _front; // front�� index
	int _rear; // rear�� index
};

Queue* Queue_new(int givenCapacity);
void Queue_delete(Queue* _this);
Boolean Queue_isEmpty(Queue* _this);
Boolean Queue_isFull(Queue* _this);
int Queue_size(Queue* _this);
void Queue_add(Queue* _this, Element anElement);
Element Queue_remove(Queue* _this);

Element Queue_elementAt(Queue* _this, int anOrder);
