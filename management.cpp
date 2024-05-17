#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 회원 정보를 저장하는 클래스
class Information {
private:
    string name;
    string phoneNumber;

public:
    // 생성자
    Information(string n, string p) : name(n), phoneNumber(p) {}

    // 이름 반환 함수
    string getName() {
        return name;
    }

    // 전화번호 반환 함수
    string getPhonenumber() {
        return phoneNumber;
    }

    // 이름과 전화번호가 일치하는지 확인하는 함수
    bool isEqual(const string* n, const string* p) {
        return (name == *n && phoneNumber == *p);
    }

    // 회원 정보 수정 함수
    void updateInformation(string newName, string newPhoneNumber) {
        name = newName;
        phoneNumber = newPhoneNumber;
    }
};

int main() {
    vector<Information> members; // 회원 정보를 저장하는 벡터

    while (true) {
        // 초기화면 
        cout << "***** SWING 회원 정보 관리 프로그램 *****" << endl;
        cout << "1. 회원가입\n2. 로그인\n3. 회원 정보 수정\n4. 종료" << endl;
        cout << "번호를 입력하세요: ";

        int num;
        cin >> num;

        if (num == 1) {
            // 회원가입
            string name, phoneNumber;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> phoneNumber;

            // 기존에 등록된 회원 정보인지 확인
            bool found = false;
            for (auto& member : members) {
                if (member.isEqual(&name, &phoneNumber)) {
                    found = true;
                    cout << "이미 등록된 정보입니다." << endl;
                    break;
                }
            }
            if (!found) {
                members.push_back(Information(name, phoneNumber));
                cout << "회원가입이 완료되었습니다." << endl;
            }
        }
        else if (num == 2) {
            // 로그인
            string name, phoneNumber;
            cout << "***** 로그인을 진행합니다 *****" << endl << endl;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> phoneNumber;

            // 회원 정보가 있는지 확인
            bool found = false;
            for (auto& member : members) {
                if (member.isEqual(&name, &phoneNumber)) {
                    cout << "로그인이 완료되었습니다." << endl << endl << "***** SWING " << name << "님을 응원합니다 *****" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "회원 정보가 일치하지 않습니다." << endl;
            }
        }
        else if (num == 3) {
            // 회원 정보 수정
            string name, phoneNumber;
            cout << "현재 회원 정보를 입력하세요." << endl;
            cout << "이름: ";
            cin >> name;
            cout << "전화번호: ";
            cin >> phoneNumber;

            // 기존에 등록된 회원 정보인지 확인
            bool found = false;
            for (auto& member : members) {
                if (member.isEqual(&name, &phoneNumber)) {
                    found = true;
                    string newName, newPhoneNumber;
                    cout << "새로운 회원 정보를 입력하세요." << endl;
                    cout << "이름: ";
                    cin >> newName;
                    cout << "전화번호: ";
                    cin >> newPhoneNumber;

                    // 새로운 정보가 이미 존재하는지 확인
                    bool newInfoExists = false;
                    for (auto& otherMember : members) {
                        if (otherMember.isEqual(&newName, &newPhoneNumber)) {
                            newInfoExists = true;
                            cout << "새로운 정보가 이미 존재합니다. 중복된 정보로 변경할 수 없습니다." << endl;
                            break;
                        }
                    }

                    if (!newInfoExists) {
                        member.updateInformation(newName, newPhoneNumber);
                        cout << "회원 정보가 수정되었습니다." << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "등록되지 않은 회원 정보입니다." << endl;
            }
        }
        else if (num == 4) {
            // 종료
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "정확한 번호를 입력해주세요." << endl;
        }
    }

    return 0;
}


