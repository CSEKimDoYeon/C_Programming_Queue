#include "Queue.h"

Queue* Queue_new(int givenCapacity)
{
	Queue* _this;
	_this = NewObject(Queue);
	_this->_front = 0;
	_this->_rear = 0;
	_this->_capacity = givenCapacity; // �߰�
	_this->_elements = NewVector(char, _this->_capacity + 1); // element �迭 �Ҵ�.
	return _this; // At this point, q points an empty queue.

} // ť ��ü ����.

void Queue_delete(Queue* _this)
{ // ť�� �������ִ� �Լ�.
  // There may be some elements in the queue.
	free(_this->_elements); // ť ���� ���� �迭 ���� �����Ѵ�.
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this)
{ // ť�� ����ִ��� ���θ� Ȯ��.
	if ((_this->_front) == 0 && (_this->_rear) == 0) {
		return TRUE;
		// front�� rear�� 0�̸� ť�� ����ִ°��̴�.
	}
	else
		return FALSE;
}

Boolean Queue_isFull(Queue* _this)
{ // ť�� ���� �� �ִ��� Ȯ��.
	return _this->_rear == MAX_CAPACITY-1;
}

void Queue_add(Queue* _this, Element anElement)
{ // ť�� �� ���� �ʾҴٸ� ��带 �߰����ش�.
	if (!Queue_isFull(_this)) { // ť�� �� ���� �ʾҴٸ� �߰��� ����.
		if (Queue_isEmpty(_this)) {
			// ť�� ����ִٸ� front�� �߰�.
			_this->_front++;
			_this->_rear++;
			_this->_elements[_this->_front] = anElement;
			// �ʱ⿡�� front �� rear�� ����.
		}
		else {
			// ť�� ������� �ʴٸ� front�� �̾ �߰�.
			_this->_rear++;
			_this->_elements[_this->_rear] = anElement;
		}
	} 
}

Element Queue_remove(Queue* _this)
{ // ������ empty�� �ƴ� ��쿡 pop���ش�.

	Element removedElement;
	if ((_this->_rear == 1) && (_this->_front == 1)) {
		removedElement = _this->_elements[_this->_front];
		_this->_elements[_this->_front] = NULL;
		_this->_front--;
		_this->_rear--;
		return removedElement;
	}
	else {
		removedElement = _this->_elements[_this->_front];
		_this->_elements[_this->_front] = NULL;

		for (int i = 1; i < _this->_rear; i++) {
			_this->_elements[i] = _this->_elements[i + 1];
		}
		_this->_elements[_this->_rear] = NULL;
		_this->_rear--;
		return removedElement;
	}
}

int Queue_size(Queue* _this)
{ // ť�� ����� ��ȯ�Ѵ�.
	return _this->_rear; // rear�� ���� ť�� ����ִ� ������ ���� ����.
}

Element Queue_FrontElement(Queue* _this)
{ // ť�� Front Element�� ��ȯ�Ѵ�.
	return _this->_elements[_this->_front];
}

Element Queue_elementAt(Queue* _this, int anOrder) {
	return _this->_elements[anOrder + 1];
	// ť���� anOrder ��ġ�� �ش��ϴ� ���Ҹ� ��ȯ�Ѵ�.
}

