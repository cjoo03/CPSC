import java.util.ArrayList;
public class ArtistAccount extends Account{
  public ArtistAccount(){
    super();
  }

  public ArtistAccount(String username){
    super(username);
  }

  public String toString(){
    return accName;
  }
}
