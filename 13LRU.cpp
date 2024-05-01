// LRU Page Replacement Algorithm
#include <iostream>
#include <vector>
#include <algorithm>

int findLRU(std::vector<int>& time, int n)
{
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int no_of_frames, no_of_pages;
    std::cout << "Enter number of frames: ";
    std::cin >> no_of_frames;
    std::cout << "Enter number of pages: ";
    std::cin >> no_of_pages;

    std::vector<int> frames(no_of_frames, -1);
    std::vector<int> pages(no_of_pages);
    std::vector<int> time(no_of_frames);
    int counter = 0, faults = 0, hits = 0;

    std::cout << "Enter reference string: ";
    for (int i = 0; i < no_of_pages; ++i)
    {
        std::cin >> pages[i];
    }

    for (int i = 0; i < no_of_pages; ++i)
    {
        bool flag1 = false, flag2 = false;
        for (int j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                hits++;
                flag1 = flag2 = true;
                break;
            }
        }
        if (!flag1)
        {
            for (int j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = true;
                    break;
                }
            }
        }
        if (!flag2)
        {
            int pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        std::cout << std::endl;
        for (int j = 0; j < no_of_frames; ++j)
        {
            std::cout << frames[j] << "\t";
        }
    }

    std::cout << "\nTotal Page Faults = " << faults << std::endl;
    std::cout << "Total Hits = " << hits << std::endl;
    return 0;
}

