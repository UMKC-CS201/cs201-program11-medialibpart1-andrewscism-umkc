#include "MediaLib.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream mediaListFile("mediaList.txt");
    if (!mediaListFile.is_open())
    {
        std::cerr << "Error opening media list file" << std::endl;
        return 1;
    }

    std::ifstream mediaCommandsFile("mediaCommands.txt");
    if (!mediaCommandsFile.is_open())
    {
        std::cerr << "Error opening media commands file" << std::endl;
        return 1;
    }

    std::ofstream reportFile("report.txt");
    if (!reportFile.is_open())
    {
        std::cerr << "Error opening report file" << std::endl;
        return 1;
    }

    std::ofstream errorFile("error.txt");
    if (!errorFile.is_open())
    {
        std::cerr << "Error opening error file" << std::endl;
        return 1;
    }

    std::vector<Media> mediaData;
    readMediaList(mediaListFile, errorFile, mediaData);

    char action;
    while (mediaCommandsFile >> action)
    {
        switch (action)
        {
        case 'M':
            printMovieList(std::cin, reportFile, errorFile, mediaData);
            break;
        case 'B':
            printBookList(std::cin, reportFile, errorFile, mediaData);
            break;
        case 'S':
            printSongList(std::cin, reportFile, errorFile, mediaData);
            break;
        case 'A':
            printAllMedia(std::cin, reportFile, errorFile, mediaData);
            break;
        case 'N':
            addNewMedia(mediaCommandsFile, reportFile, errorFile, mediaData);
            break;
        case 'T':
            printTotals(reportFile);
            break;
        case 'Q':
            std::cout << "Exiting program" << std::endl;
            break;
        default:
            errorFile << "Error: Invalid action '" << action << "' encountered" << std::endl;
            break;
        }
    }

    mediaListFile.close();
    mediaCommandsFile.close();
    reportFile.close();
    errorFile.close();

    return 0;
}
