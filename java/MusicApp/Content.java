  import java.util.ArrayList;

  public abstract class Content implements Comparable<Content>{
    protected String contentTitle;
    protected ArtistAccount artAcc;
    protected int streams;
    protected boolean isSong;
    protected String[] genres;

  public Content(){
    contentTitle = " ";
    artAcc = null;
    streams = 0;
    genres = new String[3];
}

  public Content(String contentTitle, ArtistAccount artAcc, String[]genres, Boolean song, int streams){
    this.contentTitle = contentTitle;
    this.artAcc = artAcc;
    this.streams = streams;
    this.isSong = song;
    this.genres = genres;
  }
  public ArtistAccount getArtist(){
    return artAcc;
  }

  public String getContentTitle(){
    return contentTitle;
  }

  public int getStreams(){
    return streams;
  }

  public String getGenre(){
    String s = "";
    for (int i = 0; i < genres.length; i++){
      s += genres[i];
    }
    return s;
  }

  public boolean getSong(){
    return isSong;
  }

  public void setContentTitle(String cTitle){
    contentTitle = cTitle;
  }

  public void setArtist(ArtistAccount art){
    artAcc = art;
  }

  public void setGenres(String[] genres){
    this.genres = genres;
  }

  public void setPlays(int plays){
    streams = plays;
  }

  public void setSong(Boolean song){
    isSong = song;
  }

  public void play(){
    streams++;
  }

  public int compareTo(Content c){
    if (this.streams < c.getStreams()){
      return -1;
    }
    else if (this.streams == c.getStreams()){
      return 0;
    }
    else{
      return 1;
    }
  }
  public String toString(){
  String s = "";
  for (int i = 0; i < genres.length; i++){
    s += genres[i];
  }
  return ("Song: " + contentTitle + "\nArtist: " + artAcc + "\nGenre: " + genres);
}
}
