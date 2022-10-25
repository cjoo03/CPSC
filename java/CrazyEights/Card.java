public class Card{
  //value of suits
  public static final int HEARTS = 0;
  public static final int SPADES = 1;
  public static final int CLUBS = 2;
  public static final int DIAMONDS = 3;

  //value of face cards
  public static final int JACK = 11;
  public static final int QUEEN = 12;
  public static final int KING = 13;
  public static final int ACE = 14;

  private int suit_value;
  private int card_value;

  //default constructor
  public Card(){
    suit_value = 0;
    card_value = 0;
  }
  public Card(int suit, int card){
    suit_value = suit;
    card_value = card;
}
  public Card(Card c){
    this.suit_value = c.suit_value;
    this.card_value = c.card_value;
  }
  public int getSuitValue(){
    return this.suit_value;
  }
  public int getCardValue(){
    return this.card_value;
  }
  public void setSuitValue(int suit){
    this.suit_value = suit;
  }
  public void setCardValue(int card){
    this.card_value = card;
  }
  public String toString(){
    String s = "";
    String c = "";
    switch (suit_value){
      case HEARTS:
        s += " of Hearts\n";
        break;
      case SPADES:
        s += " of Spades\n";
        break;
      case CLUBS:
        s += " of Clubs\n";
        break;
      case DIAMONDS:
        s += " of Diamonds\n";
        break;
      }
    switch (card_value){
      case JACK:
        c += "Jack";
        break;
      case QUEEN:
        c += "Queen";
        break;
      case KING:
        c += "King";
        break;
      case ACE:
        c += "Ace";
        break;
      default:
        c += card_value;
        break;
    }
    return c + s;
    }
public boolean equals(Card o){
  return o == this;
}
}
