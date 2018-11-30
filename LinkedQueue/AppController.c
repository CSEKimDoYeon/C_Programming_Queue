#include "AppController.h"
#include "AppIO.h"

void AppController_run(AppController* _this) { // 프로그램 실행 함수.
	AppIO_out_startProgram();
	AppController_initCountingChars(_this);
	AppIO_out_newLine();
	char c = AppIO_in_charDirectlyFromKeyboard();
	// 키보드로 입력받은 문자를 직접 삽입.

	while (c != Esc) { // Esc가 입력 될 때 까지 진행.
		AppController_countInputChars(_this);
		if (isAlpha(c)) {
			AppController_add(_this, c);
			// 알파벳일경우 큐에 Add
		}
		else if (isDigit(c)) {
			int digitValue = c - '0';
			AppController_removeN(_this, digitValue);
			// 숫자일경우 숫자만큼 Remove
		}
		else if (c == '-') {
			AppController_remove1(_this);
			// - 일 경우 하나를 Remove
		}
		else if (c == '#') {
			AppController_showSize(_this);
			// # 일 경우 큐의 사이즈 출력.
		}
		else if (c == '/') {
			AppController_showAllFromFront(_this);
			// '/' 일 경우 큐의 front부터 rear까지 출력.
		}
		else if (c == '^') {
			AppController_showFrontElement(_this);
			// ^ 일 경우 현재 큐의 fornt Element 출력.
		}
		else {
			AppController_ignore(_this);
			// 이외의 문자는 무시 처리.
		}
		AppIO_out_newLine();
		c = AppIO_in_charDirectlyFromKeyboard();
	}
	AppController_endInput(_this);
	// 프로그램이 종료되면 모든 원소 삭제.
	AppController_showStatistics(_this);
	AppIO_out_endProgram();
}


AppController* AppController_new() {
	// AppController 객체 생성.
	AppController* _this;
	_this = NewObject(AppController);
	_this->_queue = Queue_new();
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
	return (_this);
}

void AppController_delete(AppController* _this) {
	// AppController 객체 삭제.
	Queue_delete(_this->_queue);
	free(_this);
}

void AppController_add(AppController* _this, char aChar) {
	// 큐에 aChar를 push하는 함수.
	if (Queue_isFull(_this->_queue)) {
		AppIO_out_queueIsFullAgainstPush(aChar);
	} // 큐가 꽉 찼을 경우에는 넣지 않는다.
	else {
		// 큐에 남은 공간이 있을 경우에는 Add한다.
		Queue_add(_this->_queue, aChar);
		AppController_countAdded(_this);
		AppIO_out_addedElementInQueue(aChar);
	}
}

void AppController_remove1(AppController* _this) {
	// 큐에서 front에 위치한 원소를 삭제한다.
	if (Queue_isEmpty(_this->_queue)) {
		AppIO_out_noElementInQueue();
	} // 큐가 비어있으면 Remove하지 않는다.
	else {
		char removedChar = Queue_remove(_this->_queue);
		AppIO_out_removed1ElementFromQueue(removedChar);
	}
}

void AppController_removeN(AppController* _this, int numberOfChars) {
	// numberOfChar 입력 수 만큼 큐에서 Remove 실행.
	if (numberOfChars > Queue_size(_this->_queue)) {
		//AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Queue_isEmpty(_this->_queue)); i++)
		{
			char poppedChar = Queue_remove(_this->_queue);
			AppIO_out_removedNElementFromQueue(poppedChar);
		}
		AppIO_out_queueIsEmptyAgainstPops();
		// 입력 수가 사이즈보다 클 경우 모두 삭제하고 큐가 비었다는 메시지 출력.
	}
	else {
		//AppIO_out_beginPops(numberOfChars);
		for (int i = 0; (i < numberOfChars) && (!Queue_isEmpty(_this->_queue)); i++)
		{
			char poppedChar = Queue_remove(_this->_queue);
			AppIO_out_removedNElementFromQueue(poppedChar);
		}
		//AppIO_out_endPops();
		// 입력 수가 사이즈보다 작을 경우 사이즈만큼 삭제.
	}
}

void AppController_showAllFromFront(AppController* _this) {
	// 큐의 Front부터 Rear까지 순서대로 원소를 출력.
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
	// 입력수, 무시한 수, 푸쉬한 수를 실행 될 때마다 카운팅.
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
}

void AppController_countInputChars(AppController* _this)
{
	// 입력한 문자의 수를 추가해준다.
	_this->_inputChars++;
}

void AppController_countIgnoredChars(AppController* _this)
{
	// 무시한 문자의 수를 추가해준다.
	_this->_ignoredChars++;
}

void AppController_countAdded(AppController* _this)
{
	// 푸쉬한 문자의 수를 추가해준다.
	_this->_addedChars++;
}

int AppController_numberOfInputChars(AppController* _this)
{
	//입력한 문자의 수를 추가해준다.
	return (_this->_inputChars);
}

int AppController_numberOfNormallyProcessedChars(AppController* _this)
{
	// 순수 입력된 문자의 개수를 반환한다.
	return (_this->_inputChars - _this->_ignoredChars);
}

int AppController_numberOfIgnoredChars(AppController* _this)
{
	// 무시한 문자의 수를 반환한다.
	return (_this->_ignoredChars);
}

int AppController_numberOfPushedChars(AppController* _this)
{
	// 푸쉬한 문자의 수를 반환한다.
	return (_this->_addedChars);
}

void AppController_showStatistics(AppController* _this)
{
	// 지금까지의 통계를 바탕으로 통계 자료들을 모두 출력한다.
	AppIO_out_newLine();
	AppIO_out_numberOfInputChars(AppController_numberOfInputChars(_this));
	AppIO_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppIO_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppIO_out_numberOfPushedChars(AppController_numberOfPushedChars(_this));
}

void AppController_endInput(AppController* _this) {
	// Esc가 입력되어 종료되면 모든 큐의 모든 원소들을 꺼낸다.
	char Elements;
	AppIO_out_endInput();
	for (int i = 0; i < Queue_size(_this->_queue); i++) {
		Elements = Queue_elementAt(_this->_queue, i);
		AppIO_out_poppedElementByEndInput(Elements);
	}
}

void AppController_showSize(AppController* _this) {
	// 현 큐의 size를 출력한다.
	int size = Queue_size(_this->_queue);
	AppIO_out_numberOfElements(size);
}

void AppController_showFrontElement(AppController* _this) {
	// 현 큐의 Front에 있는 Element를 출력한다.
	char anElements = Queue_FrontElement(_this->_queue);
	AppIO_out_FrontElement(anElements);
}

void AppController_ignore(AppController* _this) {
	// 지정된 문자 이외의 것을 무효처리한다.
	AppIO_out_ignoredChar();
	AppController_countIgnoredChars(_this);
}