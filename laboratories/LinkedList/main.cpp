#include <iostream>

using namespace std;
class IntNode{
	//Класс узла списка
private:
	int elem;
	IntNode* next;
	friend class IntLinkedList;
};
//-------------------------------------
class IntLinkedList{
	//Собственно сам класс связанного списка
public:
	//Прототипы конструкторов
	IntLinkedList();
	~IntLinkedList();
	//Прототипы методов
	bool empty() const; //Проверка, пустой список или нет
	//Метод добавления элемента в начало списка
	void addFront (const int& e);
	//Метод удаления элемента из начала списка
	void removeFront();
	void print() const; //Метод вывода всех элементов списка на экран

private:
	IntNode *head; //Указатель на начало списка (голова)
};
//Конструктор. Сначала пишем название класса + :: + Имя конструктора + в скобках входящие параметры
IntLinkedList::IntLinkedList():head(NULL) {}
//Деструктор для освобождения памяти. Пишется аналогично конструктору
IntLinkedList::~IntLinkedList(){
	//Пока список не пустой
	while ( !empty() )
	{
		//тело цикла
		removeFront();
	}
}
bool IntLinkedList::empty() const{
	//Реализация метода
	//true - если головной элемент равен NULL, т.е. список пустой, false - если список не пустой
	return head == NULL;}
//Метод добавления
void IntLinkedList::addFront(const int& e){
	//Реализация метода добавления
	IntNode *v = new IntNode; //Динамически выделили память под новый элемент
	v->elem = e;
	v->next = head;
	head = v; //Присвоили первому элементу указатель на вновь добавленный элемент
}
void IntLinkedList::removeFront(){
	IntNode* old = head;
	head = old->next;
	delete old;
}
void IntLinkedList::print() const {
	IntNode* flag = head;
	while ( flag ->next != 0)
	{
		cout<<flag->elem<<endl;
		flag = flag->next;
	}
}


int main (){
	IntLinkedList test_list();
	test_list.addFront("720");
	return 0;
}