#include<iostream>
using namespace std;

int total(int purchaseprice, int* sum) {
    *sum += purchaseprice;
    return *sum;
} // ��ü ���� ������ ����ϴ� ������ �Լ�

void welcome() {
    cout << "***** ������ ��鰡�Կ� ���� ���� ȯ���մϴ� *****" << endl;
}

int main() {
    string menu[] = { "�Ϲ� ���", "��ġ ���", "ġ�� ���", "�� ���", "�� ���� ���" };
    int price[] = { 3500, 4000, 4200, 4300, 4500 };
    int sum = 0;

    while (true) { 
        cout << endl;
        welcome();
        cout << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << ". " << menu[i] << " (" << price[i] << "��)" << endl;
        } // �ʱ�ȭ�� ����

        cout << endl << "�����Ͻ� ��� ��ȣ�� �Է����ּ���(����� 0) : ";
        int num;
        cin >> num;

        if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5) {
            string YorN;
            cout << menu[num - 1] << "��(��) �����Ͻðڽ��ϱ�? (Y/N): ";
            cin >> YorN;

            if (YorN == "Y" || YorN == "y") {
                cout << "�����Ͻ� ��� ������ �Է����ּ���: ";
                int n;
                cin >> n;

                int purchaseprice = price[num - 1] * n;
                cout << endl;
                cout << menu[num - 1] << "��(��) " << n << "�� �����ϼ̽��ϴ�." << endl;
                cout << "�� ������ " << purchaseprice << "�� �Դϴ�." << endl;
                sum += purchaseprice;
            } // ����? yes

            else if (YorN == "N" || YorN == "n") {
                continue;
            } // ����? no
        }

        else if (num == 0) {
            cout << "�� ������" << total(0, &sum) << "�� �Դϴ�. ";
            break;
        } // 0 �Է�

        else {
            cout << "����� �� ���ڸ� �Է��� �ּ���." << endl;
            continue;
        } // �ٸ� ���� �Է�

  
    }
    return 0;
}