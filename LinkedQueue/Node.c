#include "Node.h"

struct _Node { // ��� ����ü ����
	Element _element;
	Node* _next;
};
Node* Node_new() {
	// ��忡 ���Ͽ� �޸� ���� �Ҵ�.
	Node* _this = (Node*)malloc(sizeof(Node));
	return _this;
}
void Node_delete(Node* _this) {
	// ��� ����
	free(_this);
}

void Node_setElement(Node* _this, Element newElement)
{	// ��忡 Element�� Setting�Ѵ�.
	_this->_element = newElement;
}
Element Node_element(Node* _this)
{	//��忡 �ش��ϴ� element�� ��ȯ�Ѵ�.
	return _this->_element;
}
void Node_setNext(Node* _this, Node* newNext)
{	// �ش� ����� ���� ��带 Setting�Ѵ�.
	_this->_next = newNext;
}
Node* Node_next(Node* _this)
{	// �ش� ����� ���� ��带 ��ȯ�Ѵ�.
	return _this->_next;
}