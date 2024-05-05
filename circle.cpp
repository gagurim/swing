#include <iostream>
using namespace std;

class Circle { // ��� �� Ŭ����
public:
    double pie = 3.14;
    double radius;

    Circle() { // ������
        cout << "***��� �� ���� ����***" << endl;
    }

    ~Circle() { // �Ҹ���
        cout << "��� �� ���� ����..." << endl;
    }

    double area() { // �� ���� ��� �Լ�
        return pie * radius * radius;
    }

    double round() { // �� �ѷ� ��� �Լ�
        return 2 * pie * radius;
    }
};

class Cylinder { // ����� Ŭ����
public:
    double pie = 3.14;
    double radius;
    double height;

    Cylinder() { // ������
        cout << "***����� ���� ����***" << endl;
    }

    ~Cylinder() { // �Ҹ���
        cout << "����� ���� ����..." << endl;
    }

    double cylinder_volume() { // ������� ���� ��� �Լ�
        return pie * radius * radius * height;
    }

    double cylinder_surface() { // ������� �ѳ��� ��� �Լ�
        return 2 * pie * radius * (radius + height);
    }
};

class Cone { // ���� Ŭ����
public:
    double pie = 3.14;
    double radius;
    double height;

    Cone() { // ������
        cout << "***���� ���� ����***" << endl;
    }

    ~Cone() { // �Ҹ���
        cout << "���� ���� ����..." << endl;
    }

    double cone_volume() {  // ������ ���� ��� �Լ�
        return (1 / 3.0) * pie * radius * radius * height;
    }
};

class Ball { // �� Ŭ����
public:
    double pie = 3.14;
    double radius;

    Ball() { // ������
        cout << "***�� ���� ����***" << endl << endl;
    }

    ~Ball() { // �Ҹ���
        cout << "�� ���� ����..." << endl << endl;
    }

    double ball_volume() { // �� ���� ��� �Լ�
        return (4 / 3.0) * pie * radius * radius * radius;
    }

    double ball_surface() { // �� �ѳ��� ��� �Լ�
        return 4 * pie * radius * radius;
    }
};

int main() {
    int num;
    double radius, height;

    while (true) {
        cout << endl << "���ϴ� ����� �����ϼ���" << endl;
        cout << "1. ���� ���� ���\n2. ���� �ѷ� ���\n3. ������� ���� ���\n4. ������� �ѳ��� ���\n5. ������ ���� ���\n6. ���� ���� ���\n7. ���� �ѳ��� ���\n8. ����\n";
        cout << "����: ";
        cin >> num;
        cout << endl;

        switch (num) {
        case 1: {
            Circle circle;
            cout << "������ �Է�: ";
            cin >> radius;
            circle.radius = radius;
            cout << "��� ���� ����: " << circle.area() << endl;
            break;
        }
        case 2: {
            Circle circle;
            cout << "������ �Է�: ";
            cin >> radius;
            circle.radius = radius;
            cout << "���� �ѷ�: " << circle.round() << endl;
            break;
        }
        case 3: {
            Cylinder cylinder;
            cout << "������ �Է�: ";
            cin >> radius;
            cout << "���� �Է�: ";
            cin >> height;
            cylinder.radius = radius;
            cylinder.height = height;
            cout << "������� ����: " << cylinder.cylinder_volume() << endl;
            break;
        }
        case 4: {
            Cylinder cylinder;
            cout << "������ �Է�: ";
            cin >> radius;
            cout << "���� �Է�: ";
            cin >> height;
            cylinder.radius = radius;
            cylinder.height = height;
            cout << "������� �ѳ���: " << cylinder.cylinder_surface() << endl;
            break;
        }
        case 5: {
            Cone cone;
            cout << "������ �Է�: ";
            cin >> radius;
            cout << "���� �Է�: ";
            cin >> height;
            cone.radius = radius;
            cone.height = height;
            cout << "������ ����: " << cone.cone_volume() << endl;
            break;
        }
        case 6: {
            Ball ball;
            cout << "������ �Է�: ";
            cin >> radius;
            ball.radius = radius;
            cout << "���� ����: " << ball.ball_volume() << endl;
            break;
        }
        case 7: {
            Ball ball;
            cout << "������ �Է�: ";
            cin >> radius;
            ball.radius = radius;
            cout << "���� �ѳ���: " << ball.ball_surface() << endl;
            break;
        }
        case 8: {
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        }
        default: {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
        }
        }
    }

    return 0;
}
