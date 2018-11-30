#include "AppController.h"
#include "AppIO.h"

void AppController_run(AppController* _this) { // ���α׷� ���� �Լ�.
	AppIO_out_startProgram();
	AppController_initCountingChars(_this);
	AppIO_out_newLine();
	char c = AppIO_in_charDirectlyFromKeyboard();
	// Ű����� �Է¹��� ���ڸ� ���� ����.

	while (c != Esc) { // Esc�� �Է� �� �� ���� ����.
		AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_add(_this, c);
			// ���ĺ��ϰ�� ť�� Add
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_removeN(_this, digitValue);
			// �����ϰ�� ���ڸ�ŭ Remove
		}
		else if (c == '-') {
			AppController_remove1(_this);
			// - �� ��� �ϳ��� Remove
		}
		else if (c == '#') {
			AppController_showSize(_this);
			// # �� ��� ť�� ������ ���.
		}
		else if (c == '/') {
			AppController_showAllFromFront(_this);
			// '/' �� ��� ť�� front���� rear���� ���.
		}
		else if (c == '^') {
			AppController_showFrontElement(_this);
			// ^ �� ��� ���� ť�� fornt Element ���.
		}
		else {
			AppController_ignore(_this);
			// �̿��� ���ڴ� ���� ó��.
		}
		AppIO_out_newLine();
		c = AppIO_in_charDirectlyFromKeyboard();
	}
	AppController_endInput(_this);
	// ���α׷��� ����Ǹ� ��� ���� ����.
	AppController_showStatistics(_this);
	AppIO_out_endProgram();
}


AppController* AppController_new() {
	// AppController ��ü ����.
	AppController* _this;
	_this = NewObject(AppController);
	_this->_queue = Queue_new();
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
	return (_this);
}

void AppController_delete(AppController* _this) {
	// AppController ��ü ����.
	Queue_delete(_this->_queue);
	free(_this);
}

void AppController_add(AppController* _this, char aChar) {
	// ť�� aChar�� push�ϴ� �Լ�.
	if (Queue_isFull(_this->_queue)) {
		AppIO_out_queueIsFullAgainstPush(aChar);
	} // ť�� �� á�� ��쿡�� ���� �ʴ´�.
	else {
		// ť�� ���� ������ ���� ��쿡�� Add�Ѵ�.
		Queue_add(_this->_queue, aChar);
		AppController_countAdded(_this);
		AppIO_out_addedElementInQueue(aChar);
	}
}

void AppController_remove1(AppController* _this) {
	// ť���� front�� ��ġ�� ���Ҹ� �����Ѵ�.
	if (Queue_isEmpty(_this->_queue)) {
		AppIO_out_noElementInQueue();
	} // ť�� ��������� Remove���� �ʴ´�.
	else {
		char removedChar = Queue_remove(_this->_queue);
		AppIO_out_removed1ElementFromQueue(removedChar);
	}
}

void AppController_removeN(AppController* _this, int numberOfChars) {
	// numberOfChar �Է� �� ��ŭ ť���� Remove ����.
	if (numberOfChars > Queue_size(_this->_queue)) {
		//AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Queue_isEmpty(_this->_queue)); i++)
		{
			char poppedChar = Queue_remove(_this->_queue);
			AppIO_out_removedNElementFromQueue(poppedChar);
		}
		AppIO_out_queueIsEmptyAgainstPops();
		// �Է� ���� ������� Ŭ ��� ��� �����ϰ� ť�� ����ٴ� �޽��� ���.
	}
	else {
		//AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Queue_isEmpty(_this->_queue)); i++)
		{
			char poppedChar = Queue_remove(_this->_queue);
			AppIO_out_removedNElementFromQueue(poppedChar);
		}
		//AppIO_out_endPops();
		// �Է� ���� ������� ���� ��� �����ŭ ����.
	}
}

void AppController_showAllFromFront(AppController* _this) {
	// ť�� Front���� Rear���� ������� ���Ҹ� ���.
	char queueElement;
	AppIO_out_frontOfQueue();
	for (int i = 0; i < Queue_size(_this->_queue); i++) {
		queueElement = Queue_elementAt(_this->_queue, i);
		AppIO_out_element(queueElement);
	}
	AppIO_out_rearOfQueue();
	AppIO_out_newLine();
}

void AppController_initCountingChars(AppController* _this)
{
	// �Է¼�, ������ ��, Ǫ���� ���� ���� �� ������ ī����.
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
}

void AppController_countInputChars(AppController* _this)
{
	// �Է��� ������ ���� �߰����ش�.
	_this->_inputChars++;
}

void AppController_countIgnoredChars(AppController* _this)
{
	// ������ ������ ���� �߰����ش�.
	_this->_ignoredChars++;
}

void AppController_countAdded(AppController* _this)
{
	// Ǫ���� ������ ���� �߰����ش�.
	_this->_addedChars++;
}

int AppController_numberOfInputChars(AppController* _this)
{
	//�Է��� ������ ���� �߰����ش�.
	return (_this->_inputChars);
}

int AppController_numberOfNormallyProcessedChars(AppController* _this)
{
	// ���� �Էµ� ������ ������ ��ȯ�Ѵ�.
	return (_this->_inputChars - _this->_ignoredChars);
}

int AppController_numberOfIgnoredChars(AppController* _this)
{
	// ������ ������ ���� ��ȯ�Ѵ�.
	return (_this->_ignoredChars);
}

int AppController_numberOfPushedChars(AppController* _this)
{
	// Ǫ���� ������ ���� ��ȯ�Ѵ�.
	return (_this->_addedChars);
}

void AppController_showStatistics(AppController* _this)
{
	// ���ݱ����� ��踦 �������� ��� �ڷ���� ��� ����Ѵ�.
	AppIO_out_newLine();
	AppIO_out_numberOfInputChars(AppController_numberOfInputChars(_this));
	AppIO_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppIO_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppIO_out_numberOfPushedChars(AppController_numberOfPushedChars(_this));
}

void AppController_endInput(AppController* _this) {
	// Esc�� �ԷµǾ� ����Ǹ� ��� ť�� ��� ���ҵ��� ������.
	char Elements;
	AppIO_out_endInput();
	for (int i = 0; i < Queue_size(_this->_queue); i++) {
		Elements = Queue_elementAt(_this->_queue, i);
		AppIO_out_poppedElementByEndInput(Elements);
	}
}

void AppController_showSize(AppController* _this) {
	// �� ť�� size�� ����Ѵ�.
	int size = Queue_size(_this->_queue);
	AppIO_out_numberOfElements(size);
}

void AppController_showFrontElement(AppController* _this) {
	// �� ť�� Front�� �ִ� Element�� ����Ѵ�.
	char anElements = Queue_FrontElement(_this->_queue);
	AppIO_out_FrontElement(anElements);
}

void AppController_ignore(AppController* _this) {
	// ������ ���� �̿��� ���� ��ȿó���Ѵ�.
	AppIO_out_ignoredChar();
	AppController_countIgnoredChars(_this);
}