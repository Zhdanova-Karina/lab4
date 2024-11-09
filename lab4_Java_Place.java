public class Place {
    private String name;
    private boolean existDalmatian;

    public Place(String name, boolean existDalmatian) {
        this.name = name;
        this.existDalmatian = existDalmatian;
    }
    public String getName() { return name; }

    public boolean getExistDalmatian() { return existDalmatian; }
    public void setExistDalmatian(boolean trueORfalse) { existDalmatian = trueORfalse; }
}
