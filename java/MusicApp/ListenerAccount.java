import java.util.*;

public class ListenerAccount extends Account{
  protected LinkedList<Content> userFav;

  public ListenerAccount(){
    super();
    userFav = new LinkedList<Content>();
  }

  public LinkedList<Content> getUserFav(){
    return userFav;
  }

  public void setUserFav(LinkedList<Content>favCon){
    userFav = favCon;
  }
  public void favorite(Content favCon){
    userFav.add(favCon);
    System.out.print("Favorites " + favCon.getContentTitle());
  }
}
