/*!
 * The AnyIndex of PetroCOVERY Solution is a collection of native C++ classes that implement the fundamental 
 * algorithms & operations required to satisfy COMMON DEMANDS of other packages, especially for those quick
 * spatial algorithms.
 *
 * Copyright (C) 2015 XIUJIE SHENG
 *
 * This library isn't a free software, so you cann't take the source code without author's permit.
 * Of course, there is NO ANY WARRANTY that this library will not harm your computer or ongoing 
 * business if you illegally got it. 
 *
 * NOTE: 
 * AUTHOR WOULD ALWAYS RESERVE LEGAL RIGHT TO PROTECT WHAT HE HAVE DONE ACCORDING TO
 * LOCAL OR INTERNATIONAL COPYRIGHT OR RELATIVE LAW(S).
 *
 * For more information, contact:
 *
 * China University of Geoseciences(Wuhan)
 * Resource Faculty
 *
 * Xiujie Sheng
 * herman.sheng@gmail.com
 */
#ifndef __ANYINDEX_JTS_BINARYTREENODE_H__
#define __ANYINDEX_JTS_BINARYTREENODE_H__

// Refer to its parent which has common implementation for kinds of nodes
#include "anyjtsbinarytreebase.h"

// Refer to its corresponding index
#include "anyinterval.h"

//
namespace AnyIndex
{
    /*!
    * Inner and leaf nodes of current binary tree except root node
    **/
    class CAnyJTSBinaryTreeNode : public CAnyJTSBinaryTreeBase
    {
    public:
        //
        //
        //
        /*!
        *
        **/
        CAnyJTSBinaryTreeNode(const CAnyInterval &curInterval, int level);

        /*!
        *
        **/
        virtual ~CAnyJTSBinaryTreeNode();

	private:
        /*!
		* Not permitted
        **/
        CAnyJTSBinaryTreeNode(const CAnyInterval &curInterval)
		{
		}

		/*!
		* Not permitted
		**/
		const CAnyJTSBinaryTreeNode &operator = (const CAnyJTSBinaryTreeNode &other)
		{
		}

    public:
        //
        // Basic interface for set and access methods
        //
        /*!
        *
        **/
        void Insert(const CAnyJTSBinaryTreeNode *oneNode);

        /*!
        *
        **/
        const CAnyInterval &GetInterval() const;

		//
		// Query Inerface
		//
        /*!
        * Here will build a path until find the leaf node
        **/
        CAnyJTSBinaryTreeBase *GetNode(const CAnyInterval &queryInterval);

        /*!
        * Here not do anything except for the suitable node
        **/
        CAnyJTSBinaryTreeBase *Find(const CAnyInterval &queryInterval);

        //
        //
        //
        /*!
        *
        **/
        static CAnyJTSBinaryTreeNode *CreateNode(const CAnyInterval &oneInterval);

        /*!
        *
        **/
        static CAnyJTSBinaryTreeNode *CreateExpanded(CAnyJTSBinaryTreeNode *node, const CAnyInterval &addInterval);

    protected:
        //
        //
        //
        /*!
        *
        **/
        bool IsSearchMatch(const CAnyInterval &curInterval);

    private:
        //
        //
        //
        /*!
        *
        **/
        CAnyJTSBinaryTreeNode *GetSubnode(int index);

        /*!
        *
        **/
        CAnyJTSBinaryTreeNode *CreateSubnode(int index);

    private:
        // Corresponding interval
	    CAnyInterval m_interval;

        //
	    double m_center;

        //
	    int m_level;
    };
}

#endif
