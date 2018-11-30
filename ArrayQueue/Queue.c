#include "Queue.h"

Queue* Queue_new(int givenCapacity)
{
	Queue* _this;
	_this = NewObject(Queue);
	_this->_front = 0;
	_this->_rear = 0;
	_this->_capacity = givenCapacity; // 추가
	_this->_elements = NewVector(char, _this->_capacity + 1); // element 배열 할당.
	return _this; // At this point, q points an empty queue.

} // 큐 객체 정의.

void Queue_delete(Queue* _this)
{ // 큐을 삭제해주는 함수.
  // There may be some elements in the queue.
	free(_this->_elements); // 큐 삭제 전에 배열 먼저 삭제한다.
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this)
{ // 큐가 비어있는지 여부를 확인.
	if ((_this->_front) == 0 && (_this->_rear) == 0) {
		return TRUE;
		// front와 rear가 0이면 큐가 비어있는것이다.
	}
	else
		return FALSE;
}

Boolean Queue_isFull(Queue* _this)
{ // 큐가 가득 차 있는지 확인.
	return _this->_rear == MAX_CAPACITY-1;
}

void Queue_add(Queue* _this, Element anElement)
{ // 큐가 꽉 차지 않았다면 노드를 추가해준다.
	if (!Queue_isFull(_this)) { // 큐가 꽉 차지 않았다면 추가를 실행.
		if (Queue_isEmpty(_this)) {
			// 큐가 비어있다면 front를 추가.
			_this->_front++;
			_this->_rear++;
			_this->_elements[_this->_front] = anElement;
			// 초기에는 front 와 rear가 같다.
		}
		else {
			// 큐가 비어있지 않다면 front에 이어서 추가.
			_this->_rear++;
			_this->_elements[_this->_rear] = anElement;
		}
	} 
}

Element Queue_remove(Queue* _this)
{ // 스택이 empty가 아닐 경우에 pop해준다.

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
{ // 큐의 사이즈를 반환한다.
	return _this->_rear; // rear의 수는 큐에 들어있는 원소의 수와 같다.
}

Element Queue_FrontElement(Queue* _this)
{ // 큐의 Front Element를 반환한다.
	return _this->_elements[_this->_front];
}

Element Queue_elementAt(Queue* _this, int anOrder) {
	return _this->_elements[anOrder + 1];
	// 큐에서 anOrder 위치에 해당하는 원소를 반환한다.
}

