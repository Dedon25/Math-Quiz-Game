#include <windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <random>
#include <iomanip>
#include <cstdlib>

using namespace std;

int numberOfQuestion,correct_count = 0, wrong_count = 0;
float marks;
char operators[] = {'+','-','*','/'};
string name;

float divisionAns(int,int);
void startGame();
void loading();
void questionsGenerator(int);
void answerChecker(int,char,int,float);
void Correct();
void Wrong();


int main(){
	startGame();
	return 0;
}

void answerChecker(int a,char b,int c,float d){
	switch(b){
		case '+':{
			if(d == (a + c)){
				Correct();
			}
			else{
				Wrong();
			}
			break;
		}
		case '-':{
			if(d == (a - c)){
				Correct();
			}
			else{
				Wrong();
			}
			break;
		}
		case '*':{
			if(d == (a * c)){
				Correct();
			}
			else{
				Wrong();
			}
			break;
		}
		case '/':{
			if(d == divisionAns(a , c)){
				Correct();
			}
			else{
				Wrong();
			}
			break;
		}
	}
	
}

//displays when answer is wrong
void Wrong() {
	cout <<" WRONG" << endl;
	wrong_count++;
}

//displays when answer is correct
void Correct() {
	cout <<" CORRECT" << endl;
	correct_count++;
}

//sets the quotient into having two decimal places
float divisionAns(int dividend,int divider){
    return static_cast<float>(dividend) / divider;
}


//the loading screen
void loading() {
	cout<<endl;
	cout << "Generating questions";
	for (int i = 1; sleep(1)||i <= 3; i++) {
		cout << ".";
	}
	system("cls");
	cout << endl;
	cout << "Get ready...";
	for (int j = 3; sleep(1) || j >= 1; j--) {
		cout <<j<<" ";
	}
	cout << "GO...." << endl;
	system("cls");
}

//generates questions based on operation chosen
void questionsGenerator(int operation) {
	char sign,play_again;
	int first_value,second_value,answer;
	switch(operation){
		case 1:{
			sign = '+';
			break;
		}
		
		case 2:{
			sign = '-';
			break;
		}
		
		case 3:{
			sign = '*';
			break;
		}
		
		case 4:{
			sign = '/';
			break;
		}
		
		case 5:{
			operation = 5;
			break;
		}
		
		default:{
			cout << "invalid option";
			break;
		}
	}

	for (int k = 1; k <= numberOfQuestion; k++) {
		first_value = 50 + rand() % 100;
		second_value = 1 + rand() % 100;
		cout << endl;
		
		if(operation == 5){
			sign = operators[0 + rand() % 4];
		}
		
		cout << "QN" << ":" << first_value <<" "<< sign <<" "<< second_value <<" =";
		cin >> answer;
		cout << endl;
		answerChecker(first_value,sign,second_value,answer);
	    cout << endl;
	
	    cout<<"---------------RESULTS-----------------"<<endl;
	    cout << "You got " << correct_count << " correct" << endl;
	    cout << endl;
	    cout<<"You got " << wrong_count <<" wrong" << endl;
	    cout << endl;
	    marks = (static_cast<float>(correct_count) / numberOfQuestion) * 100;
	    cout << "Marks are: " << marks << "%" << endl;
	    cout<<"---------------------------------------"<<endl;
	    cout << endl;
	    cout << "Do you want to play again?(y/n):";
	    cin >> play_again;
	
	    if( play_again == 'y' || play_again == 'Y'){
		    system("cls);
		    startGame();
	    }
	    else{
		    exit(0);
	    }

    }
}

//game starts here
void startGame(){
	int menu_choice,operation_choice,settings_choice,theme,logo;
	srand(time(0));
	cout << endl;
	logo=1+rand()%3;

	if(logo==1) {
		
		cout << "aaaaaaaaaaaaaaa aaaaaaaaaaaaaaa " << endl;
		cout << "aaaaaaaaaaaaaaa aaaaaaaaaaaaaaa " << endl;
		cout << "aaaaa     aaaaa      aaaaa      " << endl;
		cout << "aaaaaaaaaaaaaaa      aaaaa      " << endl;
		cout << "aaaaaaaaaaaaaaa      aaaaa      " << endl;
		cout << "aaaaa     aaaaa      aaaaa      " << endl;
		cout << "aaaaa     aaaaa      aaaaa      " << endl;
		cout << "aaaaa     aaaaa aaaaaaaaaaaaaaa " << endl;
		cout << "aaaaa     aaaaa aaaaaaaaaaaaaaa " << endl;
		
	} 
	
	else if(logo==2) {
		
		cout<<"############### #####     ##### ############### "<<endl;
		cout<<"############### ######   ###### ############### "<<endl;
		cout<<"#####     ##### ####### ####### #####           "<<endl;
		cout<<"############### ############### #####           "<<endl;
		cout<<"############### ##### ### ##### #####           "<<endl;
		cout<<"#####           #####  #  ##### #####           "<<endl;
		cout<<"#####           #####     ##### ############### "<<endl;
		cout<<"#####           #####     ##### ############### "<<endl;
	} 
	
	else {
		
		cout<<"#####     ##### ############### #####           #####           ############### "<<endl;
		cout<<"#####     ##### ############### #####           #####           ############### "<<endl;
		cout<<"#####     ##### #####           #####           #####           #####     ##### "<<endl;
		cout<<"############### ##########      #####           #####           #####     ##### "<<endl;
		cout<<"############### ##########      #####           #####           #####     ##### "<<endl;
		cout<<"#####     ##### #####           #####           #####           #####     ##### "<<endl;
		cout<<"#####     ##### ############### ############### ############### ###############"<<endl;
		cout<<"#####     ##### ############### ############### ############### ###############"<<endl;
		
	}
	
	cout<<"________________________"<<endl;
	cout<<"*****MATH QUIZ GAME*****"<< endl;
	cout<<"________________________"<<endl;
	cout << "made by: Adon" << endl;
	cout << endl;
	cout << "1.start\n";
	cout << "2.settings\n";
	cout << "3.Exit\n";
	cout << endl;
	cout << "CHOICE: ";
	cin >> menu_choice;
	switch(menu_choice) {
		case 1: {
			cout << "Enter your name: ";
			cin >> name;
			cout << endl;
			cout << "Enter the number of questions: ";
			cin >> numberOfQuestion;
			cout << endl;
			cout << "CHOOSE THE TYPE OF QUESTION:" << endl;
			cout << endl;
			cout << "1.Addition\n";
			cout << "2.Subtraction\n";
			cout << "3.Multiplication\n";
			cout << "4.Division\n";
			cout << "5.Mixed\n";
			cout << endl;
			cout << "CHOICE: ";
			cin >> operation_choice;
			loading();
			questionsGenerator(operation_choice);
			break;
		}
		
		case 2:{
			back_settings:
			system("cls");
			cout << "settings\n";
			cout << "--------\n";
			cout << "1.Theme\n";
			cout << "2.Credits\n";
			cout << "CHOICE: ";
			cin >> settings_choice;
			switch(settings_choice) {
				case 1: {
					system("cls");
					cout << "choose theme:\n";
					cout << "1.Dark theme:\n";
					cout << "2.Light theme:\n";
					cout << endl;
					cout << "CHOICE: ";
					cin >> theme;
					switch(theme) {
						case 1: {
							system("color 0F");
							system("cls");
							startGame();
							break;
						}
						
						case 2: {
							system("color F0");
							system("cls");
							startGame();
							break;
						}
					}
					break;
				}
				
				case 2:{
					system("cls");
					cout << "MADE BY ADON TUMAINI\n";
					cout << "hope you enjoy it :)";
					system("pause");
					startGame();
					break;
				}
				
				default:{
					cout << "invalid choice\n";
					system("pause");
					goto back_settings;
					break;
				}
				break;
			}
			break;
		}
		case 3:{	
			exit(0);
			break;
		}
		
		default:{
			cout << "invalid choice\n";
			system("pause");
			system("cls");
			startGame();
			break;
		}
	}
}
