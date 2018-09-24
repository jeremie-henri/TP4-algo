#ifndef CRANDOMTREE_HPP
#define CRANDOMTREE_HPP

#include <cstdlib> //rand ()
#include <memory.h> // shared_ptr (), ...
#include <iostream> // rand ()
#include "node.hpp"

template <typename T>
class RDTree
{
  private:
    //T m_data;
    std::shared_ptr<CNode<T>> m_Root;
    //void localAdd (const std::shared_ptr<CNode<T>> & ptr, const T &Val);
   // void localShow (const std::shared_ptr<CNode<T>> & ptr);
  public:
    RDTree (const T & val);
    ~ RDTree() {}
    void add (const T & Val);
    bool find(const T & Val);
    void show () const;
};

template<typename T>
RDTree<T>::RDTree(const T &val)
{
    std::shared_ptr<CNode <T>> tmp (new CNode<T> (val));
    m_Root = tmp;
}

template<typename T>
void localAdd (const std::shared_ptr<CNode<T>> & ptr, const T &Val)
{
    if(ptr->getLC() == nullptr)
    {
        std::shared_ptr<CNode<T>> tmp (new CNode<T>(Val));
        ptr->setLC(tmp);
    }
    else if(ptr->getRC() == nullptr)
    {
        std::shared_ptr<CNode<T>> tmp (new CNode<T>(Val));
        ptr->setRC(tmp);
    }
}

template<typename T>
void RDTree<T>::add(const T &Val)
{
    if (Val < m_Root->GetData())
        localAdd(m_Root,Val);

}


template<typename T>
void localShow (const std::shared_ptr<CNode<T>> & ptr)
{
    if (ptr == nullptr) return;
    localShow (ptr->getLC());
    std::cout << ptr->GetData () << std::endl;
    localShow (ptr->getRC());
}


template<typename T>
void RDTree<T>::show () const
{

    std::cout << m_Root->GetData () << std::endl;
    localShow (m_Root->getLC());
    localShow (m_Root->getRC());
}

template <typename T>
bool RDTree<T>::find(const T & Val)
{
    return localFind(m_Root,Val);
}


template <typename T>
bool localFind (const std::shared_ptr<CNode<T>> & ptr,const T & Val)
{
    if(ptr->GetData() == Val)
    {
        std::cout<<"trouvé"<<std::endl;
        return true;
}
    else if (Val < ptr->GetData() && ptr->getLC() != nullptr)
    {
        localFind(ptr->getLC(),Val);
    }
    else if (Val > ptr->GetData() && ptr->getRC() != nullptr)
    {
        localFind(ptr->getRC(),Val);
    }
    else
    {
        std::cout<<"pas trouvé"<<std::endl;
    }
    return false;

}


#endif // CRANDOMTREE_HPP
