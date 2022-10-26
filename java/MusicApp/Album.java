public class Album extends ContentCollections{
  protected ArtistAccount albumArtist;

  public Album(){
    super();
    albumArtist = new ArtistAccount();
  }

  public Album(ArtistAccount albumArtist, String albumTitle){
    super(albumTitle);
    this.albumArtist = albumArtist;
  }

  public ArtistAccount getAlbumArtist(){
    return albumArtist;
  }

  public void setAlbumArtist(ArtistAccount albumArtist){
    this.albumArtist = albumArtist;
  }

  public String toString(){
    return albumArtist.getUsername() + "\n" + super.toString();
  }
}
