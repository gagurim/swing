#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ȸ�� ������ �����ϴ� Ŭ����
class Information {
private:
    string name;
    string phoneNumber;

public:
    // ������
    Information(string n, string p) : name(n), phoneNumber(p) {}

    // �̸� ��ȯ �Լ�
    string getName() {
        return name;
    }

    // ��ȭ��ȣ ��ȯ �Լ�
    string getPhonenumber() {
        return phoneNumber;
    }

    // �̸��� ��ȭ��ȣ�� ��ġ�ϴ��� Ȯ���ϴ� �Լ�
    bool isEqual(const string* n, const string* p) {
        return (name == *n && phoneNumber == *p);
    }

    // ȸ�� ���� ���� �Լ�
    void updateInformation(string newName, string newPhoneNumber) {
        name = newName;
        phoneNumber = newPhoneNumber;
    }
};

int main() {
    vector<Information> members; // ȸ�� ������ �����ϴ� ����

    while (true) {
        // �ʱ�ȭ�� 
        cout << "***** SWING ȸ�� ���� ���� ���α׷� *****" << endl;
        cout << "1. ȸ������\n2. �α���\n3. ȸ�� ���� ����\n4. ����" << endl;
        cout << "��ȣ�� �Է��ϼ���: ";

        int num;
        cin >> num;

        if (num == 1) {
            // ȸ������
            string name, phoneNumber;
            cout << "�̸��� �Է��ϼ���: ";
            cin >> name;
            cout << "��ȭ��ȣ�� �Է��ϼ���: ";
            cin >> phoneNumber;

            // ������ ��ϵ� ȸ�� �������� Ȯ��
            bool found = false;
            for (auto& member : members) {
                if (member.isEqual(&name, &phoneNumber)) {
                    found = true;
                    cout << "�̹� ��ϵ� �����Դϴ�." << endl;
                    break;
                }
            }
            if (!found) {
                members.push_back(Information(name, phoneNumber));
                cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
            }
        }
        else if (num == 2) {
            // �α���
            string name, phoneNumber;
            cout << "***** �α����� �����մϴ� *****" << endl << endl;
            cout << "�̸��� �Է��ϼ���: ";
            cin >> name;
            cout << "��ȭ��ȣ�� �Է��ϼ���: ";
            cin >> phoneNumber;

            // ȸ�� ������ �ִ��� Ȯ��
            bool found = false;
            for (auto& member : members) {
                if (member.isEqual(&name, &phoneNumber)) {
                    cout << "�α����� �Ϸ�Ǿ����ϴ�." << endl << endl << "***** SWING " << name << "���� �����մϴ� *****" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "ȸ�� ������ ��ġ���� �ʽ��ϴ�." << endl;
            }
        }
        else if (num == 3) {
            // ȸ�� ���� ����
            string name, phoneNumber;
            cout << "���� ȸ�� ������ �Է��ϼ���." << endl;
            cout << "�̸�: ";
            cin >> name;
            cout << "��ȭ��ȣ: ";
            cin >> phoneNumber;

            // ������ ��ϵ� ȸ�� �������� Ȯ��
            bool found = false;
            for (auto& member : members) {
                if (member.isEqual(&name, &phoneNumber)) {
                    found = true;
                    string newName, newPhoneNumber;
                    cout << "���ο� ȸ�� ������ �Է��ϼ���." << endl;
                    cout << "�̸�: ";
                    cin >> newName;
                    cout << "��ȭ��ȣ: ";
                    cin >> newPhoneNumber;

                    // ���ο� ������ �̹� �����ϴ��� Ȯ��
                    bool newInfoExists = false;
                    for (auto& otherMember : members) {
                        if (otherMember.isEqual(&newName, &newPhoneNumber)) {
                            newInfoExists = true;
                            cout << "���ο� ������ �̹� �����մϴ�. �ߺ��� ������ ������ �� �����ϴ�." << endl;
                            break;
                        }
                    }

                    if (!newInfoExists) {
                        member.updateInformation(newName, newPhoneNumber);
                        cout << "ȸ�� ������ �����Ǿ����ϴ�." << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "��ϵ��� ���� ȸ�� �����Դϴ�." << endl;
            }
        }
        else if (num == 4) {
            // ����
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "��Ȯ�� ��ȣ�� �Է����ּ���." << endl;
        }
    }

    return 0;
}


