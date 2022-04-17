#include "Movies.h"
#include "Podcasts.h"
#include "Books.h"
#include <iostream>

using namespace std;

int main() {
    Movies *movies = new Movies();
    Podcasts *podcasts = new Podcasts();
    Books *books = new Books();

    string medium;
    string first;
    string second;
    string third;

    cout << "Would you like a book, podcast, or movie?" << endl;
    cin >> medium;
    cout << "What is your first priority: genre, rating, publication date?" << endl;
    cin >> first;
    cout << "What is your second priority: genre, rating, publication date?" << endl;
    cin >> second;
    cout << "What is your third priority: genre, rating, publication date?" << endl;
    cin >> third;
    string genre;
    string rating;
    string publicationDate;
    if(medium == "book"){
        cout << "Select a genre: " << endl;
        cout << "Accidents\n"
                "Act\n"
                "Adolescence\n"
                "Adventure\n"
                "Advertising\n"
                "Africa\n"
                "Aging\n"
                "Agriculture\n"
                "Air\n"
                "Alcohol\n"
                "Allegories\n"
                "American\n"
                "Ancient\n"
                "Angels\n"
                "Anger\n"
                "Animal\n"
                "Antiheroes\n"
                "Antiques & Collectibles\n"
                "Antisemitism\n"
                "Antislavery movements\n"
                "Apartheid\n"
                "Arab\n"
                "Archaeology\n"
                "Architecture\n"
                "Arctic regions\n"
                "Arithmetic\n"
                "Art\n"
                "Audiobooks\n"
                "Australia\n"
                "Autobiography\n"
                "Baggins\n"
                "Ballet\n"
                "Banks\n"
                "Battle\n"
                "Behavior\n"
                "Beowulf\n"
                "Bible\n"
                "Bilbo\n"
                "Biography\n"
                "Birds\n"
                "Blind\n"
                "Boarding school\n"
                "Boats boating\n"
                "Body\n"
                "Bond\n"
                "Boys\n"
                "Bracelets\n"
                "Brewing\n"
                "British\n"
                "Brothers\n"
                "Bullying\n"
                "Bus travel\n"
                "Business\n"
                "Butlers\n"
                "C (Computer program language)\n"
                "Cabrillo\n"
                "Cambridge (Mass.)\n"
                "Canada\n"
                "Cancer\n"
                "Candy\n"
                "Capitalism\n"
                "Cat\n"
                "Caterpillars\n"
                "Catholic\n"
                "Cellists\n"
                "Chick\n"
                "Children\n"
                "Chilean\n"
                "China\n"
                "Chocolate\n"
                "Christian\n"
                "Christmas\n"
                "Civil law\n"
                "Classical\n"
                "Comedy\n"
                "Comic\n"
                "Computer\n"
                "Confucianism\n"
                "Conspiracies\n"
                "Cook\n"
                "Crime\n"
                "Crusades\n"
                "Cuban\n"
                "Cults\n"
                "Death\n"
                "Democracy\n"
                "Detective\n"
                "Diaries\n"
                "Disasters\n"
                "Divorce\n"
                "Dracula\n"
                "Dragons\n"
                "Drama\n"
                "East\n"
                "Education\n"
                "Egypt\n"
                "English\n"
                "Epidemics\n"
                "Essays\n"
                "Fairy tales\n"
                "Family\n"
                "Fantasy\n"
                "Fiction\n"
                "Folklore\n"
                "Foreign Language Study\n"
                "French\n"
                "Gambling\n"
                "Games\n"
                "Gangs\n"
                "Gardening\n"
                "Girls\n"
                "Heroes\n"
                "History\n"
                "Horror\n"
                "Humor\n"
                "Law\n"
                "Leadership\n"
                "Literature\n"
                "Love\n"
                "Love poetry\n"
                "Magic\n"
                "Mathematics\n"
                "Medical\n"
                "Meditation\n"
                "Misogyny\n"
                "Modern\n"
                "Murder\n"
                "Music\n"
                "Mythology\n"
                "Novelists\n"
                "Performing Arts\n"
                "Personal\n"
                "Pets\n"
                "Philosophy\n"
                "Photography\n"
                "Physics\n"
                "Poetry\n"
                "Presidents\n"
                "Psychology\n"
                "Religion\n"
                "Roman\n"
                "Science\n"
                "Short stories\n"
                "Social action\n"
                "Sports Recreation\n"
                "Stone age\n"
                "Surealism\n"
                "Technology\n"
                "Teenagers\n"
                "Television\n"
                "Travel\n"
                "United States\n"
                "Vampires\n"
                "War\n"
                "Young Adult Fiction\n"
                "Zoology" << endl;
        cin >> genre;
        cout << "Select a rating (float between 1.0  and 5.0): " << endl;
        cin >> rating;
        cout << "Enter a publication Date: " << endl;
        cin >> publicationDate;
    }
    if(medium == "podcast"){
        cout << "Select a genre: " << endl;
        cout << "Music\n"
                "Arts\n"
                "Performing\n"
                "Design\n"
                "Literature\n"
                "Food\n"
                "Fashion & Beauty\n"
                "Society & Culture\n"
                "Gadgets\n"
                "Business\n"
                "Investing\n"
                "Management & Marketing\n"
                "Careers\n"
                "Shopping\n"
                "Self-Help\n"
                "Sports & Recreation\n"
                "Education\n"
                "Language Courses\n"
                "Higher Education\n"
                "Educational Technology\n"
                "Training\n"
                "Tech News\n"
                "Automotive\n"
                "Video Games\n"
                "Hobbies\n"
                "Games & Hobbies\n"
                "Other Games\n"
                "Aviation\n"
                "Places & Travel\n"
                "Government & Organizations\n"
                "Non-Profit\n"
                "National\n"
                "Regional\n"
                "Local\n"
                "News & Politics\n"
                "Kinds & Family\n"
                "Social Sciences\n"
                "Health\n"
                "Sexuality\n"
                "Philosophy\n"
                "Fitness & Nutrition\n"
                "TV & Film\n"
                "Science & Medicine \n"
                "Christianity\n"
                "Spirituality\n"
                "Religion & Spirituality\n"
                "Natural Sciences\n"
                "Personal Journals\n"
                "Professional\n"
                "College & High School\n"
                "Outdoor\n"
                "Amateur\n"
                "Technology\n"
                "Software How-to\n"
                "Podcasting" << endl;
        cin >> genre;
        cout << "Select a rating (float between 1.0  and 5.0): " << endl;
        cin >> rating;
        cout << "Enter a publication Date: " << endl;
        cin >> publicationDate;
    }
    if(medium == "movie"){
        cout << "Select a genre: " << endl;
        cout << "Animation\n"
                "Adventure\n"
                "Comedy\n"
                "Action\n"
                "Family\n"
                "History\n"
                "Drama\n"
                "Fantasy\n"
                "Science Fiction\n"
                "War\n"
                "Crime\n"
                "Romance\n"
                "Horror\n"
                "Thriller\n"
                "Mystery\n"
                "Foreign\n"
                "Documentary\n"
                "Western" << endl;
        cin >> genre;
        cout << "Select a rating (float between 1.0  and 5.0): " << endl;
        cin >> rating;
        cout << "Enter a publication Date: " << endl;
        cin >> publicationDate;
    }
    // creating a data structure for the input so that the data can be parsed
    

    delete movies;
    delete podcasts;
    delete books;
    return 0;
}
