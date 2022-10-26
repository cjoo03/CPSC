import java.util.LinkedList;

public class Game{
  private Player player1;
  private Player player2;
  private Dealer crazy;
  private LinkedList<Card> starterPile;


  /* creates a startPile, new dealer, and 2 players */
  public Game(){
    this.starterPile = new LinkedList<Card>();
    this.crazy = new Dealer();
    this.player1 = new Player(1,crazy,starterPile);
    this.player2 = new Player(2,crazy,starterPile);
  }

  /* checkWinner method that determines a winner
     when the # of owned Cards is 0 */
  public boolean checkWinner(Player player){
    if (player.getHandSize() == 0){
      return true;
    }
    else {
      return false;
    }
  }

  /* play method that carries out the rules of the game
     until one of the players has won */
  public void play(){
    player1.deal(5);
    player2.deal(5);
    starterPile.add(crazy.deals(1).getFirst());
    Player playerTurn = player1;
    while (true){
      if (playerTurn == player1){
        System.out.println("Player 1 Turn:");
        if (player1.takeTurn() != null){
          playerTurn = player2;
          if (checkWinner(player1)){
            System.out.println("Player 1 has won!");
            break;
          }
        }
        else{
          playerTurn = player2;
        }
      }
      else {
        System.out.println("Player 2 Turn:");
        if (player2.takeTurn() != null){
          playerTurn = player1;
          if (checkWinner(player2)){
            System.out.println("Player 2 has won!");
            break;
          }
        }
        else{
          playerTurn = player1;
        }
      }

    }
  }


}
