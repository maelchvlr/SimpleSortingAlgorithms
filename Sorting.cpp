#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<int> bubbleSort(std::vector<int> valuesToSort)
{
    for (int i = 0; i < valuesToSort.size() - 1; i++)
    {
        for (int j = i + 1; j < valuesToSort.size(); j++)
        {
            if (valuesToSort[i] > valuesToSort[j])
            {
                int save = valuesToSort[j];
                valuesToSort[j] = valuesToSort[i];
                valuesToSort[i] = save;
            }
        }
    }

    return valuesToSort;
}

std::vector<int> quickSort(std::vector<int> valuesToSort)
{
    if(valuesToSort.size() <= 1)
    {
        return valuesToSort;
    }

    int pivot = valuesToSort.size()-1;

    for(int i = 0; i < pivot;)
    {
        if(valuesToSort[i] > valuesToSort[pivot])
        {
            int temp = valuesToSort[i];
            valuesToSort[i] = valuesToSort[pivot-1];
            valuesToSort[pivot-1] = valuesToSort[pivot];
            valuesToSort[pivot] = temp;
            pivot -= 1;
        }
        else
        {
            i += 1;
        }
    }

    std::vector<int> half1 (valuesToSort.begin(), valuesToSort.begin() + pivot);
    std::vector<int> half2 (valuesToSort.begin() + pivot, valuesToSort.end());

    half1 = quickSort(half1);
    half2 = quickSort(half2);

    half1.insert(half1.end(), half2.begin(), half2.end());
    return half1;
}

int main(int argc, char *argv[])
{
    char in;
    std::vector<int> valuesToSort;
    string values;
    string currentValue;
    std::cout << "Enter an array of values separated by a comma (Example: 5,7,8,4,3)" << std::endl;
    getline(cin, values);
    
    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] != ',')
        {
            currentValue.push_back(values[i]);
        }
        else{
            valuesToSort.emplace_back(stoi(currentValue));
            currentValue.clear();
        }
    }

    valuesToSort.emplace_back(stoi(currentValue));
    std::cout << "Enter number depending on which sorting you want, Bubbles (0), QuickSort (1)" << std::endl;
    std::cin >> in;
    cin.ignore();

    if (in < '0' || in > '5')
    {
        std::cout << "Error, only enter one of the options provided" << std::endl;
        return 1;
    }

    switch (in - '0')
    {
    case 0:
        valuesToSort = bubbleSort(valuesToSort);
        break;
    case 1:
        valuesToSort = quickSort(valuesToSort);

    default:
        break;
    }

    std::cout << "Here are your sorted values : ";
    for (auto i : valuesToSort)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}