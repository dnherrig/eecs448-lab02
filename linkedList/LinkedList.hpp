/**
*	Dylan Herrig
*	 9-6-2017
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	if(m_front == nullptr)//check for empty list
	{
	}
	else
	{
		
		while((temp -> getValue() != value))
		{
			if(temp -> getNext() != nullptr)//increment the list unless the end is reached
			{
			temp = temp -> getNext();
			}
			else
			{
				return(isFound);//if the end was reached without the value then return
			}
		}
		if(temp -> getValue() == value)//if the value is found change state to true
		{
			isFound = true;
		}
	}	

	return(isFound);
	
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = m_front;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if(isEmpty())
	{
	}
	else 
	{
		while((lastNode->getNext() != nullptr))// increment to the back of the list
		{
			secondintoLast = lastNode;//set the value of last node to second to last node before incrementing 
			lastNode = lastNode->getNext();
		}

		delete lastNode;//delete the back
		secondintoLast -> setNext(nullptr);//set the new back to look at nullptr
 
		m_size--;//increment the size
		isRemoved = true;


	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
