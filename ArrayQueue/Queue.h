#include "Common.h"

typedef struct _Queue Queue;
typedef char Element;
#define MAX_CAPACITY 5

struct _Queue {
	
	//int _size; 비공개속성 _size를 선언하지 말것, front와 rear로 구할것.
	Element* _elements; // 배열을 동적으로 할당.
	int _capacity; // 추가
	int _front; // front의 index
	int _rear; // rear의 index
};

Queue* Queue_new(int givenCapacity);
void Queue_delete(Queue* _this);
Boolean Queue_isEmpty(Queue* _this);
Boolean Queue_isFull(Queue* _this);
int Queue_size(Queue* _this);
void Queue_add(Queue* _this, Element anElement);
Element Queue_remove(Queue* _this);

Element Queue_elementAt(Queue* _this, int anOrder);
