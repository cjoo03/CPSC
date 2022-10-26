import java.util.LinkedList;
public class Dealer{
  private Deck m_deck;

  public Dealer(){
    m_deck = new Deck();
  }

  public LinkedList<Card> deals(int n){
    LinkedList<Card> dealtCards = new LinkedList<Card>();
    for (int i = 0; i < n; i++){
      if (m_deck.size() == 0){
        m_deck = new Deck();
      }
      dealtCards.add(m_deck.deal());
    }
    return dealtCards;
  }

  public int size(){
    return m_deck.size();
  }

  public String toString(){
    return m_deck.toString();
  }
}
