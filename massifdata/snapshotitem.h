/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef SNAPSHOTITEM_H
#define SNAPSHOTITEM_H

#include <ctime>

namespace Massif
{

class TreeLeafItem;

class SnapshotItem
{
public:
    SnapshotItem();
    ~SnapshotItem();

    /**
     * Sets the number of this snapshot.
     */
    void setNumber(const unsigned int num);
    /**
     * Returns the number of this snapshot.
     */
    unsigned int number() const;

    /**
     * Sets the time at which this snapshot was taken.
     */
    void setTime(const std::time_t time);
    /**
     * @return The time at which this snapshot was taken.
     */
    std::time_t time() const;

    /**
     * Sets the size of the memory heap in bytes.
     */
    void setMemHeap(const unsigned int bytes);
    /**
     * @return The size of the memory heap in bytes.
     */
    unsigned int memHeap() const;

    /**
     * Sets the size of the extra memory heap in bytes.
     */
    void setMemHeapExtra(const unsigned int bytes);
    /**
     * @return The size of the extra memory heap in bytes.
     */
    unsigned int memHeapExtra() const;

    /**
     * Sets the size of the memory stacks in bytes.
     */
    void setMemStacks(const unsigned int bytes);
    /**
     * @return The size of the memory stacks in bytes.
     */
    unsigned int memStacks() const;

    /**
     * Sets @p root as root node of the detailed heap tree of this snapshot.
     */
    void setHeapTree(TreeLeafItem* root);
    /**
     * @return The root node of the detailed heap tree or zero if none is set.
     */
    TreeLeafItem* heapTree();

private:
    unsigned int m_number;
    std::time_t m_time;
    unsigned int m_memHeap;
    unsigned int m_memHeapExtra;
    unsigned int m_memStacks;
    TreeLeafItem* m_heapTree;
};

}

#endif // SNAPSHOTITEM_H