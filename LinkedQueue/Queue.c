#include "Queue.h"

#define DEFAULT_QUEUE_CAPACITY 5

Queue* Queue_new()
{
	Queue* _this;
	_this = NewObject(Queue);
	_this->_front = NULL;
	_this->_rear = NULL;
	_this->_capacity = MAX_CAPACITY; // 추가
	_this->_size = 0; // 추가
	return _this; // At this point, q points an empty queue.

} // 큐 객체 정의.

void Queue_delete(Queue* _this)
{ // 큐을 삭제해주는 함수.
  // There may be some elements in the queue.
	Queue_deleteLinkedChain(_this);
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this)
{ // 큐가 비어있는지 여부를 확인.
	//return ((_this->_top) < 0);
	if (_this->_size == 0) {
		return TRUE;
	}
	else
		return FALSE;
	// front와 rear가 같으면 비어있는것이다.
}

Boolean Queue_isFull(Queue* _this)
{ // 스택이 가득 차 있는지 확인.
	return _this->_size == MAX_CAPACITY;
}

void Queue_add(Queue* _this, Element anElement)
{ // 큐가 꽉 차지 않았다면 노드를 추가해준다.
	if (!Queue_isFull(_this)) { // 큐가 꽉 차지 않았다면 추가를 실행.
		Node* addedNode = Node_new();
		Node_setElement(addedNode, anElement);
		if (Queue_isEmpty(_this)) {
			// 큐가 비어있다면 front를 추가.
			_this->_front = addedNode;
			_this->_rear = _this->_front;
			_this->_size++;
			// 초기에는 front 와 rear가 같다.
		}
		else {
			// 큐가 비어있지 않다면 front에 이어서 추가.
			Node_setNext(_this->_rear, addedNode);
			_this->_rear = addedNode;
			_this->_size++;
		}
	} 
}

Element Queue_remove(Queue* _this)
{ // 스택이 empty가 아닐 경우에 pop해준다.
	Element removedElement;
	//removedElement = _this->_elements[_this->_top];
	removedElement = Node_element(_this->_front);

	Node* tempNode = _this->_front; // 삭제할 노드를 임시저장
	_this->_front = Node_next(_this->_front); // 프론트를 삭제할 노드 다음것으로 지정.
	Node_delete(tempNode); // 템프토드 삭제
	_this->_size--;
	return removedElement;
}

int Queue_size(Queue* _this)
{ // 큐의 사이즈를 반환한다.
	return _this->_size;
}

Element Queue_FrontElement(Queue* _this)
{ // 큐의 Front Element를 반환한다.
	return Node_element(_this->_front);
}

Element Queue_elementAt(Queue* _this, int anOrder) {
	if (anOrder == 0) {
		// 첫번째 원소는 Front이므로 Front원소를 반환한다.
		return Node_element(_this->_front);
	}
	else {
		Node* tempNode = _this->_front;
		for (int i = 0; i < anOrder ; i++) {
			tempNode = Node_next(tempNode);
		}
		return Node_element(tempNode);
	}
	// 큐에서 anOrder 위치에 해당하는 원소를 반환한다.
}

void Queue_deleteLinkedChain(Queue* _this)
{	// 큐에 존재하는 원소들을 순차적으로 삭제한다.
	Node* tempNode = _this->_front;
	for (int i = 0; i < _this->_size; i++) {
		_this->_front = Node_next(_this->_front);
		Node_delete(tempNode);
	}
}
