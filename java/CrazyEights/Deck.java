import java.util.LinkedList;
import java.util.Random;

public class Deck{
  private LinkedList<Card> m_cards = new LinkedList<Card>();

//default constructor
public Deck(){
  for (int suit_value = 0; suit_value < 4; suit_value++){
    for (int card_value = 2; card_value <= 14; card_value++){
      Card new_card = new Card(suit_value, card_value);
      m_cards.add(new_card);
    }
  }
}
//copy constructor
public Deck(Deck d){
  this.m_cards = new LinkedList<Card>();
}

public String toString(){
  return m_cards.toString();
}

public int size(){
  return m_cards.size();
}

public Card deal(){
  Random rand = new Random();
  int r = rand.nextInt(m_cards.size());
  return m_cards.remove(r);
}
}
