public class Account{
  protected String accName;

public Account(){
  accName = "";
}

public Account(String user){
  accName = user;
}

public String getUsername(){
  return accName;
}

public void setUsername(String user){
  accName = user;
}

public String toString(){
  return accName;
}
}
