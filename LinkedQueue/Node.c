#include "Node.h"

struct _Node { // 노드 구조체 정의
	Element _element;
	Node* _next;
};
Node* Node_new() {
	// 노드에 대하여 메모리 공간 할당.
	Node* _this = (Node*)malloc(sizeof(Node));
	return _this;
}
void Node_delete(Node* _this) {
	// 노드 삭제
	free(_this);
}

void Node_setElement(Node* _this, Element newElement)
{	// 노드에 Element를 Setting한다.
	_this->_element = newElement;
}
Element Node_element(Node* _this)
{	//노드에 해당하는 element를 반환한다.
	return _this->_element;
}
void Node_setNext(Node* _this, Node* newNext)
{	// 해당 노드의 다음 노드를 Setting한다.
	_this->_next = newNext;
}
Node* Node_next(Node* _this)
{	// 해당 노드의 다음 노드를 반환한다.
	return _this->_next;
}