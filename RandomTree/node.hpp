#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode> m_LC;
    std::shared_ptr<CNode> m_RC;
public:
    //constructor
    CNode (const T &  val, const std::shared_ptr<CNode> & ptrLC = nullptr, const std::shared_ptr<CNode> & ptrRC = nullptr);
    CNode (const std::shared_ptr <T> & ptr);
    //destructor
    ~CNode () {}

    //getter / setter
    const T &GetData () const;
    const std::shared_ptr<CNode> & getLC() const;
    const std::shared_ptr<CNode> & getRC() const;

    void setLC(const std::shared_ptr<CNode> &LC);
    void setRC(const std::shared_ptr<CNode> &RC);
    void SetData (const T & val);

    void Show () const ;
    void add (const T & val);
};



template <typename T>
CNode<T>::CNode (const T & val, const std::shared_ptr<CNode> & leftChild,  const std::shared_ptr<CNode> & rightChild) :
    m_Data (val), m_LC (leftChild), m_RC (rightChild)
{
}

template<typename T>
void CNode<T>::setLC(const std::shared_ptr<CNode> &LC)
{
    m_LC = LC;
}

template<typename T>
void CNode<T>::setRC(const std::shared_ptr<CNode> &RC)
{
    m_RC = RC;
}

template<typename T>
const std::shared_ptr<CNode<T>> &CNode<T>::getRC() const
{
    return m_RC;
}

template<typename T>
const std::shared_ptr<CNode<T>> &CNode<T>::getLC() const
{
    return m_LC;
}

template<typename T>
const T &CNode<T>::GetData () const
{
    return m_Data;
}

#endif // NODE_HPP
