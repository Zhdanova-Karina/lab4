import java.io.IOException;

public class Game {
    private static PlusDalmatin countDalmatinsFound;

    public Game() {
        countDalmatinsFound = new PlusDalmatin(); // Инициализация отслеживателя
    }

    public static int getCountDalmatins() {
        return countDalmatinsFound.getCount();
    }
    public void PlusOne() {
        countDalmatinsFound.incrementCount();    }
    public void PrintRepeatInput(){
        System.out.println("Повторите ввод.\n");
    }

  public void Play(){
        Game game = new Game();
       while (true) {
           Level level = new Level(true, "Спальня", 3);
          System.out.print(level.getName());
          int countDalmatins = level.Level_1(level, game);
           printCompliments();

           int yesOrNo;
          do {
               yesOrNo = level.TransferLastLocation(level, game);
              if (yesOrNo == 0) {
                  level = new Level(false, "Подвал", 1); // создаем новый уровень
                 System.out.print(level.getName());
                   level.Level_2(level, game, countDalmatins);
               } else {
                    PrintRepeatInput();
                }
          } while (yesOrNo != 0);
           break;
       }
    }

    public void printCompliments(){
        System.out.println("\nПоздравляем! Уровень пройден!");
    }

    public int StartPlay() {
        System.out.println("\nНажмите *, чтобы начать игру\n1, чтобы завершить игру\n");
        try {
            char symbol = (char) System.in.read(); // Читаем один символ

            // Очистка буфера: считываем оставшийся символ новой строки
            System.in.read();

            if (symbol == '*') {
                return 1; // Начать игру
            } else if (symbol == '1') {
                return 0; // Завершить игру
            } else {
                return -1; // Неверный ввод
            }
        } catch (IOException e) {
            e.printStackTrace(); // Обработка исключения
            return -1; // Вернуть -1 в случае ошибки
        }

    }
    public void Rules(){
        System.out.println("ПРАВИЛА ИГРЫ\nНазвание: Поиск далматинцев\nСложность: 3\nКоличество игроков: 1\n\nВ этой захватывающей игре вы и ваш команда отправитесь в сложное и увлекательное путешествие, чтобы спасти наших пушистых друзей – далматинцев, которых снова похитила жестокая Круэлла! Только вместе вы сможете преодолеть все препятствия и вернуть животных домой.\n\nВаша задача – найти всех похищенных далматинцев на заданных локациях. \nИгра считается завершенной, когда все далматинцы будут найдены и возвращены домой.\n");
    }
}
