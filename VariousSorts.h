#ifndef VARIOUSSORTS_H
#define VARIOUSSORTS_H

#include<iostream>

template<class ItemType>
class VariousSorts
{
    private:
        ItemType values[];
        int numValues;

    public:
        VariousSorts();
        VariousSorts(ItemType newValues[], int numOfValues);
        ~VariousSorts();
        bool IsEmpty() const;
        bool IsFull() const;
        void BubbleSort();
        void ShortBubble();
        void SelectionSort();
        void InsertionSort();
        void MergeSort();
};

#endif // VARIOUSSORTS_H
