import java.util.*;

public abstract class ContentCollections implements Comparable<ContentCollections>{
  protected String collectionTitle;
  protected LinkedList<Content> collection;
  Random rand = new Random();
  private int i;

  public ContentCollections(){
    collectionTitle = "";
    collection = new LinkedList<Content>();
    i = 0;
  }

  public ContentCollections(String title){
    collectionTitle = title;
    collection = new LinkedList<Content>();
  }

  public String getCollectionTitle(){
    return collectionTitle;
  }

  public LinkedList<Content> getCollection(){
    return collection;
  }

  public void setCollectionTitle(String cTitle){
    collectionTitle = cTitle;
  }

  public void shuffle(){
    int r = rand.nextInt(collection.size());
    collection.get(i).play();
  }

  public int compareTo(ContentCollections o){
    if (this.collection.size() < o.getCollection().size()){
      return -1;
    }
    else if (this.collection.size() == o.getCollection().size()){
      return 0;
    }
    else{
      return 1;
    }
  }

  public String toString(){
    return "Title: " + collectionTitle + "\nCollection: " + collection;
  }

}
