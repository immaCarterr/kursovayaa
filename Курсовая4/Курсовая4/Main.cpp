#include "Libraries.h"
#include "Functions.h"
#include "Flat.h"
#include "OneRoom.h"
#include "TwoRoom.h"
#include "ThreeRoom.h"
#include "MultyRoom.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag) {
		system("cls");
		int choice1 = Menu();
		switch (choice1) {
		case 1:
			system("cls");
			reg();
			continue;
			break;
		case 2:
			while (true) {
				system("cls");
				int EnterChoice = EnterMenu();
				if (EnterChoice == 3) break;
				switch (EnterChoice) {
				case 1: {
					if (authorization() == -1) continue;
					while (true) {
						system("cls");
						int choice2 = AdminMenu();
						if (choice2 == 7) break;
						switch (choice2) {
						case 1:
							while (true) {
								system("cls");
								int choice3 = AddMenu();
								if (choice3 == 5) break;
								switch (choice3) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									AddData(&oneRoom, "OneRoom.txt", 0);
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									AddData(&twoRoom, "TwoRoom.txt", 0);
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									AddData(&threeRoom, "ThreeRoom.txt", 0);
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									AddData(&multyRoom, "MultyRoom.txt", 0);
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 2:
							while (true) {
								system("cls");
								int choice4 = RedMenu();
								if (choice4 == 9) break;
								switch (choice4) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									ShowData(oneRoom, "OneRoom.txt", 0);
									RedactData(oneRoom, "OneRoom.txt");
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									ShowData(twoRoom, "TwoRoom.txt", 0);
									RedactData(twoRoom, "TwoRoom.txt");
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									ShowData(threeRoom, "ThreeRoom.txt", 0);
									RedactData(threeRoom, "ThreeRoom.txt");
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									ShowData(multyRoom, "MultyRoom.txt", 0);
									RedactData(multyRoom, "MultyRoom.txt");
									break;
								}
								case 5: {
									system("cls");
									OneRoom oneRoom;
									ShowData(oneRoom, "BoughtOneRoom.txt", 0);
									RedactData(oneRoom, "BoughtOneRoom.txt");
									break;
								}
								case 6: {
									system("cls");
									TwoRoom twoRoom;
									ShowData(twoRoom, "BoughtTwoRoom.txt", 0);
									RedactData(twoRoom, "BoughtTwoRoom.txt");
									break;
								}
								case 7: {
									system("cls");
									ThreeRoom threeRoom;
									ShowData(threeRoom, "BoughtThreeRoom.txt", 0);
									RedactData(threeRoom, "BoughtThreeRoom.txt");
									break;
								}
								case 8: {
									system("cls");
									MultyRoom multyRoom;
									ShowData(multyRoom, "BoughtMultyRoom.txt", 0);
									RedactData(multyRoom, "BoughtMultyRoom.txt");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 3:
							while (true) {
								system("cls");
								int choice5 = DelMenu();
								if (choice5 == 10) break;
								switch (choice5) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									ShowData(oneRoom, "OneRoom.txt", 0);
									DeleteData(oneRoom, "OneRoom.txt");
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									ShowData(twoRoom, "TwoRoom.txt", 0);
									DeleteData(twoRoom, "TwoRoom.txt");
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									ShowData(threeRoom, "ThreeRoom.txt", 0);
									DeleteData(threeRoom, "ThreeRoom.txt");
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									ShowData(multyRoom, "MultyRoom.txt", 0);
									DeleteData(multyRoom, "MultyRoom.txt");
									break;
								}
								case 5: {
									system("cls");
									OneRoom oneRoom;
									ShowData(oneRoom, "BoughtOneRoom.txt", 0);
									DeleteData(oneRoom, "BoughtOneRoom.txt");
									break;
								}
								case 6: {
									system("cls");
									TwoRoom twoRoom;
									ShowData(twoRoom, "BoughtTwoRoom.txt", 0);
									DeleteData(twoRoom, "BoughtTwoRoom.txt");
									break;
								}
								case 7: {
									system("cls");
									ThreeRoom threeRoom;
									ShowData(threeRoom, "BoughtThreeRoom.txt", 0);
									DeleteData(threeRoom, "BoughtThreeRoom.txt");
									break;
								}
								case 8: {
									system("cls");
									MultyRoom multyRoom;
									ShowData(multyRoom, "BoughtMultyRoom.txt", 0);
									DeleteData(multyRoom, "BoughtMultyRoom.txt");
									break;
								}
								case 9: {
									system("cls");
									Buyer buyer;
									ShowBuyers();
									DeleteBuyer(buyer, "Buyers.txt");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 4:
							while (true) {
								system("cls");
								int choice6 = ShowMenu();
								if (choice6 == 7) break;
								switch (choice6) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									ShowData(oneRoom, "OneRoom.txt", 0);
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									ShowData(twoRoom, "TwoRoom.txt", 0);
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									ShowData(threeRoom, "ThreeRoom.txt", 0);
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									ShowData(multyRoom, "MultyRoom.txt", 0);
									break;
								}
								case 5: {
									system("cls");
									cout << "Однокомнатные:" << endl;
									OneRoom oneRoom;
									ShowData(oneRoom, "BoughtOneRoom.txt", 1);

									cout << "\n\nДвухкомнатные:" << endl;
									TwoRoom twoRoom;
									ShowData(twoRoom, "BoughtTwoRoom.txt", 1);

									cout << "\n\nТрёхкомнатные:" << endl;
									ThreeRoom threeRoom;
									ShowData(threeRoom, "BoughtThreeRoom.txt", 1);

									cout << "\n\nМногокомнатные:" << endl;
									MultyRoom multyRoom;
									ShowData(multyRoom, "BoughtMultyRoom.txt", 1);
									system("pause");
									break;
								}
								case 6: {
									system("cls");
									ShowBuyers();
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 5:
							while (true) {
								system("cls");
								int choice7 = FindMenu();
								if (choice7 == 7) break;
								switch (choice7) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									FindData(oneRoom, "OneRoom.txt");
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									FindData(twoRoom, "TwoRoom.txt");
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									FindData(threeRoom, "ThreeRoom.txt");
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									FindData(multyRoom, "MultyRoom.txt");
									break;
								}
								case 5: {
									system("cls");
									FindBought();
									break;
								}
								case 6: {
									system("cls");
									cout << "Однокомнатные:" << endl;
									OneRoom oneRoom;
									FilterPrice(oneRoom, "OneRoom.txt");

									cout << "\n\nДвухкомнатные:" << endl;
									TwoRoom twoRoom;
									FilterPrice(twoRoom, "TwoRoom.txt");

									cout << "\n\nТрёхкомнатные:" << endl;
									ThreeRoom threeRoom;
									FilterPrice(threeRoom, "ThreeRoom.txt");

									cout << "\n\nМногокомнатные:" << endl;
									MultyRoom multyRoom;
									FilterPrice(multyRoom, "MultyRoom.txt");
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 6: {
							system("cls");
							DelUsers();
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					break;
				}
				case 2: {
					if (authorization() == -1) continue;
					while (true) {
						system("cls");
						int userChoice = UserMenu();
						if (userChoice == 4) break;
						switch (userChoice) {
						case 1: {
							while (true) {
								system("cls");
								int choice6 = ShowMenu();
								if (choice6 == 7) break;
								switch (choice6) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									ShowData(oneRoom, "OneRoom.txt", 0);
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									ShowData(twoRoom, "TwoRoom.txt", 0);
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									ShowData(threeRoom, "ThreeRoom.txt", 0);
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									ShowData(multyRoom, "MultyRoom.txt", 0);
									break;
								}
								case 5: {
									system("cls");
									cout << "Однокомнатные:" << endl;
									OneRoom oneRoom;
									ShowData(oneRoom, "BoughtOneRoom.txt", 1);

									cout << "\n\nДвухкомнатные:" << endl;
									TwoRoom twoRoom;
									ShowData(twoRoom, "BoughtTwoRoom.txt", 1);

									cout << "\n\nТрёхкомнатные:" << endl;
									ThreeRoom threeRoom;
									ShowData(threeRoom, "BoughtThreeRoom.txt", 1);

									cout << "\n\nМногокомнатные:" << endl;
									MultyRoom multyRoom;
									ShowData(multyRoom, "BoughtMultyRoom.txt", 1);
									system("pause");
									break;
								}
								case 6: {
									system("cls");
									ShowBuyers();
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						}
						case 2: {
							while (true) {
								system("cls");
								int choice7 = FindMenu();
								if (choice7 == 7) break;
								switch (choice7) {
								case 1: {
									system("cls");
									OneRoom oneRoom;
									FindData(oneRoom, "OneRoom.txt");
									break;
								}
								case 2: {
									system("cls");
									TwoRoom twoRoom;
									FindData(twoRoom, "TwoRoom.txt");
									break;
								}
								case 3: {
									system("cls");
									ThreeRoom threeRoom;
									FindData(threeRoom, "ThreeRoom.txt");
									break;
								}
								case 4: {
									system("cls");
									MultyRoom multyRoom;
									FindData(multyRoom, "MultyRoom.txt");
									break;
								}
								case 5: {
									system("cls");
									FindBought();
									break;
								}
								case 6: {
									system("cls");
									cout << "Однокомнатные:" << endl;
									OneRoom oneRoom;
									FilterPrice(oneRoom, "OneRoom.txt");

									cout << "\n\nДвухкомнатные:" << endl;
									TwoRoom twoRoom;
									FilterPrice(twoRoom, "TwoRoom.txt");

									cout << "\n\nТрёхкомнатные:" << endl;
									ThreeRoom threeRoom;
									FilterPrice(threeRoom, "ThreeRoom.txt");

									cout << "\n\nМногокомнатные:" << endl;
									MultyRoom multyRoom;
									FilterPrice(multyRoom, "MultyRoom.txt");
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						}
						case 3: {
							system("cls");
							cout << "Однокомнатные:" << endl;
							OneRoom oneRoom;
							ShowData(oneRoom, "OneRoom.txt", 1);

							cout << "\n\nДвухкомнатные:" << endl;
							TwoRoom twoRoom;
							ShowData(twoRoom, "TwoRoom.txt", 1);

							cout << "\n\nТрёхкомнатные:" << endl;
							ThreeRoom threeRoom;
							ShowData(threeRoom, "ThreeRoom.txt", 1);

							cout << "\n\nМногокомнатные:" << endl;
							MultyRoom multyRoom;
							ShowData(multyRoom, "MultyRoom.txt", 1);
							system("pause");
							BuyFlat();
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					break;
				}
				}
				continue;
			}
			break;
		case 3:
			exit(0);
			break;
		default: {
			system("cls");
			cout << "Неверный выбор!\nПовторите попытку." << endl;
			system("pause");
		}
		}
	}
	return 0;
}