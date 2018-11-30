#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

char AppIO_in_charDirectlyFromKeyboard()
{ // ������� Ű����κ��� �Է¹��� ���ڸ� ���� �ʿ���� �ٷ� �����Ѵ�.
	printf(">���ڸ� �Է��Ͻÿ� : ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppIO_out_newLine();
	return charDirectlyFromKeyboard;
}

char getCharDirectlyFromKeyboard(void)
{ /*���� ���͸� ������ ����� �ƴ� Ű���忡��
  ������ ���� �ٷ� �ν��ϵ��� �ϴ� �Լ�*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}


void AppIO_out_queueIsFullAgainstPush(char aChar)
{
	printf("[Full] ť�� �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", aChar);
}
void AppIO_out_addedElementInQueue(char anElement)
{
	printf("[Add] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n", anElement) ;
}
void AppIO_out_noElementInQueue()
{
	printf("[Empty] ť�� ������ ���Ұ� �����ϴ�.\n");
}
void AppIO_out_removed1ElementFromQueue(char anElement)
{
	printf("[Remove1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppIO_out_removedNElementFromQueue(char anElement)
{
	printf("[RemoveN] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppIO_out_beginPops(int numberOfElements)
{
	printf("[Pops] % d ���� ���Ҹ� �����Ϸ��� �մϴ� : \n", numberOfElements);
}
void AppIO_out_endPops()
{
	printf("[Pops] ������ �����մϴ�. \n");
}
void AppIO_out_queueIsEmptyAgainstPops()
{
	printf("[Empty] ť�� �� �̻� ������ ���Ұ� �����ϴ�.\n") ;
}
void AppIO_out_FrontElement(char anElement)
{
	printf("[Front] Front ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}
void AppIO_out_noFrontElement()
{
	printf("[Empty] ���� ť�� ��� �ֽ��ϴ�.\n");
}

void AppIO_out_frontOfQueue()
{
	printf("[Queue] <Front>");
}
void AppIO_out_element(char anElement)
{
	printf(" %c", anElement);
}
void AppIO_out_rearOfQueue()
{
	printf(" <Rear>");
}
void AppIO_out_newLine()
{
	printf("\n");
}
void AppIO_out_queueSize(int stackSize)
{
	printf("[Size] ���� ť�� ũ��� %d �Դϴ�.\n", stackSize);
}
void AppIO_out_ignoredChar()
{
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}
void AppIO_out_endInput()
{
	printf("[End Input] �Է��� �����ϸ�, ť�� ��� ���Ҹ� �����մϴ� : \n");
}
void AppIO_out_poppedElementByEndInput(char anElement)
{
	printf(" [Esc] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppIO_out_numberOfInputChars(int numberOfChars)
{
	printf("�����Էµ� ���ڴ� ��� %d �� �Դϴ�.\n", numberOfChars);
}
void AppIO_out_numberOfNormallyProcessedChars(int numberOfChars)
{
	printf("������������ ó���� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}
void AppIO_out_numberOfIgnoredChars(int numberOfChars)
{
	printf("�������õ� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}
void AppIO_out_numberOfPushedChars(int numberOfChars)
{
	printf("�������Ե� ���ڴ� %d �� �Դϴ�.\n ", numberOfChars);
}
void AppIO_out_startProgram()
{
	printf("<<< Queue Ȱ�� ���α׷��� �����մϴ� >>>\n ");
	AppIO_out_newLine();
}
void AppIO_out_endProgram()
{
	AppIO_out_newLine();
	printf(" <<< Queue Ȱ�� ���α׷��� �����մϴ� >>>\n ");
}

void AppIO_out_numberOfElements(int numberOfChars) {
	printf("[Size] ť���� ���� %d���� ���Ұ� �ֽ��ϴ�.\n", numberOfChars);
}
