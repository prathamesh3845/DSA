#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct song {
    int id;
    string title;
    string artist;
    float duration;
    song* next;
};

class playList {
private:
    song* head = NULL;

public:
    void AddSongatpos() {
        song* nn = new song;
        cout << "Enter :-- Title <space> Artist <space> Duration: ";
        cin >> nn->title >> nn->artist >> nn->duration;
        nn->id = rand() % 1000; // Random ID generation
        nn->next = NULL;

        string t;
        cout << "Enter the title of the song after which you want to add the new song: ";
        cin >> t;

        if (head == NULL) {
            head = nn;
            cout << "Playlist was empty. Song added as the first song.\n";
            return;
        }

        song* temp = head;
        while (temp != NULL && temp->title != t) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song with title '" << t << "' not found.\n";
            delete nn; // Free allocated memory
        } else {
            nn->next = temp->next;
            temp->next = nn;
            cout << "Song added successfully after '" << t << "'.\n";
        }
    }

    void addbeg() {
        song* nn = new song;
        cout << "Enter :-- Title <space> Artist <space> Duration: ";
        cin >> nn->title >> nn->artist >> nn->duration;
        nn->id = rand() % 1000;
        nn->next = head;
        head = nn;
        cout << "Song added to the beginning.\n";
    }

    void addatend() {
        song* nn = new song;
        cout << "Enter :-- Title <space> Artist <space> Duration: ";
        cin >> nn->title >> nn->artist >> nn->duration;
        nn->id = rand() % 1000;
        nn->next = NULL;

        if (head == NULL) {
            head = nn;
            cout << "Playlist was empty. Song added as the first song.\n";
            return;
        }

        song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
        cout << "Song added to the end.\n";
    }

    void search() {
        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }

        string t;
        cout << "Enter the title of the song you want to search for: ";
        cin >> t;

        song* temp = head;
        while (temp != NULL && temp->title != t) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song with title '" << t << "' not found.\n";
        } else {
            cout << "Song found:\n";
            cout << "1. Song ID    : " << temp->id << endl;
            cout << "2. Title      : " << temp->title << endl;
            cout << "3. Artist     : " << temp->artist << endl;
            cout << "4. Duration   : " << temp->duration << endl;
        }
    }

    void delatstart() {
        if (head == NULL) {
            cout << "Playlist is empty! Can't delete.\n";
            return;
        }

        song* temp = head;
        head = head->next;
        cout << "Deleted song: " << temp->title << endl;
        delete temp;
    }

    void delatend() {
        if (head == NULL) {
            cout << "Playlist is empty! Can't delete.\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted the only song in the playlist.\n";
            return;
        }

        song* temp = head;
        song* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        cout << "Deleted song: " << temp->title << endl;
        delete temp;
    }

    void DeleteSong() {
        if (head == NULL) {
            cout << "Playlist is empty! Can't delete.\n";
            return;
        }

        string t;
        cout << "Enter the title of the song to delete: ";
        cin >> t;

        if (head->title == t) {
            song* temp = head;
            head = head->next;
            cout << "Deleted song: " << temp->title << endl;
            delete temp;
            return;
        }

        song* temp = head;
        while (temp->next != NULL && temp->next->title != t) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Song with title '" << t << "' not found.\n";
        } else {
            song* toDelete = temp->next;
            temp->next = toDelete->next;
            cout << "Deleted song: " << toDelete->title << endl;
            delete toDelete;
        }
    }

    void reverse() {
        if (head == NULL) {
            cout << "Playlist is empty! Can't reverse.\n";
            return;
        }

        song* prev = NULL;
        song* curr = head;
        song* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "Playlist reversed successfully.\n";
    }

    void delall() {
        while (head != NULL) {
            song* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All songs deleted.\n";
    }

    void DisplaySong() {
        if (head == NULL) {
            cout << "Your playlist is empty.\n";
            return;
        }

        song* temp = head;
        cout << "Songs in the playlist:\n";
        while (temp != NULL) {
            cout << "----------------------\n";
            cout << "1. Song ID    : " << temp->id << endl;
            cout << "2. Title      : " << temp->title << endl;
            cout << "3. Artist     : " << temp->artist << endl;
            cout << "4. Duration   : " << temp->duration << endl;
            temp = temp->next;
        }
    }
};

int main() {
    srand(time(0)); // Seed for random number generation
    playList p;

    cout << "Playlist Menu:\n";
    cout << "1. Add Song at a specific position\n";
    cout << "2. Add Song to the beginning\n";
    cout << "3. Add Song to the end\n";
    cout << "4. Search for a song\n";
    cout << "5. Delete the first song\n";
    cout << "6. Delete the last song\n";
    cout << "7. Delete a song by title\n";
    cout << "8. Reverse the playlist\n";
    cout << "9. Delete all songs\n";
    cout << "10. Display all songs\n";
    cout << "0. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                p.AddSongatpos();
                break;
            case 2:
                p.addbeg();
                break;
            case 3:
                p.addatend();
                break;
            case 4:
                p.search();
                break;
            case 5:
                p.delatstart();
                break;
            case 6:
                p.delatend();
                break;
            case 7:
                p.DeleteSong();
                break;
            case 8:
                p.reverse();
                break;
            case 9:
                p.delall();
                break;
            case 10:
                p.DisplaySong();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
