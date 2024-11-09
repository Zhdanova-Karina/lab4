#pragma warning(disable : 4996)
#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "string.h"
#include <locale.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

#define MAX_DALMATIANS 4

class Dalmatian;
class Cage;
class Game;
class PlaceWithDalmatian;
class Level;

class Cage {
private:
    string answer;
public:
    Cage(){}
    Cage(string answer) {
        this->answer = answer;
    }

    int getHintForCode();
    void CodeOfCage(Level& level, Game& game, int number);

    string getAnswerCode() { return answer; }

};

class Game {
private:
   static int countDalmatinsFound;
public:

    static int getCountDalmatins() { return countDalmatinsFound; }
    // Перегрузка префиксного оператора ++
    Game& operator++() {
        countDalmatinsFound++;
        return *this; 
    }

    // Перегрузка постфиксного оператора ++
    Game operator++(int) {
        Game temp = *this; // Сохраняем текущее состояние
        ++(*this); // вызываем префиксный оператор
        return temp; // Возвращаем предыдущее состояние
    }
    void Play();
    void printCompliments();
    int StartPlay();
    void PrintRepeatInput();
    void Rules();
    friend int TransferLastLocation(Level& level, Game& game);
};

class Dalmatian {
private:
    string name;
public:
    Dalmatian() {}
    Dalmatian(string name) {
       this->name = name;
    }

    string getName() { return name; }

};

class PlaceWithDalmatian {
private:
    string name;
    bool existDalmatian;
public:
    Dalmatian dalmatian;

    PlaceWithDalmatian(){}
    PlaceWithDalmatian(string name, Dalmatian dalmatian, bool trueORfalse) : existDalmatian(trueORfalse) {
        this->name = name;
    }

    string getName() { return name; }

    bool getExistDalmatian() { return existDalmatian; }
    void setExistDalmatian(bool existDalamtian) { this->existDalmatian = existDalamtian; }

};

class Level {
private:
    string name;
    static int countDalmatins, countPlace; //статические переменные

public:
    Dalmatian* dalmatians;
    Cage cage;
    PlaceWithDalmatian* place;
    Level(bool isBedroom, string name, int countDalmatins, int countPlace) {
        // Инициализация далматинцев
        dalmatians = new Dalmatian[MAX_DALMATIANS];
        dalmatians[0] = Dalmatian("Патч");
        dalmatians[1] = Dalmatian("Пэдди");
        dalmatians[2] = Dalmatian("Понго");
        dalmatians[3] = Dalmatian("Ролли");

        // Инциализация места
        if (isBedroom) {
            this->name = name;
            this->countDalmatins = countDalmatins;
            this->countPlace = countPlace;
            place = new PlaceWithDalmatian[5];
            place[0] = PlaceWithDalmatian("\n 1. Шкаф", dalmatians[0], false);
            place[1] = PlaceWithDalmatian("\n 2. Тумба", dalmatians[0], false);
            place[2] = PlaceWithDalmatian("\n 3. Кровать", dalmatians[0], true);
            place[3] = PlaceWithDalmatian("\n 4. Коробка", dalmatians[1], true);
            place[4] = PlaceWithDalmatian("\n 5. Полка", dalmatians[2], true);

        }
        else {
           this->name = name;
           this->countDalmatins = countDalmatins;
           this->countPlace = countPlace;
            place = new PlaceWithDalmatian[3];
            place[0] = PlaceWithDalmatian("\n 1. Бочка", dalmatians[3], false);
            place[1] = PlaceWithDalmatian("\n 2. Клетка", dalmatians[3], true);
            place[2] = PlaceWithDalmatian("\n 3. Шкаф", dalmatians[3], false);
        }
    }

    // Метод для получения указателя на определенного далматинца
    Dalmatian* getDalmatianPointer(int index) {
            return &dalmatians[index];
    }
    //метод для получения ссылки на определенное место
    PlaceWithDalmatian& getPlacePointer(int index) {
            return place[index];
    }

    /*статический метод*/
    static int getCountDalmatins() { return countDalmatins; }
    static int getCountPlace() { return countPlace; }

    string getName() { return name; }

    int PrintLocationPlace(Level& level, int countPlace);
    void dalmatianFound(Level& level, Game& game, int number);
   friend int TransferLastLocation(Level& level, Game& game);
    void Level_1(Level& level, Game& game);
    void Level_2(Level& level, Game& game);
    int RangeCheck(int number, int range);
    void ViewingFoundDalmatians(Level& level, Game& game);


};

int Level::countPlace = 0;
int Level::countDalmatins = 0;
int Game::countDalmatinsFound = 0;

int main() {
    setlocale(LC_ALL, "RU");
    Game game;
    game.Rules();
    int start;
    do {
        start = game.StartPlay();
        if (start == 1) {
            game.Play();
        }
        else  if (start == 0) break;
        else game.PrintRepeatInput();
    } while (start < 0);
    cout << "Конец игры" << endl;
    return 0;
}

void Game::Rules() {
    cout << "ПРАВИЛА ИГРЫ\nНазвание: Поиск далматинцев\nСложность: 3\nКоличество игроков: 1\n\nВ этой захватывающей игре вы и ваш команда отправитесь в сложное и увлекательное путешествие, чтобы спасти наших пушистых друзей – далматинцев, которых снова похитила жестокая Круэлла! Только вместе вы сможете преодолеть все препятствия и вернуть животных домой.\n\nВаша задача – найти всех похищенных далматинцев на заданных локациях. \nИгра считается завершенной, когда все далматинцы будут найдены и возвращены домой." << endl;
}

void Game::printCompliments() {
    cout << "Поздравляем! Уровень пройден!" << endl;
}

int Game::StartPlay() {
    char symbol;
    cout << "Нажмите *, чтобы начать игру\nESC, чтобы завершить игру\n" << endl;
    cin >> symbol;
    if (symbol == '*') {
        return 1;
    }
    else if (symbol == 27) {
        return 0;
    }
    else {
        return -1;
    }
}

void Game::PrintRepeatInput() {
    cout << "Повторите ввод." << endl;
}
void Game::Play() {
    while (true) {
        Level level(true, "Спальня", 3, 5);
        cout << level.getName() << endl;
        level.Level_1(level, *this);
        this->printCompliments();
        int YesOrNo;
        do {
            YesOrNo = TransferLastLocation(level, *this);
            if (YesOrNo == 0) {
                level = Level(false, "Подвал", 1, 3);
                cout << level.getName() << endl;
                level.Level_2(level, *this);
            }
            else PrintRepeatInput();
        } while (YesOrNo != 0);
        break;
    }
}

    int Level::PrintLocationPlace(Level& level, int countPlace) {
    int numberPlace;
    for (int i = 0; i < countPlace; i++) {
        PlaceWithDalmatian& place = getPlacePointer(i); // Используем метод getPlacePointer
        cout << place.getName() << endl; // Выводим название
    }
    cout << "\nВведите пункт: ";
    cin >> numberPlace;
    return numberPlace;
}

  void Level::ViewingFoundDalmatians(Level& level, Game& game) {
      cout << "\nВы нашли " << game.getCountDalmatins() << "/4 далматинцев:" << endl;  
      for (int i = 0; i < game.getCountDalmatins(); i++) {
          Dalmatian* dalmatian = getDalmatianPointer(i);
        cout << dalmatian->getName() << endl;
    }
}

void Level::dalmatianFound(Level& level, Game& game, int number) {
    if (place[number - 1].getExistDalmatian() == true) {
        place[number - 1].setExistDalmatian(false);    
        game++;

        ViewingFoundDalmatians(level, game);
    }
    else {
        cout << "Увы, здесь никого нет\n" << endl;
    }
}

/*дружественная функция*/
int TransferLastLocation(Level& level, Game& game) {
    char symbol;
    if (game.getCountDalmatins() == level.getCountDalmatins() && game.getCountDalmatins() < MAX_DALMATIANS) {
        cout << "\nНажмите *, чтобы перейти к следующей локации" << endl;
        cin >> symbol;
    }
    if (symbol == '*') return 0;
    else return 1;
}
int Level::RangeCheck(int number, int range) {
    if (number > 0 && number < range + 1) return 0;
    else return 1;
}

void Level::Level_1(Level& level, Game& game) {
    while (game.getCountDalmatins() < getCountDalmatins()) {
        int number;
        number = PrintLocationPlace(level, getCountPlace());
        if (RangeCheck(number, getCountPlace()) == 0) dalmatianFound(level, game, number);
        else game.PrintRepeatInput();
    }
}
void Level::Level_2(Level& level, Game& game) {
    while (game.getCountDalmatins() < MAX_DALMATIANS) {
        int number;
        number = PrintLocationPlace(level, getCountPlace());
        if (RangeCheck(number, getCountPlace()) == 0) {
            if (number != 2) dalmatianFound(level, game, number);
            else {
                cout << "\nО нет! Клетка закрыта на замок! Вам нужно отгадать код!" << endl;
                cage.CodeOfCage(level, game, number);
            }
        }
        else game.PrintRepeatInput();
    }
}
int Cage::getHintForCode() {
    cout << "Нажмите *, чтобы получить подсказку" << endl;
    char symbol;
    do {
        cin >> symbol;
    } while (symbol != '*');
    if (symbol == '*') {
        cout << "\nКод состоит из трёх символов. Чтобы найти каждый символ вам нужно:\n1) перевести число 127 в двоичную, восьмеричную и шестнадцатиричную системы счисления;\n2) каждый последний символ будет являться частью кода\nВсе буквы должны быть заглавными!\n" << endl;
        return 0;
    }
}

void Cage::CodeOfCage(Level& level, Game& game, int number) {
    string input;
    Cage cage("17F");
    if (getHintForCode() == 0) {
        do {
            cout << "\nВведите код:" << endl;
            cin >> input;
            if (input.empty()) {
                cout << "Код не может быть пустым. Пожалуйста, попробуйте снова." << endl;
                continue; // Пропустить текущую итерацию цикла
            }

            if (input == cage.getAnswerCode()) {
                cout << "Ура! Вы освободили далматинца!\n" << endl;
                level.dalmatianFound(level, game, number);
                return;
            }
            else {
                game.PrintRepeatInput();
            }
        } while (true);
    }
    else {
        game.PrintRepeatInput();
    }
}
