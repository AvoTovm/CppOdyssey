# Adapter Design Pattern

### The Adapter Design Pattern allows incompatible interfaces to work together. It acts as a bridge between two classes by wrapping an existing class with a new interface. This pattern is also known as the Wrapper Pattern.

## Code

### 1.Original Class

  + ThirdPartyAudioPlayer: Represents the existing interface or functionality that we want to adapt.

    ```cpp
    class ThirdPartyAudioPlayer{
      public:
          void playAudioFile(const string& fileName){
              cout << "Playing audio file -- " << fileName << endl;
          }
    };
    ```
### 2. Target Interface
  + MediaPlayer: The interface expected by the system, which abstracts media playback.

    ```cpp
    class MediaPlayer{
    public:
        virtual void playMedia(const string& fileName) = 0;
        virtual ~MediaPlayer() = default;
    };
    ```

### 3. Concrete Implementation
  + OurMediaPlayer: Implements MediaPlayer for video playback.

    ```cpp
    class OurMediaPlayer : public MediaPlayer{
    public:
        void playMedia(const string& fileName) override{
            cout << "Playing video file -- " << fileName << "\n";
        }
    };
    ```
### 4. Adapter Class
  + AudioPlayerAdapter: Adapts the ThirdPartyAudioPlayer to the MediaPlayer interface.

    ```cpp
    class AudioPlayerAdapter : public MediaPlayer{
    private:
        ThirdPartyAudioPlayer* audioPlayer;

    public:
        AudioPlayerAdapter(ThirdPartyAudioPlayer* player) : audioPlayer(player){}

        void playMedia(const string& fileName) override{
            audioPlayer->playAudioFile(fileName);
        }
    };
    ```

### 5. Usage in main Function
  + Create instances of OurMediaPlayer and AudioPlayerAdapter to demonstrate video and audio playback.

    ```cpp
    int main() {
    MediaPlayer* videoPlayer = new OurMediaPlayer();
    videoPlayer->playMedia("movie.mp4");

    ThirdPartyAudioPlayer* thirdPartyPlayer = new ThirdPartyAudioPlayer();
    MediaPlayer* audioPlayer = new AudioPlayerAdapter(thirdPartyPlayer);
    audioPlayer->playMedia("song.mp3");

    delete videoPlayer;
    delete audioPlayer;
    delete thirdPartyPlayer;
    }
    ```

## Output

![image](https://github.com/user-attachments/assets/7a320d85-66e8-4bd9-a511-53a215e07cfa)

## Key Benefits of the Adapter Pattern

1. Interface Compatibility: Allows two incompatible interfaces to work together seamlessly.
2. Reusability: Enables the use of existing functionality (e.g., ThirdPartyAudioPlayer) without modifications.
3. Flexibility: Makes the system more extensible by decoupling client code from specific implementations.
