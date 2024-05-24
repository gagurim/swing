#include <iostream>
using namespace std;

// Node Ŭ���� ���ø�
template <class T>

class Node { // ��� Ŭ����
public:
    T data;       // ������ ����
    Node* next;   // ���� ��带 ����Ű�� ������

    Node(T value) : data(value), next(nullptr) {}  // ������
};

// ���� ���� ����Ʈ Ŭ���� ���ø�
template <class T>
class singleLinkedList {
public:
    singleLinkedList();  // ������
    ~singleLinkedList(); // �Ҹ���
    void push(T element); // element�� ����Ʈ�� ������ ���ҷ� �ִ� �Լ�
    void show(); // ����Ʈ�� ��� ���Ұ��� ����ϴ� �Լ�

private:
    Node<T>* head; // ����Ʈ�� ù ��° ����
    Node<T>* tail; // ����Ʈ�� ������ ����
};

// ������ - ����Ʈ �ʱ�ȭ
template <class T>
singleLinkedList<T>::singleLinkedList() : head(nullptr), tail(nullptr) {}

// �Ҹ��� - ����Ʈ�� ��� ��� ����
template <class T>
singleLinkedList<T>::~singleLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

// push �Լ� - ����Ʈ�� �������� ��� �߰�
template <class T>
void singleLinkedList<T>::push(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (tail == nullptr) { // ����Ʈ�� ����ִ� ���
        head = newNode;
        tail = newNode;
    }
    else { // ����Ʈ�� ���Ұ� �ִ� ���
        tail->next = newNode;
        tail = newNode;
    }
}

// show �Լ� - ����Ʈ�� ��� ���� ���
template <class T>
void singleLinkedList<T>::show() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) {
            cout << " -> ";
        }
    }
    cout << " ->" << endl;
}

// main �Լ�
int main() {
    singleLinkedList<int>* idx = new singleLinkedList<int>;
    idx->push(1);
    idx->push(2);
    idx->push(3);
    idx->push(4);
    idx->push(5);
    idx->show();

    delete idx; // �Ҵ�� �޸� ����
    return 0;
}
