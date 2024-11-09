public class PlusDalmatin {
        private int countDalmatinsFound;

        public PlusDalmatin() {
            countDalmatinsFound = 0;
        }

        // Метод для увеличения количества найденных далматинцев
        public void incrementCount() {
            countDalmatinsFound++;
        }

        // Метод для получения количества найденных далматинцев
        public int getCount() {
            return countDalmatinsFound;
        }
    }
