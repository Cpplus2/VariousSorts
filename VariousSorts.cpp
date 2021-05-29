#ifndef VARIOUSSORTS_CPP
#define VARIOUSSORTS_CPP

#include "VariousSorts.h"

const int MAX_ITEMS = 100;

template<class ItemType>
VariousSorts<ItemType>::VariousSorts()
{
    numValues = 0;
    values = NULL;
}

template<class ItemType>
VariousSorts<ItemType>::VariousSorts(ItemType newValues[], int numOfValues)
{
    numValues = numOfValues;
    values = newValues;
}


template<class ItemType>
VariousSorts<ItemType>::~VariousSorts()
{
    numValues = 0;
    values = NULL;
}


template<class ItemType>
bool VariousSorts<ItemType>::IsEmpty() const
{
    return (numValues == 0);
}

template<class ItemType>
bool VariousSorts<ItemType>::IsFull() const
{
    return (numValues == MAX_ITEMS);
}


template<class ItemType>
void VariousSorts<ItemType>::BubbleSort()
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
void VariousSorts<ItemType>::ShortBubble()
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
void VariousSorts<ItemType>::SelectionSort()
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
void VariousSorts<ItemType>::InsertionSort()
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
void VariousSorts<ItemType>::MergeSort()
{
    int first = 0; int last = numValues - 1;

    if(first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle);
        MergeSort(values, middle+1, last);
        Merge(values, first, middle, middle+1, last);
    }
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

#endif // VARIOUSSORTS_CPP
