#include <iostream>
#include "VariousSorts.h"

const int MAX_ITEMS = 100;
using namespace std;

template<class ItemType>
void BubbleSort(ItemType values[], int numValues);

template<class ItemType>
ItemType * copyArray(ItemType values[], ItemType newItem);

template<class ItemType>
void ShortBubble(ItemType values[], int numValues);

template<class ItemType>
void SelectionSort(ItemType values[], int numValues);

template<class ItemType>
void InsertionSort(ItemType values[], int numValues);

template<class ItemType>
void MergeSort(ItemType[], int, int);

void Swap(int &a, int &b);

int main()
{
    cout << "Enter the number of values to enter for you list: "; int nums, num; cin >> nums;
    int *values = new int[nums];

    cout << "There will be " << nums << " values in you array. " << endl;

    for(int count = 0; count < nums; count++)
    {
        cout << "Enter num" << (count+1) << ": ";
        cin >> num;
        values[count] = num;
    }

    //BubbleSort(values, nums);
    //ShortBubble(values, nums);
    //SelectionSort(values, nums);
    //InsertionSort(values, nums);
    //MergeSort(values, 0, nums-1);

    for(int counter = 0; counter < nums; counter++)
        cout << "Num" << (counter+1) << ": " << values[counter] << endl;

    return 0;
}

template<class ItemType>
ItemType * copyArray(ItemType *values, ItemType newItem)
{
    int count;
    int sz = sizeof(values) / sizeof(values[0]);
    ItemType * temp = new ItemType[ sizeof(values) / sizeof(values[0]) + 1];
    for(count = 0; count < sz; count++)
        temp[count] = values[count];

    temp[count] = newItem;

    cout << "Is it working? " <<  count << endl;

    values = new ItemType[count+1];
    for(int counter = 0; counter < count; counter++)
    {
        cout << "Is it workign? " << endl;
        values[counter] = temp[counter];
    }
    cout << "Is it workign? " << endl;

    delete [] temp;

    return values;
}

template<class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex)
{
    for(int index = endIndex; index > startIndex; index--)
        if(values[index-1] > values[index])
            Swap(values[index-1], values[index]);
}

template<class ItemType>
void BubbleSort(ItemType values[], int numValues)
{
    int current = 0;

    while(current < (numValues-1))
    {
        BubbleUp(values, current, numValues);
        current++;
    }
}

template<class ItemType>
void BubbleUp2(ItemType values[], int startIndex, int endIndex, bool& sorted)
{
    sorted = true;
    for(int index = endIndex; index > startIndex; index--)
    {
        if(values[index] < values[index-1])
        {
            Swap(values[index], values[index-1]);
            sorted = false;
        }
    }
}

template<class ItemType>
void ShortBubble(ItemType values[], int numValues)
{
    int current = 0;
    bool sorted = false;

    while(current < (numValues-1) && !sorted)
    {
        BubbleUp2(values, current, numValues-1, sorted);
        current++;
    }
}

template<class ItemType>
int getMindex(ItemType values[], int startIndex, int endIndex)
{
    int indexOfMin = startIndex;

    for(int index = startIndex; index <= endIndex; index++)
        if(values[index] < values[indexOfMin])
            indexOfMin = index;

    return indexOfMin;
}

template<class ItemType>
void SelectionSort(ItemType values[], int numValues)
{
    int endIndex = numValues-1;
    int mindex;

    for(int current = 0; current < endIndex; current++)
    {
        mindex = getMindex(values, current, endIndex);
        Swap(values[current], values[mindex]);
    }
}

template<class ItemType>
void InsertItem(ItemType values[], int startIndex, int endIndex)
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);

    while(moreToSearch && !finished)
    {
        if(values[current] < values[current-1])
        {
            Swap(values[current], values[current-1]);
            current--;
            moreToSearch = (current != startIndex);
        }
        else
            finished = true;
    }
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues)
{
    for(int count = 0; count < numValues; count++)
        InsertItem(values, 0, count);
}

template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
    ItemType tempArray[MAX_ITEMS];
    int index = leftFirst; int saveFirst = leftFirst;

    while((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if(values[leftFirst] < values[rightFirst])
        {
            tempArray[index++] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index++] = values[rightFirst];
            rightFirst++;
        }
    }
    while(leftFirst <= leftLast)
    {

        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }
    while(rightFirst <= rightLast)
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    for(index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
}

template<class ItemType>
void MergeSort(ItemType values[], int first, int last)
{
    if(first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle);
        MergeSort(values, middle+1, last);
        Merge(values, first, middle, middle+1, last);
    }
}


