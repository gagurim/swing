#include <iostream>
using namespace std;

class Circle { // 평면 원 클래스
public:
    double pie = 3.14;
    double radius;

    Circle() { // 생성자
        cout << "***평면 원 계산기 접속***" << endl;
    }

    ~Circle() { // 소멸자
        cout << "평면 원 계산기 종료..." << endl;
    }

    double area() { // 원 넓이 계산 함수
        return pie * radius * radius;
    }

    double round() { // 원 둘레 계산 함수
        return 2 * pie * radius;
    }
};

class Cylinder { // 원기둥 클래스
public:
    double pie = 3.14;
    double radius;
    double height;

    Cylinder() { // 생성자
        cout << "***원기둥 계산기 접속***" << endl;
    }

    ~Cylinder() { // 소멸자
        cout << "원기둥 계산기 종료..." << endl;
    }

    double cylinder_volume() { // 원기둥의 부피 계산 함수
        return pie * radius * radius * height;
    }

    double cylinder_surface() { // 원기둥의 겉넓이 계산 함수
        return 2 * pie * radius * (radius + height);
    }
};

class Cone { // 원뿔 클래스
public:
    double pie = 3.14;
    double radius;
    double height;

    Cone() { // 생성자
        cout << "***원뿔 계산기 접속***" << endl;
    }

    ~Cone() { // 소멸자
        cout << "원뿔 계산기 종료..." << endl;
    }

    double cone_volume() {  // 원뿔의 부피 계산 함수
        return (1 / 3.0) * pie * radius * radius * height;
    }
};

class Ball { // 구 클래스
public:
    double pie = 3.14;
    double radius;

    Ball() { // 생성자
        cout << "***구 계산기 접속***" << endl << endl;
    }

    ~Ball() { // 소멸자
        cout << "구 계산기 종료..." << endl << endl;
    }

    double ball_volume() { // 구 부피 계산 함수
        return (4 / 3.0) * pie * radius * radius * radius;
    }

    double ball_surface() { // 구 겉넓이 계산 함수
        return 4 * pie * radius * radius;
    }
};

int main() {
    int num;
    double radius, height;

    while (true) {
        cout << endl << "원하는 계산을 선택하세요" << endl;
        cout << "1. 원의 넓이 계산\n2. 원의 둘레 계산\n3. 원기둥의 부피 계산\n4. 원기둥의 겉넓이 계산\n5. 원뿔의 부피 계산\n6. 구의 부피 계산\n7. 구의 겉넓이 계산\n8. 종료\n";
        cout << "선택: ";
        cin >> num;
        cout << endl;

        switch (num) {
        case 1: {
            Circle circle;
            cout << "반지름 입력: ";
            cin >> radius;
            circle.radius = radius;
            cout << "평면 원의 넓이: " << circle.area() << endl;
            break;
        }
        case 2: {
            Circle circle;
            cout << "반지름 입력: ";
            cin >> radius;
            circle.radius = radius;
            cout << "원의 둘레: " << circle.round() << endl;
            break;
        }
        case 3: {
            Cylinder cylinder;
            cout << "반지름 입력: ";
            cin >> radius;
            cout << "높이 입력: ";
            cin >> height;
            cylinder.radius = radius;
            cylinder.height = height;
            cout << "원기둥의 부피: " << cylinder.cylinder_volume() << endl;
            break;
        }
        case 4: {
            Cylinder cylinder;
            cout << "반지름 입력: ";
            cin >> radius;
            cout << "높이 입력: ";
            cin >> height;
            cylinder.radius = radius;
            cylinder.height = height;
            cout << "원기둥의 겉넓이: " << cylinder.cylinder_surface() << endl;
            break;
        }
        case 5: {
            Cone cone;
            cout << "반지름 입력: ";
            cin >> radius;
            cout << "높이 입력: ";
            cin >> height;
            cone.radius = radius;
            cone.height = height;
            cout << "원뿔의 부피: " << cone.cone_volume() << endl;
            break;
        }
        case 6: {
            Ball ball;
            cout << "반지름 입력: ";
            cin >> radius;
            ball.radius = radius;
            cout << "구의 부피: " << ball.ball_volume() << endl;
            break;
        }
        case 7: {
            Ball ball;
            cout << "반지름 입력: ";
            cin >> radius;
            ball.radius = radius;
            cout << "구의 겉넓이: " << ball.ball_surface() << endl;
            break;
        }
        case 8: {
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        }
        default: {
            cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
        }
        }
    }

    return 0;
}
