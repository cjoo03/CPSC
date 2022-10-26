public class Song extends Content{

  public Song(){
    super();
  }

  public Song(String title, ArtistAccount artistAcc, int streams, String[]genres){
    super(title, artistAcc, genres, true ,streams);
  }

  public String toString(){
    return super.toString();
  }
}
