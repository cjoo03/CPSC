public class Podcast extends Content{
  private int episodeNum;

  public Podcast(){
    super();
    episodeNum = 0;
  }

  public Podcast(String title, ArtistAccount artistAcc, String[]genres, Boolean isSong, int streams){
    super(title, artistAcc, genres, false, streams);
  }

  public int getEpisodeNum(){
    return episodeNum;
  }

  public String toString(){
    return "Podcast Name: " + super.toString() + "\nEpisode #: " + episodeNum;
  }
}
