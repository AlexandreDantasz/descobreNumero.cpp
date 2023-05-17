#include <iostream>
#include <math.h>
#include <locale.h>

int questions = 0;

using namespace std;

int where(int *p, int low, int high)
{
	string answer;
	int mid = (low + high) / 2;
	if(low == high)
	{
		printf("seu n�mero � %i!\n", p[mid]);
		return questions;
	}
	questions++;
	printf("seu n�mero � maior, menor ou igual a %i?\nR: ", p[mid]);
	cin >> answer;
	for(int i = 0; i < answer.size(); i++) answer[i] = tolower(answer[i]);
	while(answer != "igual" and answer != "maior" and answer != "menor")
	{
		puts("A resposta foi escrita de maneira incorreta, tente novamente.");
		printf("seu n�mero � maior, menor ou igual a %i?\nR: ", p[mid]);
		cin >> answer;
		for(int i = 0; i < answer.size(); i++) answer[i] = tolower(answer[i]);
	}
	if(answer == "igual") 
	{
		puts("kkkk achei!"); 
		return questions;
	}
	if(answer == "maior") return where(p, mid + 1, high);
	return where(p, low, mid - 1);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	printf("seu n�mero inteiro est� entre 1 e ");
	int size, maxOfQuestions;
	cin >> size;
	maxOfQuestions = (int)round(log(size)/log(2));
	printf("tenho que descobrir seu n�mero inteiro com no m�ximo %i perguntas!\n", maxOfQuestions);
	int vet[size];
	for(int i = 1; i <= size; i++) vet[i - 1] = i;
	int numberOfQuestions = where(vet, 0, size - 1);
	printf("n�mero de perguntas feitas: %i\n", numberOfQuestions);
	return 0;
}
