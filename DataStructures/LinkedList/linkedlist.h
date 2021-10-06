#include <stdlib.h>

template <typename T>
struct Node
{
	T Data;

	Node<T>* Head,
		*Next,
		*Previous;

	Node()
	{
	}

	Node(T data) : Data(data), Head(nullptr), Next(nullptr), Previous(nullptr)
	{
	}
	
	Node(T data, Node<T>* head) : Data(data), Head(head), Next(nullptr), Previous(nullptr)
	{
	}

	Node(T data, Node<T>* head, Node<T>* next) : Data(data), Head(head), Next(next), Previous(nullptr)
	{
	}

	Node(T data, Node<T>* head, Node<T>* next, Node<T>* previous) : Data(data), Head(head), Next(next), Previous(previous)
	{
	}

	void operator =(T data)
	{
		this->Data = data;
	}

	~Node()
	{		
	}	
};

template<typename T>
class LinkedList
{
private:
	void Delete()	//	Deletes the current linked list instance
	{
		Node<T>* current = this->Head
				,*next;

		while (current != nullptr)
		{
			next = current->Next;

			delete current;
			
			current = next;
		}	
	}

	void Delete(Node<T>* node)	//	Deletes and swaps the provided node.
	{
		if (node)
		{
			this->Delete(node->Next);
			delete node;
		}
	}

	Node<T>* Traverse()	//	Traverses the list from the head node.
	{	
		return this->Traverse(this->Head);
	}

	Node<T>* Traverse(Node<T>* node)	//	Traverses the list from the provided node.
	{
		if (node->Next == nullptr)
			return node;
		
		return this->Traverse(node->Next);	
	}

	Node<T>* Traverse(Node<T>* node, int start, int end)	//	Traverses the linkedlist starting from the provied index to the provided end index.
	{
		if (start < end)
			return this->Traverse(node->Next, ++start, end);
		
		return node;
	}

	void Copy(Node<T>* node, Node<T>* prev)	//	Copies the provied linked list instance to the current.
	{
		if (node)
		{
			prev->Next = new Node<T>(node->Data, this->Head, nullptr, prev);

			this->Copy(node->Next, prev->Next);

			this->Size++;
		}
	}

public:
	Node<T>* Head,	//	Head node.	
			*Tail;	//	Tail node.

	unsigned int Size { 0 };
	
	Node<T>* GetFrontNode()	//	Returns the first/head node of the list.
	{
		return this->Head;
	}
		
	Node<T>* GetBackNode()	//	Returns the last node in the list.
	{
		return this->Traverse();
	}	

	Node<T>* GetMidNode()	//	Returns the mid node of the list.
	{
		return this->GetNode((this->Size - 1) / 2);
	}

	Node<T>* GetNode(int index)	//	Returns the node at the provided index in list.
	{
		if (index > (this->Size - 1) || index <  0)	//	Range check. 
			return nullptr;
		

		Node<T>* node = this->Head;

		node = this->Traverse(node, 0, index);

		return node;
	}
   	
	Node<T>* AddNode(T data)	//	Adds a new node with the provided data to the current linked list instance.
	{
		Node<T>* node = this->Traverse();

		node->Next = new Node<T>(data, this->Head, nullptr, node);	

		this->Tail = node->Next;

		this->Size++;
			
		return node->Next;	
	}

	Node<T>* AddNode(Node<T>* node)	//	Adds the provided node to the current linked list instance.
	{
		Node<T>* temp; 	//	temp node
		
		if (node == nullptr)	//	null check
			return node; 
	
		(temp = this->Traverse())->Next = node;

		node->Previous = temp;
	
		this->Size++;
		
		return node;		
	}

	void DeleteNode(unsigned int index)	//	Deletes the node at the provided index
	{
		Node<T>* node;

		if ((node = this->GetNode(index)) == nullptr)
			return;

		if (node->Previous != nullptr && node->Next != nullptr)
		{	
			node->Previous->Next = node->Next; 
			node->Next->Previous = node->Previous;
		}

		delete node;
	}

	void SetNodeData(T data, int index)	//	Sets the data of the node at provided index as the provided data
	{
		Node<T>* node;

		if ((node = this->GetNode(index)) == nullptr)	
			return;

		node->Data = data;
	}
		
	Node<T>* operator [](unsigned int index)
	{
		return this->GetNode(index);
	}
	
	LinkedList() : Head(nullptr), Tail(nullptr)
	{
	}
	
	LinkedList(Node<T>* node) : Head(node), Tail(this->Head->Next)
	{
		this->Size++; 
	}
	
	LinkedList(const LinkedList<T>& linkedList)	
	{
		this->Head = new Node<T>(linkedList.Head->Data);

		this->Copy(linkedList.Head->Next, this->Head);
	}

	~LinkedList()
	{
		this->Delete(this->Head);
	}
};
