import java.util.LinkedList;
import java.util.Random;
@SuppressWarnings("unchecked")

//member variables
public class Player{
  private int playerNumber;
  private LinkedList<Card> ownedCards;
  private Dealer dealer;
  private LinkedList<Card> sPile;

//overloaded constructor
  public Player(int num, Dealer m_dealer, LinkedList starterP){
    playerNumber = num;
    dealer = m_dealer;
    ownedCards = new LinkedList<Card>();
    sPile = starterP;
  }

//getHandsSize method that returns the number of cards held in hand
  public int getHandSize(){
    return ownedCards.size();
  }

/* setSuit method that sets the last played card
to a random Suit */
  public void setSuit(int sVal){
    sPile.getFirst().setSuitValue(sVal);
  }

/* deal method that deals n amount of cards to each player */
  public void deal(int n){
    LinkedList<Card> dealedCards = dealer.deals(n);
    for (int i = 0; i < n; i++){
      ownedCards.addFirst(dealedCards.getFirst());
      dealedCards.removeFirst();
    }
  }

/* cardCheck method determines if the card is playable
   if the card is playable returns true else return false */
  public boolean cardCheck(Card sCard, Card hCard){
    if (sCard.getSuitValue() == hCard.getSuitValue() ||
    sCard.getCardValue() == hCard.getCardValue() ||
    hCard.getCardValue() == 8){
      return true;
    }
    else {
      return false;
    }
  }

  /* takeTurn method that removes and returns a playable card
     from the list of owned cards, adding to the hand from the
     dealer stock as needed. If player passes turn, method returns null */
  public Card takeTurn(){
    Card startCard = sPile.getFirst();
    //checking hand for matching card
    for (int i = 0; i < ownedCards.size(); i++){
      Card handCard = ownedCards.get(i);
      if (this.cardCheck(startCard,handCard)){
        ownedCards.remove(handCard);
        sPile.addFirst(handCard);
        if (handCard.getCardValue() == 8){
          setSuit(newSuit());
        }
        System.out.println("Hand: " + handCard);
        return handCard;
      }
    }
    //checks drawn card for matching card
    while (true){
      if (dealer.size() == 0){
        return null;
      }
      else {
        this.deal(1);
        Card drawnCard = ownedCards.getFirst();
        if (this.cardCheck(drawnCard,startCard)){
          ownedCards.remove(drawnCard);
          sPile.addFirst(drawnCard);
          if (drawnCard.getCardValue() == 8){
            setSuit(newSuit());
          }
          System.out.println("Drew: " + drawnCard);
          return drawnCard;
        }
      }
    }
  }
  /* returns the new suit to be played
     uses random package to determine a random
     suit value */
  public int newSuit(){
    Random rand = new Random();
    int bound = 3;
    int ra = rand.nextInt(bound);
    return ra;
    }
}
