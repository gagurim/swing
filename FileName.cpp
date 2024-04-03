#include<iostream>
using namespace std;

int total(int purchaseprice, int* sum) {
    *sum += purchaseprice;
    return *sum;
} // 전체 누적 가격을 계산하는 포인터 함수

void welcome() {
    cout << "***** 슈니의 라면가게에 오신 것을 환영합니다 *****" << endl;
}

int main() {
    string menu[] = { "일반 라면", "김치 라면", "치즈 라면", "떡 라면", "떡 만두 라면" };
    int price[] = { 3500, 4000, 4200, 4300, 4500 };
    int sum = 0;

    while (true) { 
        cout << endl;
        welcome();
        cout << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << ". " << menu[i] << " (" << price[i] << "원)" << endl;
        } // 초기화면 세팅

        cout << endl << "구매하실 라면 번호를 입력해주세요(종료는 0) : ";
        int num;
        cin >> num;

        if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5) {
            string YorN;
            cout << menu[num - 1] << "을(를) 구입하시겠습니까? (Y/N): ";
            cin >> YorN;

            if (YorN == "Y" || YorN == "y") {
                cout << "구매하실 라면 개수를 입력해주세요: ";
                int n;
                cin >> n;

                int purchaseprice = price[num - 1] * n;
                cout << endl;
                cout << menu[num - 1] << "을(를) " << n << "개 구매하셨습니다." << endl;
                cout << "총 가격은 " << purchaseprice << "원 입니다." << endl;
                sum += purchaseprice;
            } // 구입? yes

            else if (YorN == "N" || YorN == "n") {
                continue;
            } // 구입? no
        }

        else if (num == 0) {
            cout << "총 가격은" << total(0, &sum) << "원 입니다. ";
            break;
        } // 0 입력

        else {
            cout << "제대로 된 숫자를 입력해 주세요." << endl;
            continue;
        } // 다른 숫자 입력

  
    }
    return 0;
}