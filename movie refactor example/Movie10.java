public class Movie {
  public static final int
    public static final int
    public static final int
    CHILDRENS = 2;
  REGULAR = 0;
  NEW_RELEASE = 1;
  private String _title;

  public Movie(String title, int priceCode) {
    _title = title;
    setPriceCode(priceCode);
  }

  public void setPriceCode(int arg) {
    switch (arg) {
      case REGULAR:
        _price = new RegularPrice();
        break;
      case CHILDRENS:
        _price = new ChildrensPrice();
        break;
      case NEW_RELEASE:
        _price = new NewReleasePrice();
        break;
      default:
        throw new IllegalArgumentException("Incorrect Price Code");
    }
  }
  private Price _price;

  public int getPriceCode() {
    return _price.getPriceCode();
  }
  public void setPriceCode(int arg) {
    _priceCode = arg;
  }
  public String getTitle (){
    return _title;
  };

  double getCharge(int daysRented) {
    return _price.getCharge(daysRented);
  }

  int getFrequentRenterPoints(int daysRented) {
    return _price.getFrequentRenterPoints(daysRented);
  }
}
