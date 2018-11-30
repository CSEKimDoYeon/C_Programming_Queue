#include "Common.h"
#include "Node.h"

typedef struct _Queue Queue;

#define MAX_CAPACITY 10

struct _Queue {
	Node* _front;
	Node* _rear;
	int _size;
	int _capacity; // Ãß°¡
};

Queue* Queue_new();
void Queue_delete(Queue* _this);
Boolean Queue_isEmpty(Queue* _this);
Boolean Queue_isFull(Queue* _this);
int Queue_size(Queue* _this);
void Queue_add(Queue* _this, Element anElement);
Element Queue_remove(Queue* _this);

//Element Queue_topElement(Queue* _this);
Element Queue_elementAt(Queue* _this, int anOrder);
void Queue_deleteLinkedChain(Queue* _this);