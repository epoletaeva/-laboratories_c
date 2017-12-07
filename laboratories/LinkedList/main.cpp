#include <iostream>

using namespace std;
class IntNode{
	//����� ���� ������
private:
	int elem;
	IntNode* next;
	friend class IntLinkedList;
};
//-------------------------------------
class IntLinkedList{
	//���������� ��� ����� ���������� ������
public:
	//��������� �������������
	IntLinkedList();
	~IntLinkedList();
	//��������� �������
	bool empty() const; //��������, ������ ������ ��� ���
	//����� ���������� �������� � ������ ������
	void addFront (const int& e);
	//����� �������� �������� �� ������ ������
	void removeFront();
	void print() const; //����� ������ ���� ��������� ������ �� �����

private:
	IntNode *head; //��������� �� ������ ������ (������)
};
//�����������. ������� ����� �������� ������ + :: + ��� ������������ + � ������� �������� ���������
IntLinkedList::IntLinkedList():head(NULL) {}
//���������� ��� ������������ ������. ������� ���������� ������������
IntLinkedList::~IntLinkedList(){
	//���� ������ �� ������
	while ( !empty() )
	{
		//���� �����
		removeFront();
	}
}
bool IntLinkedList::empty() const{
	//���������� ������
	//true - ���� �������� ������� ����� NULL, �.�. ������ ������, false - ���� ������ �� ������
	return head == NULL;}
//����� ����������
void IntLinkedList::addFront(const int& e){
	//���������� ������ ����������
	IntNode *v = new IntNode; //����������� �������� ������ ��� ����� �������
	v->elem = e;
	v->next = head;
	head = v; //��������� ������� �������� ��������� �� ����� ����������� �������
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