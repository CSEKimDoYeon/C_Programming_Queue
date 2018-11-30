
char AppIO_in_charDirectlyFromKeyboard();
char getCharDirectlyFromKeyboard(void);

void AppIO_out_queueIsFullAgainstPush(char anElementForPush);
void AppIO_out_addedElementInQueue(char anElement);
void AppIO_out_noElementInQueue();
//void AppIO_out_removedElementFromQueue(char anElement);
void AppIO_out_beginPops(int numberOfElements);
void AppIO_out_endPops();
void AppIO_out_queueIsEmptyAgainstPops();
void AppIO_out_FrontElement(char anElement);
void AppIO_out_noFrontElement();
void AppIO_out_frontOfQueue();
void AppIO_out_element(char anElement);
void AppIO_out_rearOfQueue();
void AppIO_out_newLine();
void AppIO_out_queueSize(int stackSize);
void AppIO_out_ignoredChar();
void AppIO_out_endInput();
void AppIO_out_poppedElementByEndInput(char anElement);
void AppIO_out_numberOfInputChars(int numberOfChars);
void AppIO_out_numberOfNormallyProcessedChars(int numberOfChars);
void AppIO_out_numberOfIgnoredChars(int numberOfChars);
void AppIO_out_numberOfPushedChars(int numberOfChars);
void AppIO_out_startProgram();
void AppIO_out_endProgram();
void AppIO_out_numberOfElements(int numberOfChars);