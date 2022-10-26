import java.util.*;
import java.io.*;

public class MusicDriver{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    ListenerAccount listenerAcc1 = new ListenerAccount();
    ArrayList <Content> songCollection = new ArrayList<Content>();

    //create playlist
    Playlist playlist1 = new Playlist();
    playlist1.setCollectionTitle("music that will tickle your funny bone");

    //create album
    Album firstAlbum = new Album();
    ArtistAccount artistAcc1 = new ArtistAccount("Post Malone");
    firstAlbum.setCollectionTitle("Hollywood's Bleeding");
    firstAlbum.setAlbumArtist(artistAcc1);

    //creates song
    String[] PMGenres = {"R&B", "Hip-hop", "Rap"};
    Song firstSong = new Song("Circles", artistAcc1, 102930192, PMGenres);
    firstAlbum.getCollection().add(firstSong);
    songCollection.add(firstSong);

    Song secondSong = new Song("Hollywood's Bleeding", artistAcc1, 221010240, PMGenres);
    firstAlbum.getCollection().add(secondSong);
    songCollection.add(secondSong);

    Song thirdSong = new Song("Goodbyes", artistAcc1, 2100310230, PMGenres);
    firstAlbum.getCollection().add(thirdSong);
    songCollection.add(thirdSong);

    System.out.println("What would you like to do?");
    System.out.println("1.) Create a listener account.\n 2.) List all playlists and albums avaliable to shuffle.\n 3.) Add songs to an existing playlist.\n 4.) Export all songs on the platformm out to a file in ascending order by times streamed\n 5.) Exit\n");
    int option = scan.nextInt();

    while (option != 5){
      if (option == 1){
        System.out.println("Enter the desired username:\n ");
        String userName = scan.next();
        listenerAcc1.setUsername(userName);
        System.out.println("Your listener account has been created " + listenerAcc1);
        System.out.println("1.) Create a listener account.\n 2.) List all playlists and albums avaliable to shuffle.\n 3.) Add songs to an existing playlist.\n 4.) Export all songs on the platformm out to a file in ascending order by times streamed\n 5.) Exit\n");
        option = scan.nextInt();
      }
      else if (option == 2){
        System.out.println("Playlists: " + playlist1.getCollectionTitle());
        System.out.println("Albums: " + firstAlbum.getCollectionTitle());
        System.out.println(firstAlbum.getCollectionTitle() + "'s Contents:\n " + "Songs:\n " + firstSong.getContentTitle() + "\n " + secondSong.getContentTitle() + "\n " + thirdSong.getContentTitle() + "\n" + "Genres: " + PMGenres[0] + ", " + PMGenres[1] + ", " + PMGenres[2]);
        System.out.println("1.) Create a listener account.\n 2.) List all playlists and albums avaliable to shuffle.\n 3.) Add songs to an existing playlist.\n 4.) Export all songs on the platformm out to a file in ascending order by times streamed\n 5.) Exit\n");
        option = scan.nextInt();
        }
      else if (option == 3){
        System.out.println("Which songs would you like to add to " + playlist1.getCollectionTitle());
        System.out.println("1. " + firstSong.getContentTitle()  + "\n2. " + secondSong.getContentTitle()  + "\n3. " + thirdSong.getContentTitle());
        int songNum = scan.nextInt();
        if (songNum == 1){
          playlist1.addContent(firstSong);
          System.out.println(firstSong.getContentTitle() + " has been added to " + playlist1.getCollectionTitle());
        }
        else if (songNum == 2){
          playlist1.addContent(secondSong);
          System.out.println(secondSong.getContentTitle() + " has been added to " + playlist1.getCollectionTitle());
        }
        else {
          playlist1.addContent(thirdSong);
          System.out.println(thirdSong.getContentTitle() + " has been added to " + playlist1.getCollectionTitle());
        }
        System.out.println("1.) Create a listener account.\n 2.) List all playlists and albums avaliable to shuffle.\n 3.) Add songs to an existing playlist.\n 4.) Export all songs on the platform out to a file in ascending order by times streamed\n 5.) Exit\n");
        option = scan.nextInt();
      }
      else if (option == 4){
        try {
          FileWriter fw = new FileWriter("exportedSongs.txt");
          fw.write("Songs on platform\n");
          for (int i = 0; i < songCollection.size(); i++){
            fw.write(songCollection.get(i).getContentTitle() + " has " + songCollection.get(i).getStreams() + " streams.");
            fw.write("\n");
          }
          fw.close();
        } catch (IOException e){
          System.out.println("Error");
          e.printStackTrace();
        }
          System.out.println("1.) Create a listener account.\n 2.) List all playlists and albums avaliable to shuffle.\n 3.) Add songs to an existing playlist.\n 4.) Export all songs on the platformm out to a file in ascending order by times streamed\n 5.) Exit\n");
          option = scan.nextInt();
        }
        else if (option == 5){
          break;
        }
        else {
          System.out.println("Not a valid option");
          System.out.println("1.) Create a listener account.\n 2.) List all playlists and albums avaliable to shuffle.\n 3.) Add songs to an existing playlist.\n 4.) Export all songs on the platformm out to a file in ascending order by times streamed\n 5.) Exit\n");
          option = scan.nextInt();
        }
      }
    }
  }
