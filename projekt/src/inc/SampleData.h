#ifndef __LIBRARY_SAMPLE_DATA_H
#define __LIBRARY_SAMPLE_DATA_H

/**
 *  # ID CONVENTION
 *  ## Books 100***
 *  ## DVDs 110***
 *  ## Librarians 200***
 *  ## BasicMembers 300***
 *  ## PermiumMembers 310***
 *  ## Loans 400***
 */
void convention() {}

/**
 * @brief vector storing sample books
 * @param 0 keyID, 
 * @param 1 name, 
 * @param 2 author
 * @param 3 description, 
 * @param 4 editionDescription, 
 * @param 5 publicationYear, 
 * @param 6 numberOfPages, 
 * @param 8 numberOfCopies, 
 */
std::vector<std::tuple<int, const std::string, const std::string, const std::string, const std::string, int, int, int>> books = {
    std::make_tuple(
        100000, 
        "Introduction to the Design and Analysis of Algorithms: International Edition", 
        "Anany Levitin",
        "Based on a new classification of algorithm design techniques and a clear delineation of analysis methods, Introduction to the Design and Analysis of Algorithms presents the subject in a coherent and innovative manner. Written in a student-friendly style, the book emphasises the understanding of ideas over excessively formal treatment while thoroughly covering the material required in an introductory algorithms course. Popular puzzles are used to motivate students' interest and strengthen their skills in algorithmic problem solving.",
        "Third Edition", 
        2003, 592,
        1
    ),
    std::make_tuple(
        100001, 
        "Clean Code: A Handbook of Agile Software Craftsmanship", 
        "Robert C. Martin",
        "Clean Code is divided into three parts. The first describes the principles, patterns, and practices of writing clean code. The second part consists of several case studies of increasing complexity. Each case study is an exercise in cleaning up code—of transforming a code base that has some problems into one that is sound and efficient. The third part is the payoff: a single chapter containing a list of heuristics and \"smells\" gathered while creating the case studies. The result is a knowledge base that describes the way we think when we write, read, and clean code.",
        "1st Edition",
        2008, 464,
        2
    ),
    std::make_tuple(
        100002, 
        "The C++ Programming Language", 
        "Bjarne Stroustrup",
        "Written by the inventor of the language, The C++ Programming Language is the definitive, classic text on the language that has become central to software development over the years. This book introduces the C++ programming language and the techniques involved in writing high-quality, real-world programs. It covers the language's facilities, programming techniques, and idioms in detail, with the focus on the best practices and most efficient techniques.",
        "4th Edition",
        2013, 1368,
        2
    )
};


/** 
 * @brief vector storing sample DVDs
 * @param 0 keyID, 
 * @param 1 name, 
 * @param 2 author
 * @param 3 description, 
 * @param 4 audio, 
 * @param 5 video, 
 * @param 6 lengthInMinutes, 
 * @param 7 numberOfCopies, 
*/
std::vector<std::tuple<int, const std::string, const std::string, const std::string, bool, bool, int, int>> dvds = {
    std::make_tuple(
        110000, 
        "The Shawshank Redemption", 
        "Frank Darabont", 
        "Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency.", 
        true, false, 
        142,
        1
    ),
    std::make_tuple(
        110001, 
        "The Godfather", 
        "Francis Ford Coppola", 
        "The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son.", 
        true, true, 
        175,
        2
    ),
    std::make_tuple(
        110002, 
        "The Dark Knight", 
        "Christopher Nolan", 
        "When the menace known as the Joker wreaks havoc and chaos on the people of Gotham, Batman must accept one of the greatest psychological and physical tests of his ability to fight injustice.", 
        true, false, 
        152,
        2
    ),
};

/**
 * @brief Vector storing the sample librarians.
 * @param 0 int keyID, 
 * @param 1 const std::string forename, 
 * @param 2 const std::string surname
 * @param 3 int salary, 
 * @param 4 time_t timeOfEmployment,
*/
std::vector<std::tuple<int, const std::string, const std::string, int, time_t>> librarians = {
    std::make_tuple(200000, "John", "Doe", 50000, time(nullptr)),
    std::make_tuple(200001, "Jane", "Smith", 55000, time(nullptr)),
    std::make_tuple(200002, "David", "Johnson", 48000, time(nullptr)),
    std::make_tuple(200003, "Emily", "Williams", 52000, time(nullptr)),
};

/**
 * @brief Vector of BasicMembers
 * @param 0 int keyID, 
 * @param 1 const std::string forename, 
 * @param 2 std::string& surname, 
*/
std::vector<std::tuple<int, const std::string, const std::string>> bmembers = {
    std::make_tuple(300000, "Johnny", "Doeb"),
    std::make_tuple(300001, "Janice", "Smithy"),
    std::make_tuple(300002, "Jennifer", "Jones"),
    std::make_tuple(300003, "Christopher", "Miller"),
};

/**
 * @brief Vector of PremiumMembers
 * @param 0 int keyID, 
 * @param 1 const std::string forename, 
 * @param 2 std::string& surname, 
 * @param 3 int bonusPoints,
*/
std::vector<std::tuple<int, const std::string, const std::string, int>> pmembers = {
    std::make_tuple(310000, "David", "Johnson", 200),
    std::make_tuple(310001, "Emily", "Williams", 180),
    std::make_tuple(310002, "Michael", "Brown", 220),
};

#endif//__LIBRARY_SAMPLE_DATA_H