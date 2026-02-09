#include "objPosArrayList.h"
#include "objPos.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 200;
    aList = new objPos[arrayCapacity];
    insertHead(objPos());
    insertTail(objPos(2, 2, '1'));
    insertTail(objPos(2, 3, '2'));    
    
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity) // check is list is not full already
    {
        return;
    }   

    listSize++; // increase size of list in order to shift everything towards the tail

    for (int i = listSize; i > 0; i--) // shifting towards tail
    {
        aList[i] = aList[i-1];
    }
    
    aList[0] = thisPos;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity) // check is list is not full already
    {
        return;
    }

    aList[listSize++] = thisPos;  
}

void objPosArrayList::removeHead()
{
    if (listSize <= 0)
    {
        return;
    }
    

    for (int i = 0; i < listSize; i++)
    {
        aList[i] = aList[i+1];
    }
    
    listSize--;
}

void objPosArrayList::removeTail()
{
    if (listSize > 0)
    {
        listSize--;
    }

    else 
    {
        return;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];   
}

objPos objPosArrayList::getElement(int index) const
{
    if(index >= arrayCapacity)
    {
        return aList[listSize-1];
    }

    else if(index < 0)
    {
        return aList[0];
    }
    else
    {
    return aList[index];
    }
}