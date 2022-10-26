public class Playlist extends ContentCollections{
  public Playlist(){
    super();
  }

  public Playlist(String playlistTitle){
    super(playlistTitle);
  }

  public void addContent(Content added){
    collection.add(added);
    System.out.println(added.getContentTitle());
  }
  public void removeContent(Content removed){
    collection.remove(removed);
    System.out.println(removed.getContentTitle());
  }

  public String toString(){
    return super.toString();
  }
}
