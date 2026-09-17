#include<iostream>

using namespace std;

enum enLevelQuestion { easy = 1, med, hard, mixLevel };

enum enTypeOperator { add = 1, sub, mul, divide, mixOperater };

enum enResult { pass = 1, fail };

struct stQuestion {
	int num1 = 0;
	int num2 = 0;
	enLevelQuestion levelOfQuestion;
	enTypeOperator symbol;
	int playerResult = 0;
	int result = 0;
};

struct stQuiz {
	stQuestion questionList[100];
	short numberOfQuestions = 0;
	enLevelQuestion levelOfQuestions;
	enTypeOperator symbol;
	short wrongAnswers = 0;
	short rightAnswer = 0;
	enResult result;

};

int randomNumbersByRange(int from, int to) {
	return rand() % (to - from + 1) + from;
}

short shortNumber(string message) {
	short numberOfQuestion = 0;
	do {
		cout << message << endl;
		cin >> numberOfQuestion;

	} while (numberOfQuestion <= 0);
	return numberOfQuestion;
}

short levelOfQuestion(string message) {
	short levelOfQuestion = 0;
	do {
		cout << message << endl;
		cin >> levelOfQuestion;

	} while (levelOfQuestion > 4 || levelOfQuestion <= 0);
	return levelOfQuestion;
}

enLevelQuestion levelQuestion(short levelOfQuestion) {
	switch (levelOfQuestion) {
	case 1:
		return enLevelQuestion::easy;
	case 2:
		return enLevelQuestion::med;
	case 3:
		return enLevelQuestion::hard;
	default:
		return enLevelQuestion::mixLevel;
	}
}

string wordOfTheLevelOfQuestion(enLevelQuestion levelOfQyestion) {
	string wordOfLevel[4] = { "easy", "med", "hard", "mix" };
	return wordOfLevel[levelOfQyestion - 1];
}

short operaterOfQuestion(string message) {
	short operaterOfQuestion = 0;
	do {
		cout << message << endl;
		cin >> operaterOfQuestion;

	} while (operaterOfQuestion > 5 || operaterOfQuestion <= 0);
	return operaterOfQuestion;
}

enTypeOperator typeOperater(short operaterOfQuestion) {
	switch (operaterOfQuestion) {
	case 1:
		return enTypeOperator::add;
	case 2:
		return enTypeOperator::sub;
	case 3:
		return enTypeOperator::mul;
	case 4:
		return enTypeOperator::divide;
	default:
		return enTypeOperator::mixOperater;
	}
}

string wordOfTheTypeOperaterOfQuestion(enTypeOperator typeOperaterOfQyestion) {
	string wordOfTypeOperater[5] = { "add", "sub", "mul", "div", "mix" };
	return wordOfTypeOperater[typeOperaterOfQyestion - 1];
}

string symbolOfTheTypeOperaterOfQuestion(enTypeOperator typeOperaterOfQyestion) {
	string wordOfTypeOperater[4] = { "+", "-", "*", "/" };
	return wordOfTypeOperater[typeOperaterOfQyestion - 1];
}

void selectResultOfQuestion(stQuestion& question) {
	switch (question.symbol) {
	case 1:
		question.result = question.num1 + question.num2;
		break;
	case 2:
		question.result = question.num1 - question.num2;
		break;
	case 3:
		question.result = question.num1 * question.num2;
		break;
	default:
		question.result = question.num1 / question.num2;
		break;
	}
}

stQuestion selectNumbersByLevelOfQuestion(stQuestion& question) {
	switch (question.levelOfQuestion) {
	case 1:
		question.num1 = randomNumbersByRange(1, 10);
		question.num2 = randomNumbersByRange(1, 10);
		selectResultOfQuestion(question);
		question.levelOfQuestion = levelQuestion(1);
		return question;
	case 2:
		question.num1 = randomNumbersByRange(-10, 10);
		question.num2 = randomNumbersByRange(-10, 10);
		selectResultOfQuestion(question);
		question.levelOfQuestion = levelQuestion(2);
		return question;
	default:
		question.num1 = randomNumbersByRange(-50, 50);
		question.num2 = randomNumbersByRange(-50, 50);
		selectResultOfQuestion(question);
		question.levelOfQuestion = levelQuestion(3);
		return question;
	}
}


stQuestion makeQuestion(enLevelQuestion levelQuestio, enTypeOperator typeOperate) {
	stQuestion question;
	if (levelQuestio == enLevelQuestion::mixLevel) {
		levelQuestio = levelQuestion(randomNumbersByRange(1, 3));
	}
	if (typeOperate == enTypeOperator::mixOperater) {
		typeOperate = typeOperater(randomNumbersByRange(1, 4));
	}

	question.symbol = typeOperate;
	return selectNumbersByLevelOfQuestion(question);
}

void makeQuiz(stQuiz& quiz) {
	for (short q = 0; q < quiz.numberOfQuestions; q++) {
		quiz.questionList[q] = makeQuestion(quiz.levelOfQuestions, quiz.symbol);
	}
}

void changeColorScreen(enResult result) {

	if (result == enResult::fail) {
		system("Color 40");
		cout << "\a";
	}
	else {
		system("Color 20");
	}
}

void isRigthAnswer(stQuiz& quiz, short numberOfQuestion) {
	if (quiz.questionList[numberOfQuestion].playerResult != quiz.questionList[numberOfQuestion].result) {
		quiz.wrongAnswers++;
		cout << "wrong answer :-(\n";
		cout << "the rigth answer is " << quiz.questionList[numberOfQuestion].result << endl << endl;
		changeColorScreen(enResult::fail);
	}
	else {
		quiz.rightAnswer++;
		cout << "right answer :-)\n\n";
		changeColorScreen(enResult::pass);
	}
}

void printQuestionInfo(stQuiz& quiz, short numberOfQuestion) {
	cout << "question[" << numberOfQuestion + 1 << "/" << quiz.numberOfQuestions << "] begain:" << endl;
	cout << quiz.questionList[numberOfQuestion].num1 << " " << symbolOfTheTypeOperaterOfQuestion(quiz.questionList[numberOfQuestion].symbol) << endl;
	cout << quiz.questionList[numberOfQuestion].num2 << endl << "___________________________________________________________ \n";
}

void restSetting() {
	system("cls");
	system("color 0F");
}

void askAndCorrectQuestionAnswers(stQuiz& quiz) {
	;
	for (int q = 0; q < quiz.numberOfQuestions; q++) {
		printQuestionInfo(quiz, q);
		cin >> quiz.questionList[q].playerResult;

		isRigthAnswer(quiz, q);
	}
	quiz.result = (quiz.rightAnswer >= quiz.wrongAnswers) ? enResult::pass : enResult::fail;
}

void isPass(enResult res) {
	if (res == enResult::pass) {
		cout << "pass";
	}
	else
		cout << "fail";
}

void printQuizResult(stQuiz quiz) {
	cout << "\n ----------------------------------------\n";
	cout << " final result is "; isPass(quiz.result);
	cout << "\n ----------------------------------------\n";
	cout << "\n ----------------------------------------\n";
	cout << "number of quistion:" << quiz.numberOfQuestions << endl;
	cout << "level of quistion:" << wordOfTheLevelOfQuestion(quiz.levelOfQuestions) << endl;
	cout << "op of quistion:" << wordOfTheTypeOperaterOfQuestion(quiz.symbol) << endl;
	cout << "number of right answer:" << quiz.rightAnswer << endl;
	cout << "number of wrong answer:" << quiz.wrongAnswers << endl;
	cout << "\n ----------------------------------------\n";
}

void play() {
	stQuiz quiz;
	quiz.numberOfQuestions = shortNumber("enter number of question");
	quiz.levelOfQuestions = levelQuestion(levelOfQuestion("enter question level [1]easy, [2]med, [3]hard, [4]mix ?"));
	quiz.symbol = typeOperater(operaterOfQuestion("enter question opertaion [1]add, [2]sub, [3]mul, [4]div, [5]mix ?"));

	makeQuiz(quiz);
	askAndCorrectQuestionAnswers(quiz);
	printQuizResult(quiz);
}

void startMath() {
	char playMore;
	do {
		restSetting();
		play();
		cout << "do you want to play again? (Y/N)" << endl;
		cin >> playMore;

	} while (playMore != 'n' && playMore != 'N');
}

int main() {
	srand((unsigned)time(NULL));
	startMath();
	return 0;
}