import java.util.ArrayList;
import java.io.IOException;
import java.util.Scanner;



public class Level {
    private String name;
    private int countDalmatins, countPlace;

    public ArrayList<Dalmatin> dalmatins = new ArrayList<>();
    public ArrayList<Place> places = new ArrayList<>();
    public static final int MAX_DOGS = 4;

    Level(boolean isBedroom, String name, int countDalmatins) {
        // Инициализация далматинцев
        dalmatins.add(new Dalmatin("Патч"));
        dalmatins.add(new Dalmatin("Пэдди"));
        dalmatins.add(new Dalmatin("Понго"));
        dalmatins.add(new Dalmatin("Ролли"));

        // Инициализация места
        if (isBedroom) {
            this.name = name;
            this.countDalmatins = countDalmatins;
            places.add(new Place("\n 1. Шкаф", false));
            places.add(new Place("\n 2. Тумба", false));
            places.add(new Place("\n 3. Кровать", true));
            places.add(new Place("\n 4. Коробка", true));
            places.add(new Place("\n 5. Полка", true));

        }
        else {
            this.name = name;
            this.countDalmatins = countDalmatins;
            places.add(new Place("\n 1. Бочка", false));
            places.add(new Place("\n 2. Клетка", true));
            places.add(new Place("\n 3. Шкаф", false));
        }
    }

    public int getCountPlace() {
        return countPlace;
    }

    public int getCountDalmatins() { return countDalmatins; }
    public String getName(){ return name; }

    public int PrintLocationPlace(Level level, int countPlace){
        // Печатаем места
        for (int i = 0; i <
