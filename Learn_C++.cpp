#include <iostream>
#include <list>

using namespace std;

class YoutubeChannel {
private: //This Private only accessable in same class not the outside class.
    string name;
    int subscribers;
    list<string> publishedVideo;
protected: // This Protected can be accessed by any subclass (derived class).
    string ownerChannel;
public: //This Public accessable in or outside class.
    //Create Constructor
    YoutubeChannel(string name, string ownerChannel, int subs = 0) {
        this->name = name;
        this->ownerChannel = ownerChannel;
        subscribers = subs;
    }

    //Create Method GetInfo
    void GetInfo() {
        cout << "My channel is " << name << endl;
        cout << "Owner is " << ownerChannel << endl;
        cout << "Subscribers " << subscribers << endl;
        cout << "My videos: " << endl;
        for (string myVideo : publishedVideo) {
            cout << myVideo << endl;
        }
    }

    //Create method publishVideo
    void publishVideo(string video) {
        publishedVideo.push_back(video);
    }

    //Create method unsubscibe
    void unsubscribe(int unsubs) {
        if (subscribers > 0)
            subscribers -= unsubs;
    }
};

class CookingYoutubeChannel:public YoutubeChannel {
public:
    CookingYoutubeChannel(string name, string ownerName):YoutubeChannel(name, ownerName) {}
};

int main()
{
    CookingYoutubeChannel ytChannel("Giveonaldo", "Aldo");
    ytChannel.GetInfo();



    system("pause>0");
}

// Note: If we do not specify any access modifiers for the members inside the class, then by default the access modifier for the members will be Private.
