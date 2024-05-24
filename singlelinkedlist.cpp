#include <iostream>
using namespace std;

// Node 클래스 템플릿
template <class T>

class Node { // 노드 클래스
public:
    T data;       // 데이터 저장
    Node* next;   // 다음 노드를 가리키는 포인터

    Node(T value) : data(value), next(nullptr) {}  // 생성자
};

// 단일 연결 리스트 클래스 템플릿
template <class T>
class singleLinkedList {
public:
    singleLinkedList();  // 생성자
    ~singleLinkedList(); // 소멸자
    void push(T element); // element를 리스트의 마지막 원소로 넣는 함수
    void show(); // 리스트의 모든 원소값을 출력하는 함수

private:
    Node<T>* head; // 리스트의 첫 번째 원소
    Node<T>* tail; // 리스트의 마지막 원소
};

// 생성자 - 리스트 초기화
template <class T>
singleLinkedList<T>::singleLinkedList() : head(nullptr), tail(nullptr) {}

// 소멸자 - 리스트의 모든 노드 삭제
template <class T>
singleLinkedList<T>::~singleLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

// push 함수 - 리스트의 마지막에 노드 추가
template <class T>
void singleLinkedList<T>::push(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (tail == nullptr) { // 리스트가 비어있는 경우
        head = newNode;
        tail = newNode;
    }
    else { // 리스트에 원소가 있는 경우
        tail->next = newNode;
        tail = newNode;
    }
}

// show 함수 - 리스트의 모든 원소 출력
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

// main 함수
int main() {
    singleLinkedList<int>* idx = new singleLinkedList<int>;
    idx->push(1);
    idx->push(2);
    idx->push(3);
    idx->push(4);
    idx->push(5);
    idx->show();

    delete idx; // 할당된 메모리 해제
    return 0;
}
