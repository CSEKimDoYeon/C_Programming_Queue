#include "Queue.h"

#define DEFAULT_QUEUE_CAPACITY 5

Queue* Queue_new()
{
	Queue* _this;
	_this = NewObject(Queue);
	_this->_front = NULL;
	_this->_rear = NULL;
	_this->_capacity = MAX_CAPACITY; // �߰�
	_this->_size = 0; // �߰�
	return _this; // At this point, q points an empty queue.

} // ť ��ü ����.

void Queue_delete(Queue* _this)
{ // ť�� �������ִ� �Լ�.
  // There may be some elements in the queue.
	Queue_deleteLinkedChain(_this);
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this)
{ // ť�� ����ִ��� ���θ� Ȯ��.
	//return ((_this->_top) < 0);
	if (_this->_size == 0) {
		return TRUE;
	}
	else
		return FALSE;
	// front�� rear�� ������ ����ִ°��̴�.
}

Boolean Queue_isFull(Queue* _this)
{ // ������ ���� �� �ִ��� Ȯ��.
	return _this->_size == MAX_CAPACITY;
}

void Queue_add(Queue* _this, Element anElement)
{ // ť�� �� ���� �ʾҴٸ� ��带 �߰����ش�.
	if (!Queue_isFull(_this)) { // ť�� �� ���� �ʾҴٸ� �߰��� ����.
		Node* addedNode = Node_new();
		Node_setElement(addedNode, anElement);
		if (Queue_isEmpty(_this)) {
			// ť�� ����ִٸ� front�� �߰�.
			_this->_front = addedNode;
			_this->_rear = _this->_front;
			_this->_size++;
			// �ʱ⿡�� front �� rear�� ����.
		}
		else {
			// ť�� ������� �ʴٸ� front�� �̾ �߰�.
			Node_setNext(_this->_rear, addedNode);
			_this->_rear = addedNode;
			_this->_size++;
		}
	} 
}

Element Queue_remove(Queue* _this)
{ // ������ empty�� �ƴ� ��쿡 pop���ش�.
	Element removedElement;
	//removedElement = _this->_elements[_this->_top];
	removedElement = Node_element(_this->_front);

	Node* tempNode = _this->_front; // ������ ��带 �ӽ�����
	_this->_front = Node_next(_this->_front); // ����Ʈ�� ������ ��� ���������� ����.
	Node_delete(tempNode); // ������� ����
	_this->_size--;
	return removedElement;
}

int Queue_size(Queue* _this)
{ // ť�� ����� ��ȯ�Ѵ�.
	return _this->_size;
}

Element Queue_FrontElement(Queue* _this)
{ // ť�� Front Element�� ��ȯ�Ѵ�.
	return Node_element(_this->_front);
}

Element Queue_elementAt(Queue* _this, int anOrder) {
	if (anOrder == 0) {
		// ù��° ���Ҵ� Front�̹Ƿ� Front���Ҹ� ��ȯ�Ѵ�.
		return Node_element(_this->_front);
	}
	else {
		Node* tempNode = _this->_front;
		for (int i = 0; i < anOrder ; i++) {
			tempNode = Node_next(tempNode);
		}
		return Node_element(tempNode);
	}
	// ť���� anOrder ��ġ�� �ش��ϴ� ���Ҹ� ��ȯ�Ѵ�.
}

void Queue_deleteLinkedChain(Queue* _this)
{	// ť�� �����ϴ� ���ҵ��� ���������� �����Ѵ�.
	Node* tempNode = _this->_front;
	for (int i = 0; i < _this->_size; i++) {
		_this->_front = Node_next(_this->_front);
		Node_delete(tempNode);
	}
}
